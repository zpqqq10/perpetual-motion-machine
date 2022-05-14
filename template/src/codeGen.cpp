#include "codeGen.h"

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

static AllocaInst *CreateEntryBlockAlloca(Function *TheFunction,
                                          StringRef VarName,
                                          Type *type)
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
    case TYPEINTPTR:
        return Type::getInt32Ty(TheContext);
    case TYPEFLOAT:
        return Type::getDoubleTy(TheContext);
    case TYPEFLOATPTR:
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
    case TYPEINTPTR:
        return ArrayType::get(TypeGen(type), size);
    case TYPEFLOATPTR:
        return ArrayType::get(TypeGen(type), size);
    }
}

Value *getInitialValue(int type)
{
    switch (type)
    {
    case TYPEINTPTR:
        return  ConstantAggregateZero::get(TypeGen(TYPEINT));
    case TYPEFLOAT:
        return ConstantFP::get(TheContext, APFloat(0.0));
    case TYPEFLOATPTR:
        return ConstantAggregateZero::get(TypeGen(TYPEFLOAT));
    case TYPEBOOL:
        return ConstantInt::get(TheContext, APInt(1, 0, false));
    case TYPEVOID:
        return ConstantPointerNull::getNullValue(Type::getInt32Ty(TheContext));
    case TYPECHAR:
        return ConstantInt::get(TheContext, APInt(8, 0, true));
    case TYPEINT:
    default:
        return ConstantInt::get(TheContext, APInt(32, 0, true));
    }
}

/************************ declaration ************************/
Value *Program::CodeGen()
{
    for (size_t i = 0; i < children.size(); i++)
    {
        children[i]->CodeGen();
    }
    TheModule->print(errs(), nullptr);
    return nullptr;
}

Value *VarDeclAST::CodeGen()
{
    return nullptr;
}

Value *VarDeclList::CodeGen()
{
    if (dynamic_cast<VarDeclAST *>(vars[0])->isGlobal)
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
            TheModule->getOrInsertGlobal(var->name,var->length == -1 ? TypeGen(var->type) : TypeGen(var->type,var->length));
            GlobalVariable *gVar = TheModule->getNamedGlobal(var->name);
            // gVar->setAlignment(MaybeAlign(4));
            gVar->setInitializer(static_cast<Constant *>(InitVal));
        }
    }
    else
    {
        debug("local variable");
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
            AllocaInst *Alloca = CreateEntryBlockAlloca(TheFunction, var->name, var->length == -1 ? TypeGen(var->type) : TypeGen(var->type,var->length));
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
        debug("Begin args");
        NamedValues[std::string(Arg.getName())] = &Arg;
        AllocaInst *alloca = CreateEntryBlockAlloca(TheFunction, Arg.getName(), Arg.getType());
        Builder.CreateStore(&Arg, alloca);
    }

    children[1]->CodeGen();
    debug("Function Done");
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
    return nullptr;
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
    Value *x;
    return nullptr;
}

Value *BinaryOpAST::CodeGen()
{
    // TODO operator type check
    // Value *L = children[0]->CodeGen();
    // Value *R = children[1]->CodeGen();
    // if (!L || !R)
    //     return nullptr;

    // switch (type)
    // {
    // case OPASSIGN: // =
    //     return Builder.createFcmp();
    // case OPADD: // +
    //     return Builder.CreateFAdd(L, R, "addtmp");
    // case OPSUB: // -
    //     return Builder.CreateFSub(L, R, "subtmp");
    // case OPMUL: // *
    //     return Builder.CreateFMul(L, R, "multmp");
    // case OPDIV: // /
    //     return Builder.CreateFDiv(L, R, "divtmp");
    // case OPLE: // <=
    //     L = Builder.CreateFCmpULT(L, R, "cmptmp");
    //     // Convert bool 0/1 to double 0.0 or 1.0
    //     return nullptr;
    // case OPLT: // <
    //     L = Builder.CreateFCmpULT(L, R, "cmptmp");
    //     // Convert bool 0/1 to double 0.0 or 1.0
    //     return Builder.CreateUIToFP(L, Type::getDoubleTy(TheContext),
    //                                 "booltmp");
    // case OPGT: // >
    //     L = Builder.CreateFCmpULT(L, R, "cmptmp");
    //     // Convert bool 0/1 to double 0.0 or 1.0
    //     return nullptr;
    // case OPGE: // >=
    //     L = Builder.CreateFCmpULT(L, R, "cmptmp");
    //     // Convert bool 0/1 to double 0.0 or 1.0
    //     return nullptr;
    // case OPEQ: // ==
    //     L = Builder.CreateFCmpULT(L, R, "cmptmp");
    //     // Convert bool 0/1 to double 0.0 or 1.0
    //     return nullptr;
    // case OPNEQ: // !=
    //     L = Builder.CreateFCmpULT(L, R, "cmptmp");
    //     // Convert bool 0/1 to double 0.0 or 1.0
    //     return nullptr;
    // default:
    //     return LogErrorV("invalid binary operator");
    // }
    return nullptr;
}

Value *UnaryOpAST::CodeGen()
{
    return nullptr;
}

Value *RefAST::CodeGen()
{
    // Look this variable up in the function.
    Value *V = NamedValues[identifier];
    if (!V)
        LogErrorV("Unknown variable name");
    return V;
}

Value *ArraySubscriptExpr::CodeGen()
{
    return nullptr;
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
    debug("Begin Compound");
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
    debug("xsxssxsxsxs");
    Value *ret = ConstantInt::get(TheContext, APInt(32, 1234, true));
    Builder.CreateRet(ret);
    return nullptr;
}