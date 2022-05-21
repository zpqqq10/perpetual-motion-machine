#ifndef __DECLARATION_H
#define __DECLARATION_H

#include <iostream>
#include <string>
#include <vector>
#include "llvm/IR/Function.h"
#include "utils.h"
using namespace std;

// variable declaration
class VarDeclAST : public BaseAST
{
private:
    /* data */

public:
    bool isGlobal;
    int type;
    string name;
    int length; // for pointer
    VarDeclAST(string n) : name(n)
    {
        length = -1;
    }
    VarDeclAST(string n, int len) : name(n), length(len) { ; }
    ~VarDeclAST() { ; }
    virtual void settype(int t)
    {
        type = t;
        if (length != -1)
        {
            type += TYPEARRAY;
        }
    }
    virtual void setGlobal(bool g)
    {
        isGlobal = g;
    }
    virtual void print(int level)
    {
        padding(level);
        cout << _GREEN << "VarDecl " << _CYAN << name << _RED << (isGlobal ? " global" : " local") << White << " " << get_type_name(type);

        cout << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

// temporary variable declaration list (that is, a line)
class VarDeclList : public BaseAST
{
private:
public:
    bool isGlobal;
    vector<VarDeclAST *> vars;
    VarDeclList(/* args */) { ; }
    ~VarDeclList() { ; }
    virtual void settype(int t)
    {
        for (size_t i = 0; i < vars.size(); i++)
        {
            vars[i]->settype(t);
        }
    }
    virtual void setGlobal(bool g)
    {
        isGlobal = g;
        for (size_t i = 0; i < vars.size(); i++)
        {
            vars[i]->setGlobal(g);
        }
    }
    void addvar(VarDeclAST *var)
    {
        vars.push_back(var);
    }
    size_t size()
    {
        return vars.size();
    }
    VarDeclAST *&operator[](int i)
    {
        return vars[i];
    }
    void clear()
    {
        vars.clear();
    }
    virtual void print(int level)
    {
        padding(level);
        cout << _PURPLE << "DeclStmt " << White << endl;
        for (size_t i = 0; i < vars.size(); i++)
        {
            vars[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

// param variable declaration
class ParmVarDeclAST : public BaseAST
{
private:
    /* data */

public:
    int type;
    string name;
    ParmVarDeclAST(string n) : name(n) {}

    ~ParmVarDeclAST() { ; }
    virtual void settype(int t)
    {
        type = t;
    }
    virtual void print(int level)
    {
        padding(level);
        cout << _GREEN << "ParmVarDecl " << _CYAN << name << White << " " << get_type_name(type);

        cout << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

// parameter variable declaration
class ParmVarDeclList : public BaseAST
{
private:
    bool is_void;

public:
    vector<ParmVarDeclAST *> parms;
    ParmVarDeclList() { is_void = false; }
    ParmVarDeclList(bool flag) : is_void(flag) { ; }
    // with a third parameter for body
    // ParmVarDeclList(int type, string& name): rettype(type), funcname(name){;}
    ~ParmVarDeclList() { ; }
    void addvar(ParmVarDeclAST *var)
    {
        parms.push_back(var);
    }
    size_t size()
    {
        return parms.size();
    }
    ParmVarDeclAST *&operator[](int i)
    {
        return parms[i];
    }
    void clear()
    {
        parms.clear();
    }
    virtual void print(int level)
    {
        if (!is_void)
        { // if it is VOID, then print nothing
            for (size_t i = 0; i < parms.size(); i++)
            {
                parms[i]->print(level);
            }
        }
        return;
    }

    virtual llvm::Value *CodeGen();
};

// function definition
class FuncAST : public BaseAST
{
private:
    /* data */
    int rettype;
    string funcname;

public:
    FuncAST() { ; }
    FuncAST(int type, string name) : rettype(type), funcname(name) { ; }
    ~FuncAST() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << _GREEN << "FunctionDecl " << _CYAN << funcname << White << " " << get_type_name(rettype) << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Function *CodeGen();
};

// function declaration
class ProtoAST : public BaseAST
{
private:
    /* data */
    int rettype;
    string funcname;

public:
    ProtoAST(int type, string name) : rettype(type), funcname(name) { ; }
    ~ProtoAST() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << _GREEN << "FunctionDecl " << _CYAN << funcname << White << " " << get_type_name(rettype) << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }

    virtual llvm::Function *CodeGen();
};

#endif