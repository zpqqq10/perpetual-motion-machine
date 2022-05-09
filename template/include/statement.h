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

    virtual void print(int level){
        padding(level);
        cout << "STMT" << endl;
    }

    // virtual llvm::Value *CodeGen();
};

// compound statement
class CompoundAST : public BaseAST
{

public:
    CompoundAST() {}

    ~CompoundAST() {}

    virtual void print(int level){
        padding(level);
        cout << "compound" << endl;
    }
    // virtual llvm::Value *CodeGen();
};

// selection statement
class SelectionAST : public BaseAST
{

public:
    SelectionAST() {}

    ~SelectionAST() {}

    virtual void print(int level){
        padding(level);
        cout << "selection" << endl;
    }
    // virtual llvm::Value *CodeGen();
};

// iteration statement of while
class WhileAST : public BaseAST
{

public:
    WhileAST() {}

    ~WhileAST() {}

    virtual void print(int level){
        padding(level);
        cout << "while" << endl;
    }
    // virtual llvm::Value *CodeGen();
};

// return statement
class ReturnAST : public BaseAST
{

public:
    ReturnAST() {}

    ~ReturnAST() {}

    virtual void print(int level){
        padding(level);
        cout << "return" << endl;
    }
    // virtual llvm::Value *CodeGen();
};

// comment (may be of no use)
class CommentAST : public BaseAST
{

public:
    CommentAST() {}

    ~CommentAST() {}

    virtual void print(int level){
        padding(level);
        cout << "comment" << endl;
    }
    // virtual llvm::Value *CodeGen();
};

#endif