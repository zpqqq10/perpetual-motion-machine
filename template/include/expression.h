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
    VoidAST()
    {
    }

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
    IntegerAST(int v) : value(v)
    {
    }

    int getValue()
    {
        return this->value;
    }


    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "IntegerLiteral " << White << " " << value;
        cout << endl;
        return;
    }

    // llvm::Value *CodeGen();
};

class FloatAST : public BaseAST
{
    float value;

public:
    FloatAST(float v) : value(v)
    {
    }

    float getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "FloatLiteral " << White << " " << value;
        cout << endl;
        return;
    }

    // llvm::Value *CodeGen();
};

class BoolAST : public BaseAST
{
    bool value;

public:
    BoolAST(bool v) : value(v)
    {
    }

    bool getValue()
    {
        return this->value;
    }

    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "BoolLiteral " << White << " " << (value ? "true" : "false");
        cout << endl;
        return;
    }

    // llvm::Value *CodeGen();
};

class BinaryOpAST : public BaseAST
{
    uint16_t type;
    
public:
    BinaryOpAST(uint16_t t) : type(t)
    {
    }



    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "BinaryOperator " << White << " "  ;
        cout << endl;
        return;
    }

    // llvm::Value *CodeGen();
};

class StringAST : public BaseAST
{
    string value;

public:
    StringAST()
    {
    }

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

/*** identifier ***/
class IdentifierAST : public BaseAST {
    string identifier;
public:
    IdentifierAST(string id) : identifier(id) {

    }

    string &getId() {
        return this->identifier;
    }

    void Print() {
        cout << identifier;
    }

    // llvm::Value *CodeGen();
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

//         for (int i = 0, e = params->exprList.size(); i < e; i++) {
//             this->params.push_back(exprPtr(params->exprList[i]));
//         }
//         this->setExprType(EXPRCALL);
//     }

//     void Print() {
//         func->Print();
//         cout << "(";
//         for (int i = 0; i < params.size(); i++) {
//             params[i]->Print();
//         }
//         cout << ")" << endl;
//     }

//     llvm::Value *CodeGen();
// };

// /*** binary calculation ***/
// class CalExpr : public Expr {
//     exprPtr Left;
//     exprPtr Right;
//     string op;
// public:
//     CalExpr(Expr *Left, Expr *Right, string &op) : Left(Left), Right(Right), op(op) {
//         this->setExprType(EXPRCAL);
//         this->setValueType(VALUEDEFAULT); 
//     }

//     void Print() {
//         cout << "(";
//         this->Left->Print();
//         cout << ")" << op << "(";
//         this->Right->Print();
//         cout << ")";
//     }

//     llvm::Value *CodeGen();
// };

#endif