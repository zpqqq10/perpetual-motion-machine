#include "codeGen.h"
#include <fstream>
#include <sstream>

Value *Program::CodeGen()
{
    error_code errorcode;
    TheModule->setTargetTriple("x86_64-pc-linux-gnu");
    TheModule->setDataLayout("e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128");
    TheModule->setSourceFileName(file_input);
    // InitializeModuleAndPassManager

    // // Create a new pass manager attached to it.
    // TheFPM = std::make_unique<legacy::FunctionPassManager>(TheModule.get());

    // // Do simple "peephole" optimizations and bit-twiddling optzns.
    // TheFPM->add(createInstructionCombiningPass());
    // // Reassociate expressions.
    // TheFPM->add(createReassociatePass());
    // // Eliminate Common SubExpressions.
    // TheFPM->add(createGVNPass());
    // // Simplify the control flow graph (deleting unreachable blocks, etc).
    // TheFPM->add(createCFGSimplificationPass());

    // TheFPM->doInitialization();

    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->CodeGen();
        debug("%d",i);
    }
    if (option_show_ir)
        TheModule->print(errs(), nullptr);
    if (option_output_ir || option_output_bc || option_output_as || option_output_bin)
    {
        raw_fd_ostream file(option_output_ir ? file_output : "__temp.ll", errorcode);
        TheModule->print(file, nullptr);
    }
    if (option_output_bc || option_output_as || option_output_bin)
    {

        std::system((std::string("llvm-as __temp.ll -o ") + (option_output_bc ? file_output : std::string("__temp.bc"))).c_str());
        std::system("rm __temp.ll");
    }
    if (option_output_as || option_output_bin)
    {
        std::system((std::string("llc --march=x86-64 __temp.bc -o ") + (option_output_bc ? file_output : std::string("__temp.s"))).c_str());
        std::system("rm __temp.bc");
    }
    if (option_output_bin)
    {
        std::system((std::string("clang++ __temp.s ./lib/libstd.o -o ") + file_output).c_str());
        std::system("rm __temp.s");
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
    case TYPECHARARRAY:
        return Type::getInt8Ty(TheContext);
    case TYPEINTPTR:
        return Type::getInt32PtrTy(TheContext);
    case TYPECHARPTR:
        return Type::getInt8PtrTy(TheContext);
    case TYPEFLOATPTR:
        return Type::getFloatPtrTy(TheContext);
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
    case TYPECHARARRAY:
        return ArrayType::get(TypeGen(type), size);
    default:
        return ArrayType::get(TypeGen(TYPEINT), size);
    }
}

Type* IntGen(int bitwidth)
{
    switch (bitwidth)
    {
        case 1:
            return Type::getInt1Ty(TheContext);
        case 8:
            return Type::getInt8Ty(TheContext);
        case 32:
            return Type::getInt32Ty(TheContext);
        default:
            return Type::getInt32Ty(TheContext);
    }
}
Value *getInitialValue(int type)
{
    switch (type)
    {
    case TYPEINTARRAY:
        return ConstantAggregateZero::get(TypeGen(TYPEINT));
    case TYPEFLOAT:
        return ConstantFP::get(TheContext, APFloat((float)0.0));
    case TYPEFLOATARRAY:
        return ConstantAggregateZero::get(TypeGen(TYPEFLOAT));
    case TYPECHARARRAY:
        return ConstantAggregateZero::get(TypeGen(TYPECHAR));
    case TYPEBOOL:
        return ConstantInt::get(TheContext, APInt(1, 0, false));
    case TYPEVOID:
        return nullptr;
    case TYPECHAR:
        return ConstantInt::get(TheContext, APInt(8, 0, true));
    case TYPEINTPTR:
        return ConstantInt::get(TypeGen(type), APInt(32, 0, true));
    case TYPEFLOATPTR:
        return ConstantFP::get(TypeGen(type), APFloat((float)0.0));
    case TYPECHARPTR:
        return ConstantInt::get(TypeGen(type), APInt(8, 0, true));
    case TYPEINT:
    default:
        return ConstantInt::get(TheContext, APInt(32, 0, false));
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
            
            if (var->children.size())
            {
                if(var->length == -1)
                    InitVal = var->children[0]->CodeGen();
                else
                {
                    std::vector<llvm::Constant*> init;
                    int Idx = 0;
                    for(auto it:dynamic_cast<StringAST*>(var->children[0])->value)
                    {
                        init.push_back(Constant::getIntegerValue(TypeGen(TYPECHAR),APInt(8,it)));
                        Idx++;
                    }
                    for(;Idx < var->length;Idx++)
                    {
                        init.push_back(Constant::getIntegerValue(TypeGen(TYPECHAR),APInt(8,0)));
                    }
                    InitVal = ConstantArray::get(TypeGen(var->type, var->length),init);
                    // InitVal = dynamic_cast<StringAST*>(var->children[0])->value;
                }
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
            AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var->name, var->length == -1 ? TypeGen(var->type) : TypeGen(var->type, var->length));

            if (var->length == -1)
            {
                if (var->children.size())
                {
                    InitVal = var->children[0]->CodeGen();
                }
                else
                {
                    InitVal = getInitialValue(var->type);
                }
                Builder.CreateStore(InitVal, Alloca);
            }
            else
            {
                if (var->children.size())
                {
                    InitVal = var->children[0]->CodeGen();
                    std::vector<Value *> indices;
                    indices.push_back(ConstantInt::get(Type::getInt64Ty(TheContext),0));
                    indices.push_back(ConstantInt::get(Type::getInt64Ty(TheContext),0));
                    InitVal = Builder.CreateInBoundsGEP(InitVal, indices);
                    Builder.CreateMemCpy(Alloca,MaybeAlign(1),InitVal,MaybeAlign(1),var->length);
                }

            }
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
    debug("22222");
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
    // Builder.CreateRet(getInitialValue(rettype));
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
    return ConstantInt::get(TheContext, APInt(32, value, false));
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
    // debug("%s",value.c_str());
    return Builder.CreateGlobalString(value);
    // Builder.CreateGlobalString()
    // return nullptr;

}

Value *CharAST::CodeGen()
{
    return ConstantInt::get(TheContext, APInt(8, value, false));
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
        if((L->getType()->isIntegerTy() && R->getType()->isIntegerTy()))
        {
            if(L->getType()->getIntegerBitWidth() >  R->getType()->getIntegerBitWidth())
            {
                R = R->getType()->getIntegerBitWidth() == 1 ? Builder.CreateZExtOrBitCast(R, IntGen(L->getType()->getIntegerBitWidth())) :  Builder.CreateSExtOrBitCast(R, IntGen(L->getType()->getIntegerBitWidth()));
            }
            else if (L->getType()->getIntegerBitWidth() < R->getType()->getIntegerBitWidth())
            {
                    L = L->getType()->getIntegerBitWidth() == 1 ? Builder.CreateZExtOrBitCast(L, IntGen(R->getType()->getIntegerBitWidth())) :Builder.CreateSExtOrBitCast(L,IntGen(R->getType()->getIntegerBitWidth()));
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
            if( L->getType()->getPointerElementType()->isIntegerTy() && R->getType()->isIntegerTy() &&L->getType()->getPointerElementType()->getIntegerBitWidth() != R->getType()->getIntegerBitWidth())
            {
                R = R->getType()->getIntegerBitWidth() == 1 
                    ? Builder.CreateZExtOrTrunc(R, IntGen(L->getType()->getPointerElementType()->getIntegerBitWidth())) 
                    : Builder.CreateSExtOrTrunc(R, IntGen(L->getType()->getPointerElementType()->getIntegerBitWidth()));
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
    if (V->getType()->getPointerElementType()->isArrayTy() || isStore || V->getType()->getPointerElementType()->isPointerTy())
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
    if( arrVal->getType()->getPointerElementType()->isPointerTy())
    {
        arrVal = Builder.CreateLoad(arrVal->getType()->getPointerElementType(), arrVal);
        indices.push_back(index);
    }
    else
    {
        indices.push_back(ConstantInt::get(Type::getInt64Ty(TheContext),0));
        indices.push_back(index);
    }


    Value *elePtr = Builder.CreateInBoundsGEP(arrVal, indices);

    if (isStore)
        return elePtr;
    else
        // return Builder.CreateLoad(arrVal->getType()->getPointerElementType()->getArrayElementType(), elePtr);
        return Builder.CreateLoad(elePtr->getType()->getPointerElementType(), elePtr);
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
    // push arguments' value into vector
    for (unsigned i = 0; i != argssize; ++i)
    {
        Value* param = dynamic_cast<ArgsList *>(children[1])->args[i]->CodeGen();
        if(param->getType()->isPointerTy() && param->getType()->getPointerElementType()->isArrayTy())
        {
            std::vector<Value *> indices;
            indices.push_back(ConstantInt::get(Type::getInt64Ty(TheContext),0));
            indices.push_back(ConstantInt::get(Type::getInt64Ty(TheContext),0));
            param = Builder.CreateInBoundsGEP(param, indices);
        }
        ArgsV.push_back(param);
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
    // calculate condition value
    Value *cond = children[0]->CodeGen();

    if (!cond) // no condition codes, error
    {
        return LogErrorV("Need condition expression in if statement.");
    }

    Function *atFunc = Builder.GetInsertBlock()->getParent();
    BasicBlock *thenBB = BasicBlock::Create(TheContext, "THEN", atFunc);
    BasicBlock *elseBB = BasicBlock::Create(TheContext, "ELSE", atFunc);
    BasicBlock *contBB = BasicBlock::Create(TheContext, "IFCONT", atFunc);
    // conditionally branch
    Builder.CreateCondBr(cond, thenBB, elseBB);

    // then statements
    Builder.SetInsertPoint(thenBB);
    children[1]->CodeGen();
    // branch to continue part
    Builder.CreateBr(contBB);
    Builder.SetInsertPoint(contBB);

    // else generation
    Builder.SetInsertPoint(elseBB);

    // else statements
    if (children.size() == 3)
    {
        children[2]->CodeGen();
    }
    // branch to continue part
    Builder.CreateBr(contBB);
    // continue generation
    Builder.SetInsertPoint(contBB);

    return nullptr;
}

Value *IterationStmtAST::CodeGen()
{
    Function *atFunc = Builder.GetInsertBlock()->getParent();

    BasicBlock *condBB = BasicBlock::Create(TheContext, "COND", atFunc);
    BasicBlock *loopBodyBB = BasicBlock::Create(TheContext, "LOOP", atFunc);
    BasicBlock *endBB = BasicBlock::Create(TheContext, "ENDLOOP", atFunc);
    // Init generation
    Builder.CreateBr(condBB);
    Builder.SetInsertPoint(condBB);

    // calculate the condition value
    Value *cond = children[0]->CodeGen();
    if (!cond) // no condition codes, error
    {
        return LogErrorV("Need condition expression in while loop.");
    }
    // conditionally branch
    Builder.CreateCondBr(cond, loopBodyBB, endBB);

    // update basic block
    condBB = Builder.GetInsertBlock();

    // loopBody Generation
    Builder.SetInsertPoint(loopBodyBB);
    children[1]->CodeGen();
    // branch to condition part
    Builder.CreateBr(condBB);
    loopBodyBB = Builder.GetInsertBlock();

    // end part generation
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