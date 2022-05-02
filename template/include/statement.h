#ifndef __STATEMENT_H
#define __STATEMENT_H

#include <vector>
#include <iostream>
#include <memory>
#include "utils.h"

using namespace std;

// parent object
class Stmt: {
    int stmtType;
public:
    Stmt() {
        this->stmtType = STMTDEFAULT;
    }

    ~Stmt() {}

    void setStmtType(int type) {
        this->stmtType = type;
    }

    int getStmtType() {
        return this->stmtType;
    }

    virtual void Print() {
        cout << "STMT" << endl;
    }

    virtual llvm::Value *CodeGen();
};
typedef unique_ptr<Stmt> stmtPtr;

// expression
class Expr : public Stmt {
    int exprType;
public:
    int valueType;
    // ? a member for return value

    Expr() {
        this->valueType = VALUEDEFAULT;
        this->exprType = EXPRDEFAULT; 
        this->setStmtType(STMTEXPRESSION);
    }

    ~Expr() {}

    void setExprType(int type) {
        this->exprType = type;
    }

    int getExprType() {
        return this->exprType;
    }

    void setValueType(int type) {
        this->valueType = type;
    }

    virtual int getValueType() {
        return this->valueType;
    }

    virtual void Print() {
        cout << "EXPR" << endl;
    }

    llvm::Value *CodeGen();
};
typedef unique_ptr<Expr> exprPtr;

#endif