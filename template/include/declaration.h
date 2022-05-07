#ifndef __DECLARATION_H
#define __DECLARATION_H

#include <iostream>
#include <string>
#include "utils.h"
using namespace std;

// variable declaration
class VarDeclAST : public BaseAST{
private:
    /* data */
    string name;
    int type;
    int length;
public:
    VarDeclAST(/* args */){;}
    ~VarDeclAST(){;}
    virtual void print(int level)
    {
        padding(level);
        cout << "var" << endl;
        // for (int i = 0; i < children.size(); i++)
        // {
        //     children[i]->print(level + 1);
        // }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// parameter variable declaration
class ParmVarDeclAST : public BaseAST{
private:
    /* data */
public:
    ParmVarDeclAST(){;}
    // with a third parameter for body
    // ParmVarDeclAST(int type, string& name): rettype(type), funcname(name){;}
    ~ParmVarDeclAST(){;}
    virtual void print(int level)
    {
        padding(level);
        // for (int i = 0; i < children.size(); i++)
        // {
        //     children[i]->print(level + 1);
        // }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// prototype declaration
class ProtoAST : public BaseAST
{
private:
    /* data */
    int rettype;
    string funcname;
public:
    ProtoAST(){;}
    ~ProtoAST(){;}
    virtual void print(int level)
    {
        padding(level);
        cout << "proto" << endl;
        // for (int i = 0; i < children.size(); i++)
        // {
        //     children[i]->print(level + 1);
        // }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// function definition
class FuncAST : public BaseAST
{
private:
    /* data */
    int rettype;
    string funcname;
    //TODO a member for body
public:
    FuncAST(){;}
    FuncAST(int type, string name): rettype(type), funcname(name){;}
    ~FuncAST(){;}
    virtual void print(int level)
    {
        padding(level);
        cout << "FunctionDecl " << funcname << " " << gettypename(rettype) << endl;
        // for (int i = 0; i < children.size(); i++)
        // {
        //     children[i]->print(level + 1);
        // }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

#endif