#ifndef __STATEMENT_H
#define __STATEMENT_H

#include <vector>
#include <iostream>
#include <memory>
#include "utils.h"

using namespace std;

// parent object
class StmtAST : public BaseAST
{
    int stmtType;

public:
    StmtAST()
    {
        this->stmtType = STMTDEFAULT;
    }

    ~StmtAST() {}

    void setStmtType(int type)
    {
        this->stmtType = type;
    }

    int getStmtType()
    {
        return this->stmtType;
    }

    virtual void Print()
    {
        cout << "STMT" << endl;
    }

    virtual llvm::Value *CodeGen();
};

// expression
class ExprAST : public StmtAST
{
    int exprType;

public:
    int valueType;
    // ? a member for return value

    ExprAST()
    {
        this->valueType = VALUEDEFAULT;
        this->exprType = EXPRDEFAULT;
        this->setStmtType(STMTEXPRESSION);
    }

    ~ExprAST() {}

    void setExprType(int type)
    {
        this->exprType = type;
    }

    int getExprType()
    {
        return this->exprType;
    }

    void setValueType(int type)
    {
        this->valueType = type;
    }

    virtual int getValueType()
    {
        return this->valueType;
    }

    virtual void Print()
    {
        cout << "EXPR" << endl;
    }

    virtual llvm::Value *CodeGen();
};

// compound statement
class CompoundAST : public StmtAST
{

public:

    CompoundAST()
    {
    }

    ~CompoundAST() {}
    virtual llvm::Value *CodeGen();
};

// selection statement
class SelectionAST : public StmtAST
{

public:

    SelectionAST()
    {
    }

    ~SelectionAST() {}
    virtual llvm::Value *CodeGen();
};

// iteration statement of while
class WhileAST : public StmtAST
{

public:

    WhileAST()
    {
    }

    ~WhileAST() {}
    virtual llvm::Value *CodeGen();
};

// return statement
class ReturnAST : public StmtAST
{

public:

    ReturnAST()
    {
    }

    ~ReturnAST() {}
    virtual llvm::Value *CodeGen();
};

// comment
class CommentAST : public StmtAST
{

public:

    CommentAST()
    {
    }

    ~CommentAST() {}
    virtual llvm::Value *CodeGen();
};

#endif