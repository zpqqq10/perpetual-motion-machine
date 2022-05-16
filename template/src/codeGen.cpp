#include "codeGen.h"

Value *Program::CodeGen()
{
    TheModule->setTargetTriple("x86_64-pc-linux-gnu");
    TheModule->setDataLayout("e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128");
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->CodeGen();
    }
    // std::cout << TheModule->getDataLayoutStr() << std::endl;
    // std::cout << TheModule->getTargetTriple() << std::endl;
    TheModule->print(errs(), nullptr);
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
    IRBuilder<> TmpB(&TheFunction->getEntryBlock(),
                     TheFunction->getEntryBlock().begin());

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

    // TODO: generate prototype
    // if (!TheFunction)
    //     ;

    if (!TheFunction->empty())
        return (Function *)LogErrorV("Function cannot be redefined.");

    // Create a new basic block to start insertion into.
    BasicBlock *BB = BasicBlock::Create(TheContext, funcname, TheFunction);
    Builder.SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    NamedValues.clear();

    for (auto &Arg : TheFunction->args())
    {

        NamedValues[std::string(Arg.getName())] = &Arg;
        AllocaInst *alloca = CreateEntryBlockAlloca(TheFunction, Arg.getName(), Arg.getType());
        Builder.CreateStore(&Arg, alloca);
    }

    children[1]->CodeGen();

    // Finish off the function.
    Builder.CreateRet(getInitialValue(rettype));
    // Validate the generated code, checking for consistency.
    verifyFunction(*TheFunction);

    return TheFunction;

    // Error reading body, remove function.
    // TheFunction->eraseFromParent();
    // return nullptr;
}

Function *ProtoAST::CodeGen()
{
    // Make the function type:  double(double,double) etc.
    // ? check for re-declaration?
    // TODO
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
        Arg.setName(argslist->parms[Idx]->name);

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
    bool fflag = false;
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
            debug("return float");
            fflag = true;
        }
        // if return float, make some necessary conversion
        if (fflag && type != OPASSIGN)
        {
            if (!L->getType()->isFloatTy())
            {
                L = Builder.CreateSIToFP(L, TypeGen(TYPEFLOAT));
            }
            if (!R->getType()->isFloatTy())
            {
                // if(R->getType()->isSingleValueType())
                R = Builder.CreateSIToFP(R, TypeGen(TYPEFLOAT));
                // else
                //     R = Builder.CreateUIToFP(R, TypeGen(TYPEFLOAT));
            }
        }
        switch (type)
        {
        case OPADD:
            return fflag
                       ? Builder.CreateFAdd(L, R, "addftmp")
                       : Builder.CreateAdd(L, R, "addtmp");
        case OPSUB:
            return fflag
                       ? Builder.CreateFSub(L, R, "subftmp")
                       : Builder.CreateSub(L, R, "subtmp");
        case OPMUL:
            return Builder.CreateMul(L, R, "multmp");
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
    return Builder.CreateNeg(children[0]->CodeGen());
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
    // TODO 检查下标为int
    Value *index = children[1]->CodeGen();
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
    // TODO
    size_t argssize = 0;
    // if (CalleeF->arg_size() != argssize)
    //     return LogErrorV("Incorrect # arguments passed");
    std::vector<Value *> ArgsV;
    // TODO 这部分应该可以放在ArgsList::CodeGen()
    // for (unsigned i = 0; i != argssize; ++i)
    // {
    //     ArgsV.push_back(Args[i]->codegen());
    //     if (!ArgsV.back())
    //         return nullptr;
    // }

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
    return nullptr;
}

Value *IterationStmtAST::CodeGen()
{
    return nullptr;
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
    else {
        if (TheFunction->getReturnType()->getTypeID())
        {
            // there is nothing to return but the function requires something to return
            return LogErrorV("Return value error!");
        }
        else {
            // return nothing
            Builder.CreateRet(nullptr);
        }
    }

    return nullptr;
}