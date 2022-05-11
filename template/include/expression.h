#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <vector>
#include <iostream>
#include <memory>
#include "utils.h"
#include "main.h"
using namespace std;

/********************************* 这个还要改的 *****************************************/

/*** value ***/
class VoidAST : public BaseAST
{
public:
    VoidAST() {}

    void Print()
    {
        cout << "VOID" << endl;
    }

    // llvm::Value *CodeGen();
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
        cout << GREEN << "IntegerLiteral " << White << " " << value << endl;
        return;
    }

    // llvm::Value *CodeGen();
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
        cout << GREEN << "FloatLiteral " << White << " " << value << endl;
        return;
    }

    // llvm::Value *CodeGen();
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
        cout << GREEN << "BoolLiteral " << White << " " << (value ? "true" : "false") << endl;

        return;
    }

    // llvm::Value *CodeGen();
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
        cout << GREEN << "BinaryOperator " << White << " " << get_op_name(type) << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    // llvm::Value *CodeGen();
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
        cout << GREEN << "UnaryOperator " << White << " " << get_op_name(type) << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    // llvm::Value *CodeGen();
};


class CompoundStmtAST : public BaseAST
{

public:
    CompoundStmtAST() {}

    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "CompoundStmt" << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    // llvm::Value *CodeGen();
};

class StringAST : public BaseAST
{
    string value;

public:
    StringAST() {}

    string &getValue()
    {
        return this->value;
    }

    void Print()
    {
        ;
    }

    // llvm::Value *CodeGen();
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
        cout << GREEN << "DeclRefExpr " << RED << get_ref_name(type) << White << " " << identifier << endl;
    }

    // llvm::Value *CodeGen();
};

class ArraySubscriptExpr : public BaseAST
{
public:
    ArraySubscriptExpr(){;}
    ~ArraySubscriptExpr(){;}
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "ArraySubscriptExpr" << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
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
        cout << GREEN << "CallExpr " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
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
    // virtual llvm::Value *CodeGen();
};

// /*** array element ***/
// class ArrEExpr: public Expr {
//     Identifier array;
//     exprPtr index;
// public:
//     ArrEExpr(string &arr, Expr* ind): array(arr), index(ind){
//         this->setExprType(EXPRARRAY);
//     }

//     ArrEExpr(string &arr): array(arr){
//         this->index = nullptr;
//         this->setExprType(EXPRARRAY);
//     }

//     string &getId(){
//         return array.getId();
//     }

//     Expr* getIndex(){
//         if(index)
//             return index.get();
//         return nullptr;
//     }

//     void Print() {
//         cout << "array: " << array.getId() << '[' << index << ']' << endl;
//     }

//     llvm::Value* CodeGen();
// };

// /*** function call ***/
// class Call : public Expr {
//     idPtr func;
//     vector<exprPtr> params;
// public:
//     Call(Expr *funcName, ExprList *params) {
//         Identifier *p = static_cast<Identifier *>(funcName);
//         this->func = idPtr(p);

//         for (size_t i = 0, e = params->exprList.size(); i < e; i++) {
//             this->params.push_back(exprPtr(params->exprList[i]));
//         }
//         this->setExprType(EXPRCALL);
//     }

//     void Print() {
//         func->Print();
//         cout << "(";
//         for (size_t i = 0; i < params.size(); i++) {
//             params[i]->Print();
//         }
//         cout << ")" << endl;
//     }

//     llvm::Value *CodeGen();
// };

#endif