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
        cout << _PURPLE << "IntegerLiteral "
             << " " << _CYAN << value << White << endl;
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
        cout << _PURPLE << "FloatLiteral "
             << " " << _CYAN << value << White << endl;
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
        cout << _PURPLE << "BoolLiteral "
             << " " << _CYAN << (value ? "true" : "false") << White << endl;
        return;
    }

    virtual llvm::Value *CodeGen();
};

class StringAST : public BaseAST
{
    string value;

public:
    StringAST(string v)
    {
        value = v.substr(1, v.length() - 2);
    }

    string &getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "StringLiteral "
             << " " << _CYAN << value << White << endl;
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
        cout << _PURPLE << "BinaryOperator "
             << " " << _CYAN << get_op_name(type) << White << endl;
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
        cout << _PURPLE << "UnaryOperator "
             << " " << _CYAN << get_op_name(type) << White << endl;
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


public:
    bool isStore;
    string identifier;
    int type;
    RefAST(string id, int type) : identifier(id), type(type) {}

    string &getId()
    {
        return this->identifier;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "DeclRefExpr " << _RED << get_ref_name(type) << " " << _CYAN << identifier << White << endl;
    }

    virtual llvm::Value *CodeGen();
};

class ArraySubscriptExpr : public BaseAST
{
public:
    bool isStore;
    ArraySubscriptExpr() { ; }
    ~ArraySubscriptExpr() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "ArraySubscriptExpr" << White << endl;
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
        cout << _PURPLE << "CallExpr " << White << endl;
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