#ifndef __STATEMENT_H
#define __STATEMENT_H

#include <vector>
#include <iostream>
#include <memory>
#include "llvm/IR/Value.h"
#include "utils.h"

using namespace std;

// compound statement
class CompoundStmtAST : public BaseAST
{

public:
    CompoundStmtAST() {}
    vector<pair<string, llvm::Value*>> OldBindings;
    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "CompoundStmt" << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

// selection stmt
class SelectionStmtAST : public BaseAST
{
private:
    /* data */
public:
    SelectionStmtAST() { ; }
    ~SelectionStmtAST() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "IfStmt " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    virtual llvm::Value *CodeGen();
};

// iteration stmt
class IterationStmtAST : public BaseAST
{
private:
    /* data */
public:
    IterationStmtAST() { ; }
    ~IterationStmtAST() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "WhileStmt " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    virtual llvm::Value *CodeGen();
};

// return stmt
class ReturnStmtAST : public BaseAST
{
private:
    /* data */
public:
    ReturnStmtAST() { ; }
    ~ReturnStmtAST() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "ReturnStmt " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    virtual llvm::Value *CodeGen();
};

// comment (may be of no use)
class CommentAST : public BaseAST
{

public:
    CommentAST() {}

    ~CommentAST() {}

    virtual void print(int level)
    {
        padding(level);
        cout << "comment" << endl;
    }
    // virtual llvm::Value *CodeGen();
};

#endif