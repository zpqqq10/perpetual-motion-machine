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

/************************ declaration ************************/
Value *VarDeclAST::CodeGen()
{
    return nullptr;
}

Value *VarDeclList::CodeGen()
{
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
    BasicBlock *BB = BasicBlock::Create(TheContext, "entry", TheFunction);
    Builder.SetInsertPoint(BB);

    // Record the function arguments in the NamedValues map.
    // TODO: 确认下这一步有没有问题
    NamedValues.clear();
    for (auto &Arg : TheFunction->args())
        NamedValues[std::string(Arg.getName())] = &Arg;

    // TODO: generate body
    // if (Value *RetVal = children[body]->codegen())
    // {
    // Finish off the function.
    //     Builder.CreateRet(RetVal);

    // Validate the generated code, checking for consistency.
    //     verifyFunction(*TheFunction);

    //     return TheFunction;
    // }

    // Error reading body, remove function.
    // TheFunction->eraseFromParent();
    return nullptr;
}

Function *ProtoAST::CodeGen()
{
    // Make the function type:  double(double,double) etc.
    // ? check for re-declaration?
    // TODO
    size_t argssize = 0;
    std::vector<Type *> Doubles(argssize, Type::getDoubleTy(TheContext));
    FunctionType *FT =
        FunctionType::get(Type::getDoubleTy(TheContext), Doubles, false);

    Function *F =
        Function::Create(FT, Function::ExternalLinkage, funcname, TheModule.get());

    // Set names for all arguments.
    // unsigned Idx = 0;
    // for (auto &Arg : F->args())
    //     Arg.setName(Args[Idx++]);

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
    return nullptr;
}

Value *BinaryOpAST::CodeGen()
{
    // TODO
    // Value *L = children[0]->codegen();
    // Value *R = children[1]->codegen();
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
    return nullptr;
}