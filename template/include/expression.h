#ifndef __EXPRESSION_H
#define __EXPRESSION_H

#include <vector>
#include <iostream>
#include <memory>
#include "utils.h"
#include "statement.h"

using namespace std;

class ExprList {
public:
    vector<Expr *> exprList;
    ExprList() {}

    void pushExpr(Expr *expr) {
        this->exprList.push_back(expr);
    }
};

/*** value ***/
class Void : public Expr
{
public:
    Void()
    {
        this->setExprType(EXPRVALUE);
        this->setValueType(VALUEVOID);
    }

    void Print()
    {
        cout << "VOID" << endl;
    }

    llvm::Value *CodeGen();
};

class Integer : public Expr
{
    int value;

public:
    Integer(int v) : value(v)
    {
        this->setExprType(EXPRVALUE);
        this->setValueType(VALUEINT);
    }

    int getValue()
    {
        return this->value;
    }

    void Print()
    {
        cout << "int: " << value << endl;
    }

    llvm::Value *CodeGen();
};

class Float : public Expr
{
    double value;

public:
    Float(double v) : value(v)
    {
        this->setExprType(EXPRVALUE);
        this->setValueType(VALUEFLOAT);
    }

    double getValue()
    {
        return this->value;
    }

    void Print()
    {
        cout << "float: " << value << endl;
    }

    llvm::Value *CodeGen();
};

class Bool : public Expr
{
    bool value;

public:
    Bool(bool v) : value(v)
    {
        this->setExprType(EXPRVALUE);
        this->setValueType(VALUEBOOL);
    }

    bool getValue()
    {
        return this->value;
    }

    void Print()
    {
        cout << "bool: " << value << endl;
    }

    llvm::Value *CodeGen();
};

class String : public Expr
{
    string value;

public:
    String()
    {
        this->setExprType(EXPRVALUE);
        this->value = "";
    }

    String(string &v)
    {
        this->setExprType(EXPRVALUE);
        if (v.length() == 2)
            this->value = "";
        else
            this->value = v.substr(1, v.length() - 2);
        this->setValueType(VALUESTRING);
    }

    string &getValue()
    {
        return this->value;
    }

    void Print()
    {
        cout << "string: " << value << endl;
    }

    llvm::Value *CodeGen();
};

/*** identifier ***/
class Identifier : public Expr {
    string identifier;
public:
    Identifier(string &id) : identifier(id) {
        this->setExprType(EXPRID);
    }

    string &getId() {
        return this->identifier;
    }

    void Print() {
        cout << identifier;
    }

    llvm::Value *CodeGen();
};
typedef unique_ptr<Identifier> idPtr;

/*** array element ***/
class ArrEExpr: public Expr {
    Identifier array;
    exprPtr index;
public:
    ArrEExpr(string &arr, Expr* ind): array(arr), index(ind){
        this->setExprType(EXPRARRAY);
    }

    ArrEExpr(string &arr): array(arr){
        this->index = nullptr;
        this->setExprType(EXPRARRAY);
    }

    string &getId(){
        return array.getId();
    }

    Expr* getIndex(){
        if(index)
            return index.get();
        return nullptr;
    }

    void Print() {
        cout << "array: " << array.getId() << '[' << index << ']' << endl;
    }

    llvm::Value* CodeGen();
};

/*** function call ***/
class Call : public Expr {
    idPtr func;
    vector<exprPtr> params;
public:
    Call(Expr *funcName, ExprList *params) {
        Identifier *p = static_cast<Identifier *>(funcName);
        this->func = idPtr(p);

        for (int i = 0, e = params->exprList.size(); i < e; i++) {
            this->params.push_back(exprPtr(params->exprList[i]));
        }
        this->setExprType(EXPRCALL);
    }

    void Print() {
        func->Print();
        cout << "(";
        for (int i = 0; i < params.size(); i++) {
            params[i]->Print();
        }
        cout << ")" << endl;
    }

    llvm::Value *CodeGen();
};

/*** binary calculation ***/
class CalExpr : public Expr {
    exprPtr Left;
    exprPtr Right;
    string op;
public:
    CalExpr(Expr *Left, Expr *Right, string &op) : Left(Left), Right(Right), op(op) {
        this->setExprType(EXPRCAL);
        this->setValueType(VALUEDEFAULT); 
    }

    void Print() {
        cout << "(";
        this->Left->Print();
        cout << ")" << op << "(";
        this->Right->Print();
        cout << ")";
    }

    llvm::Value *CodeGen();
};

#endif