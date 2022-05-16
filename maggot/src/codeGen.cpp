#include "codeGen.h"
#include <fstream>
#include <sstream>

Value *Program::CodeGen()
{
    error_code errorcode;
    TheModule->setTargetTriple("x86_64-pc-linux-gnu");
    TheModule->setDataLayout("e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128");
    TheModule->setSourceFileName(file_input);
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->CodeGen();
    }
    if (option_show_ir)
        TheModule->print(errs(), nullptr);
    else
    {
        raw_fd_ostream file(file_output, errorcode);
        TheModule->print(file, nullptr);
    }
    return nullptr;
}

/************************ tools ************************/

std::unique_ptr<BaseAST> LogError(const char *Str)
{
    fprintf(stderr, "Error: %s\n", Str);
    return nullptr;
}

Value *LogErrorV(const char *Str)
{
    LogError(Str);
    return nullptr;
}

static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction, StringRef VarName, Type *type)
{
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(), TheFunction->getEntryBlock().begin());

    return TmpB.CreateAlloca(type, nullptr, VarName);
}

Type *TypeGen(int type)
{
    switch (type)
    {
    case TYPEINT:
        return Type::getInt32Ty(TheContext);
    case TYPEINTARRAY:
        return Type::getInt32Ty(TheContext);
    case TYPEFLOAT:
        return Type::getFloatTy(TheContext);
    case TYPEFLOATARRAY:
        return Type::getFloatTy(TheContext);
    case TYPEBOOL:
        return Type::getInt1Ty(TheContext);
    case TYPEVOID:
        return Type::getVoidTy(TheContext);
    case TYPECHAR:
        return Type::getInt8Ty(TheContext);
    default:
        return Type::getInt32Ty(TheContext);
    }
}

ArrayType *TypeGen(int type, int size)
{
    switch (type)
    {
    case TYPEINTARRAY:
        return ArrayType::get(TypeGen(type), size);
    case TYPEFLOATARRAY:
        return ArrayType::get(TypeGen(type), size);
    default:
        return ArrayType::get(TypeGen(TYPEINT), size);
    }
}

Value *getInitialValue(int type)
{
    switch (type)
    {
    case TYPEINTARRAY:
        return ConstantAggregateZero::get(TypeGen(TYPEINT));
    case TYPEFLOAT:
        return ConstantFP::get(TheContext, APFloat(0.0));
    case TYPEFLOATARRAY:
        return ConstantAggregateZero::get(TypeGen(TYPEFLOAT));
    case TYPEBOOL:
        return ConstantInt::get(TheContext, APInt(1, 0, false));
    case TYPEVOID:
        return nullptr;
    case TYPECHAR:
        return ConstantInt::get(TheContext, APInt(8, 0, true));
    case TYPEINT:
    default:
        return ConstantInt::get(TheContext, APInt(32, 0, true));
    }
}

/************************ declaration ************************/

Value *VarDeclAST::CodeGen()
{
    return nullptr;
}

Value *VarDeclList::CodeGen()
{
    if (isGlobal)
    {
        for (int i = 0; i < vars.size(); i++)
        {
            VarDeclAST *var = vars[i];
            Value *InitVal;
            // InitVal = ConstantFP::get(TheContext, APFloat(0.0));
            if (var->children.size())
            {
                InitVal = var->children[0]->CodeGen();
            }
            else
            {
                InitVal = getInitialValue(var->type);
            }
            // maintain global variable
            TheModule->getOrInsertGlobal(var->name, var->length == -1 ? TypeGen(var->type) : TypeGen(var->type, var->length));
            GlobalVariable *gVar = TheModule->getNamedGlobal(var->name);
            // gVar->setAlignment(MaybeAlign(4));
            gVar->setInitializer(static_cast<Constant *>(InitVal));
        }
    }
    else
    {

        CompoundStmtAST *current = compoundstack.back();
        Function *TheFunction = Builder.GetInsertBlock()->getParent();
        for (int i = 0; i < vars.size(); i++)
        {
            VarDeclAST *var = vars[i];
            Value *InitVal;

            if (var->children.size())
            {
                InitVal = var->children[0]->CodeGen();
            }
            else
            {
                InitVal = getInitialValue(var->type);
            }
            AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var->name, var->length == -1 ? TypeGen(var->type) : TypeGen(var->type, var->length));
            Builder.CreateStore(InitVal, Alloca);
            current->OldBindings.push_back(make_pair(var->name, NamedValues[var->name]));
            NamedValues[var->name] = Alloca;
        }
    }
    return nullptr;
}

Value *ParmVarDeclAST::CodeGen()
{
    return nullptr;
}

Value *ParmVarDeclList::CodeGen()
{
    return nullptr;
}

Function *FuncAST::CodeGen()
{
    // First, check for an existing function from a previous 'extern' declaration.
    Function *TheFunction = TheModule->getFunction(funcname);

    if (!TheFunction)
    {
        ParmVarDeclList *argslist = dynamic_cast<ParmVarDeclList *>(children[0]);
        size_t argssize = argslist->parms.size();

        std::vector<Type *> args;
        for (int i = 0; i < argssize; i++)
        {
            args.push_back(TypeGen(argslist->parms[i]->type));
        }
        FunctionType *FT =
            FunctionType::get(TypeGen(rettype), args, false);

        Function *F =
            Function::Create(FT, Function::ExternalLinkage, funcname, TheModule.get());

        // Set names for all arguments.
        unsigned Idx = 0;
        for (auto &Arg : F->args())
        {
            Arg.setName(argslist->parms[Idx]->name);
            Idx++;
        }

        TheFunction = TheModule->getFunction(funcname);
    }

    if (!TheFunction->empty())
        return (Function *)LogErrorV("Function cannot be redefined.");

    // Create a new basic block to start insertion into.
    BasicBlock *BB = BasicBlock::Create(TheContext, funcname, TheFunction);
    Builder.SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();
    ParmVarDeclList *argslist = dynamic_cast<ParmVarDeclList *>(children[0]);
    unsigned Idx = 0;
    for (auto &Arg : TheFunction->args())
    {
        AllocaInst *alloca = CreateEntryBlockAlloca(TheFunction, Arg.getName(), Arg.getType());
        NamedValues[argslist->parms[Idx]->name] = alloca;
        Builder.CreateStore(&Arg, alloca);
        Idx++;
    }

    children[1]->CodeGen();

    // Finish off the function.
    Builder.CreateRet(getInitialValue(rettype));
    // Validate the generated code, checking for consistency.
    verifyFunction(*TheFunction);

    return TheFunction;
}

Function *ProtoAST::CodeGen()
{
    // Make the function type:  double(double,double) etc.
    // ? check for re-declaration?
    ParmVarDeclList *argslist = dynamic_cast<ParmVarDeclList *>(children[0]);
    size_t argssize = argslist->parms.size();

    std::vector<Type *> args;
    for (int i = 0; i < argssize; i++)
    {
        args.push_back(TypeGen(argslist->parms[i]->type));
    }
    FunctionType *FT =
        FunctionType::get(TypeGen(rettype), args, false);

    Function *F =
        Function::Create(FT, Function::ExternalLinkage, funcname, TheModule.get());

    // Set names for all arguments.
    unsigned Idx = 0;
    for (auto &Arg : F->args())
    {
        Arg.setName(argslist->parms[Idx]->name);
        Idx++;
    }

    return F;
}

/************************ expression ************************/
Value *VoidAST::CodeGen()
{
    return ConstantPointerNull::getNullValue(TypeGen(TYPEINT));
}

Value *IntegerAST::CodeGen()
{
    return ConstantInt::get(TheContext, APInt(32, value, true));
}

Value *FloatAST::CodeGen()
{
    // a floating number
    return ConstantFP::get(TheContext, APFloat(value));
}

Value *BoolAST::CodeGen()
{
    return ConstantInt::get(TheContext, APInt(1, value, false));
}

Value *StringAST::CodeGen()
{
    return nullptr;
}

Value *BinaryOpAST::CodeGen()
{
    // flag indicating whether the return type is float
    bool fflag = false, conversion = false;
    if (type == OPASSIGN)
    {
        if (!dynamic_cast<RefAST *>(children[0]) && !dynamic_cast<ArraySubscriptExpr *>(children[0]))
            return LogErrorV("Destination of assignment must be assignable!");
        if (dynamic_cast<ArraySubscriptExpr *>(children[0]))
        {
            dynamic_cast<ArraySubscriptExpr *>(children[0])->isStore = true;
        }
        if (dynamic_cast<RefAST *>(children[0]))
        {
            dynamic_cast<RefAST *>(children[0])->isStore = true;
        }
    }

    Value *L = children[0]->CodeGen();
    Value *R = children[1]->CodeGen();
    if (!L || !R)
        return LogErrorV("Expression Error!");

    if (((L->getType()->isFloatTy() || L->getType()->isIntegerTy()) && (R->getType()->isFloatTy() || R->getType()->isIntegerTy())) || (type == OPASSIGN && L->getType()->isPointerTy()))
    {
        // can be compared of computed;
        if (type != OPASSIGN && (L->getType()->isFloatTy() || R->getType()->isFloatTy()))
        {
            fflag = true;
        }
        // if return float, make some necessary conversion
        if (fflag && type != OPASSIGN)
        {
            if (!L->getType()->isFloatTy())
            {
                conversion = true;
                L = Builder.CreateSIToFP(L, TypeGen(TYPEFLOAT));
            }
            if (!R->getType()->isFloatTy())
            {
                // if(R->getType()->isSingleValueType())
                conversion = true;
                R = Builder.CreateSIToFP(R, TypeGen(TYPEFLOAT));
                // else
                //     R = Builder.CreateUIToFP(R, TypeGen(TYPEFLOAT));
            }
        }
        switch (type)
        {
        case OPADD:
            return conversion
                       ? fflag ? Builder.CreateFAdd(L, R, "addftmp") : Builder.CreateAdd(L, R, "addtmp")
                       : Builder.CreateNSWAdd(L, R, "addtmp");
        case OPSUB:
            return conversion
                       ? fflag ? Builder.CreateFSub(L, R, "subftmp") : Builder.CreateSub(L, R, "subtmp")
                       : Builder.CreateNSWSub(L, R, "subtmp");
        case OPMUL:
            return conversion
                       ? fflag ? Builder.CreateFMul(L, R, "mulftmp") : Builder.CreateMul(L, R, "multmp")
                       : Builder.CreateNSWMul(L, R, "multmp");
        case OPDIV:
            return fflag
                       ? Builder.CreateFDiv(L, R, "divftmp")
                       : Builder.CreateSDiv(L, R, "divstmp");
        case OPLT:
            return fflag
                       ? Builder.CreateFCmpOLT(L, R, "cmpftmp")
                       : Builder.CreateICmpSLT(L, R, "cmplt");
        case OPGT:
            return fflag
                       ? Builder.CreateFCmpOGT(L, R, "cmpftmp")
                       : Builder.CreateICmpSGT(L, R, "cmptmp");
        case OPLE:
            return fflag
                       ? Builder.CreateFCmpOLE(L, R, "cmpftmp")
                       : Builder.CreateICmpSLE(L, R, "cmptmp");
        case OPGE:
            return fflag
                       ? Builder.CreateFCmpOGE(L, R, "cmpftmp")
                       : Builder.CreateICmpSGE(L, R, "cmptmp");
        case OPEQ:
            return fflag
                       ? Builder.CreateFCmpOEQ(L, R, "cmpftmp")
                       : Builder.CreateICmpEQ(L, R, "cmptmp");
        case OPNEQ:
            return fflag
                       ? Builder.CreateFCmpONE(L, R, "cmpftmp")
                       : Builder.CreateICmpNE(L, R, "cmptmp");
        case OPASSIGN:
            // convert right operand
            if (L->getType()->getPointerElementType()->isFloatTy() && R->getType()->isIntegerTy())
            {
                R = Builder.CreateSIToFP(R, TypeGen(TYPEFLOAT));
            }
            else if (L->getType()->getPointerElementType()->isIntegerTy() && R->getType()->isFloatTy())
            {
                R = Builder.CreateFPToSI(R, TypeGen(TYPEINT));
            }
            return Builder.CreateStore(R, L);
        default:
            return LogErrorV("invalid binary operator");
            // case OPAND:
            //     return Builder.CreateAnd(L, R, "andtmp");
            // case OPOR:
            //     return Builder.CreateOr(L, R, "ortmp");
        }
    }
    else
    {
        return LogErrorV("Type cannot be operated");
    }
    return nullptr;
}

Value *UnaryOpAST::CodeGen()
{
    return Builder.CreateNSWNeg(children[0]->CodeGen());
    // return nullptr;
}

Value *RefAST::CodeGen()
{
    // Look this variable up in the function.
    Value *V = NamedValues[identifier];
    if (!V)
    {
        GlobalVariable *gVar = TheModule->getNamedGlobal(identifier);
        if (!gVar)
            return LogErrorV("undefined variable");
        else
        {
            if (gVar->getType()->getPointerElementType()->isArrayTy() || isStore)
            {
                return gVar;
            }
            else
                return Builder.CreateLoad(gVar->getType()->getPointerElementType(), gVar, identifier.c_str());
        }
    }
    Value *addr = V;

    if (V->getType()->getPointerElementType()->isArrayTy() || isStore)
    {
        addr = V;
    }
    else
    {
        addr = Builder.CreateLoad(V->getType()->getPointerElementType(), V, identifier.c_str());
    }

    return addr;
}

Value *ArraySubscriptExpr::CodeGen()
{
    Value *arrVal = children[0]->CodeGen();
    std::vector<Value *> indices;
    Value *index = children[1]->CodeGen();
    if (!index->getType()->isIntegerTy())
    {
        return LogErrorV("Index must be integer!");
    }
    indices.push_back(getInitialValue(TYPEINT));
    indices.push_back(index);
    Value *elePtr = Builder.CreateInBoundsGEP(arrVal, indices);
    if (isStore)
        return elePtr;
    else
        return Builder.CreateLoad(arrVal->getType()->getPointerElementType()->getArrayElementType(), elePtr);
}

Value *CallExpr::CodeGen()
{
    // Look up the name in the global module table.
    Function *CalleeF = TheModule->getFunction(dynamic_cast<RefAST *>(children[0])->getId());
    if (!CalleeF)
        return LogErrorV("Unknown function referenced");

    // If argument mismatch error.

    if (CalleeF->arg_size() != 0 &&
        (children.size() < 2 || ((dynamic_cast<ArgsList *>(children[1])->args.size()) != (CalleeF->arg_size()))))
        return LogErrorV("Incorrect # arguments passed");

    size_t argssize = CalleeF->arg_size();
    std::vector<Value *> ArgsV;
    for (unsigned i = 0; i != argssize; ++i)
    {
        ArgsV.push_back(dynamic_cast<ArgsList *>(children[1])->args[i]->CodeGen());
        if (!ArgsV.back())
            return nullptr;
    }

    return Builder.CreateCall(CalleeF, ArgsV, "calltmp");
}

Value *ArgsList::CodeGen()
{
    return nullptr;
}

/************************ statements ************************/
Value *CompoundStmtAST::CodeGen()
{
    // Value *ret = nullptr;
    compoundstack.push_back(this);
    for (size_t i = 0; i < children.size(); i++)
    {

        children[i]->CodeGen();
    }
    for (auto &p : OldBindings)
    {
        NamedValues[p.first] = p.second;
    }
    compoundstack.pop_back();
    return nullptr;
}

Value *SelectionStmtAST::CodeGen()
{
    Value *cond = children[0]->CodeGen();

    if (!cond)
    {
        return LogErrorV("Need condition expression in if statement.");
    }

    Function *atFunc = Builder.GetInsertBlock()->getParent();

    BasicBlock *thenBB = BasicBlock::Create(TheContext, "THEN", atFunc);
    BasicBlock *elseBB = BasicBlock::Create(TheContext, "ELSE");
    BasicBlock *contBB = BasicBlock::Create(TheContext, "IFCONT");



    Builder.CreateCondBr(cond, thenBB, elseBB);
    Builder.SetInsertPoint(thenBB);

    // then
    children[1]->CodeGen();
    Builder.CreateBr(contBB);

    thenBB = Builder.GetInsertBlock();
    atFunc->getBasicBlockList().push_back(elseBB);

    Builder.SetInsertPoint(elseBB);

    // else
    if (children.size() == 3)
    {
        children[2]->CodeGen();
    }

    Builder.CreateBr(contBB);

    elseBB = Builder.GetInsertBlock();
    atFunc->getBasicBlockList().push_back(contBB);

    Builder.SetInsertPoint(contBB);

    return nullptr;
}

Value *IterationStmtAST::CodeGen()
{
    Function *atFunc = Builder.GetInsertBlock()->getParent();

    BasicBlock *condBB = BasicBlock::Create(TheContext, "COND", atFunc);
    BasicBlock *loopBodyBB = BasicBlock::Create(TheContext, "LOOP", atFunc);
    BasicBlock *endBB = BasicBlock::Create(TheContext, "ENDLOOP", atFunc);
    // Init
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);

    Value *cond = children[0]->CodeGen();
    if (!cond)
    {
        return LogErrorV("Need condition expression in while loop.");
    }
    Builder.CreateCondBr(cond, loopBodyBB, endBB);

    // condBB = Builder.GetInsertBlock();
    // atFunc->getBasicBlockList().push_back(loopBodyBB);

    // loopBody
    Builder.SetInsertPoint(loopBodyBB);

    children[1]->CodeGen();
    Builder.CreateBr(condBB);

    // loopBodyBB = Builder.GetInsertBlock();
    // atFunc->getBasicBlockList().push_back(endBB);

    Builder.SetInsertPoint(endBB);
    

    return Constant::getNullValue(TypeGen(TYPEINT));
}

Value *ReturnStmtAST::CodeGen()
{
    Function *TheFunction = Builder.GetInsertBlock()->getParent();
    if (children.size())
    {
        if (TheFunction->getReturnType()->getTypeID() == Type::VoidTyID)
        {
            // there is a value to return but the function requires nothing to return
            return LogErrorV("Return value error!");
        }
        else
        {
            // there is a return type and there is a value to return
            Value *ret = children[0]->CodeGen();
            Builder.CreateRet(ret);
        }
    }
    else
    {
        if (TheFunction->getReturnType()->getTypeID())
        {
            // there is nothing to return but the function requires something to return
            return LogErrorV("Return value error!");
        }
        else
        {
            // return nothing
            Builder.CreateRet(nullptr);
        }
    }

    return nullptr;
}