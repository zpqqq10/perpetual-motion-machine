#ifndef __DECLARATION_H
#define __DECLARATION_H

#include <iostream>
#include "utils.h"

// variable declaration
class VarDeclAST: public BaseAST
{
private:
    /* data */
public:
    VarDeclAST(/* args */);
    ~VarDeclAST();
    virtual llvm::Value *CodeGen();
};

// prototype declaration
class ProtoAST: public BaseAST
{
private:
    /* data */
public:
    ProtoAST(/* args */);
    ~ProtoAST();
    virtual llvm::Value *CodeGen();
};

// function definition
class FuncAST: public BaseAST
{
private:
    /* data */
public:
    FuncAST(/* args */);
    ~FuncAST();
    virtual llvm::Value *CodeGen();
};

#endif