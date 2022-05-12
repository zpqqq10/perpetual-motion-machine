#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <vector>
#include <iostream>
#include <memory>
#include "utils.h"
#include "main.h"
using namespace std;


/*** value ***/
class VoidAST : public BaseAST
{
public:
    VoidAST() {}

    void Print()
    {
        cout << "VOID" << endl;
    }

    virtual llvm::Value *CodeGen();
};

class IntegerAST : public BaseAST
{
    int value;

public:
    IntegerAST(int v) : value(v) {}

    int getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "IntegerLiteral " << " " << CYAN << value << White << endl;
        return;
    }

    virtual llvm::Value *CodeGen();
};

class FloatAST : public BaseAST
{
    float value;

public:
    FloatAST(float v) : value(v) {}

    float getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "FloatLiteral " << " " << CYAN << value << White << endl;
        return;
    }

    virtual llvm::Value *CodeGen();
};

class BoolAST : public BaseAST
{
    bool value;

public:
    BoolAST(bool v) : value(v) {}

    bool getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "BoolLiteral " << " " << CYAN << (value ? "true" : "false") << White << endl;
        return;
    }

    virtual llvm::Value *CodeGen();
};


class StringAST : public BaseAST
{
    string value;

public:
    StringAST(string v): value(v) {}

    string &getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "StringLiteral " << " " << CYAN << value << White << endl;
        return;
    }

    virtual llvm::Value *CodeGen();
};


// for binary operator
class BinaryOpAST : public BaseAST
{
    uint16_t type;

public:
    BinaryOpAST(uint16_t t) : type(t) {}

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "BinaryOperator " << " " << CYAN << get_op_name(type) << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

// for unary operator
class UnaryOpAST : public BaseAST
{
    uint16_t type;

public:
    UnaryOpAST(uint16_t t) : type(t) {}

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "UnaryOperator " << " " << CYAN << get_op_name(type) << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

/*** Variable ***/
class RefAST : public BaseAST
{
    string identifier;
    int type;

public:
    RefAST(string id, int type) : identifier(id),type(type) {}

    string &getId()
    {
        return this->identifier;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "DeclRefExpr " << RED << get_ref_name(type) << " " << CYAN << identifier << White  << endl;
    }

    virtual llvm::Value *CodeGen();
};

class ArraySubscriptExpr : public BaseAST
{
public:
    ArraySubscriptExpr(){;}
    ~ArraySubscriptExpr(){;}
    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "ArraySubscriptExpr" << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};
// call expr
class CallExpr : public BaseAST
{
private:
    /* data */
public:
    CallExpr() { ; }
    ~CallExpr() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << PURPLE << "CallExpr " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    virtual llvm::Value *CodeGen();
};



// args expr
class ArgsList : public BaseAST
{
private:
    /* data */
public:
    vector<BaseAST *> args;
    ArgsList() { ; }
    ~ArgsList() { ; }
    void addvar(BaseAST *var)
    {
        args.push_back(var);
    }
    virtual void print(int level)
    {
        for (size_t i = 0; i < args.size(); i++)
        {
            args[i]->print(level);
        }
        return;
    }
    virtual llvm::Value *CodeGen();
};

#endif