#include "codeGen.h"
#include "declaration.h"
#include "expression.h"
#include "statement.h"

/************************ declaration ************************/
Value* VarDeclAST::CodeGen(){
    return nullptr;
}

Value* VarDeclList::CodeGen(){
    return nullptr;
}

Value* ParmVarDeclAST::CodeGen(){
    return nullptr;
}

Value* ParmVarDeclList::CodeGen(){
    return nullptr;
}

Value* FuncAST::CodeGen(){
    return nullptr;
}

Value* ProtoAST::CodeGen(){
    return nullptr;
}

/************************ expression ************************/
Value* VoidAST::CodeGen(){
    return nullptr;
}

Value* IntegerAST::CodeGen(){
    return nullptr;
}

Value* FloatAST::CodeGen(){
    return nullptr;
}

Value* BoolAST::CodeGen(){
    return nullptr;
}

Value* StringAST::CodeGen(){
    return nullptr;
}

Value* BinaryOpAST::CodeGen(){
    return nullptr;
}

Value* UnaryOpAST::CodeGen(){
    return nullptr;
}

Value* RefAST::CodeGen(){
    return nullptr;
}

Value* ArraySubscriptExpr::CodeGen(){
    return nullptr;
}

Value* CallExpr::CodeGen(){
    return nullptr;
}

Value* ArgsList::CodeGen(){
    return nullptr;
}

/************************ statements ************************/
Value* CompoundStmtAST::CodeGen(){
    return nullptr;
}

Value* SelectionStmtAST::CodeGen(){
    return nullptr;
}

Value* IterationStmtAST::CodeGen(){
    return nullptr;
}

Value* ReturnStmtAST::CodeGen(){
    return nullptr;
}