#ifndef __DECLARATION_H
#define __DECLARATION_H

#include <iostream>
#include <string>
#include <vector>
#include "utils.h"
using namespace std;

// variable declaration
class VarDeclAST : public BaseAST
{
private:
    /* data */
    string name;
    int type;
    int length;    // for pointer
    int i_initial; // for integer and bool
    float f_initial;

public:
    VarDeclAST(string n) : name(n)
    {
        length = -1;
    }
    VarDeclAST(string n, int len) : name(n), length(len) { ; }
    ~VarDeclAST() { ; }
    virtual void settype(int t)
    {
        type = t;
    }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "VarDecl " << CYAN << name << White << " " << get_type_name(type);
        if (length > 0)
        {
            cout << "* ";
        }
        cout << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// temporary variable declaration list (that is, a line)
class VarDeclList : public BaseAST
{
private:
    

public:
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
        cout << GREEN << "DeclStmt " << endl;
        for (size_t i = 0; i < vars.size(); i++)
        {
            vars[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// param variable declaration
class ParmVarDeclAST : public BaseAST
{
private:
    /* data */
    string name;
    int type;
    bool is_pointer;    // for pointer
    int i_initial; // for integer and bool
    float f_initial;

public:
    ParmVarDeclAST(string n) : name(n)
    {
        is_pointer = false;
    }
    ParmVarDeclAST(string n, bool flag) : name(n), is_pointer(flag) { ; }
    ~ParmVarDeclAST() { ; }
    virtual void settype(int t)
    {
        type = t;
    }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "ParmVarDecl " << CYAN << name << White << " " << get_type_name(type);
        if (is_pointer)
        {
            cout << "* ";
        }
        cout << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
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
        if (!is_void) { // if it is VOID, then print nothing
            for (size_t i = 0; i < parms.size(); i++)
                {
                    parms[i]->print(level);
                }
        }
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
    // TODO a member for body
public:
    FuncAST() { ; }
    FuncAST(int type, string name) : rettype(type), funcname(name) { ; }
    ~FuncAST() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "FunctionDecl " << CYAN << funcname << White << " " << get_type_name(rettype) << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
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
        cout << GREEN << "FunctionDecl " << CYAN << funcname << White << " " << get_type_name(rettype) << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// selection stmt
class SelectionStmt : public BaseAST
{
private:
    /* data */
public:
    SelectionStmt() { ; }
    ~SelectionStmt() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "IfStmt " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// iteration stmt
class IterationStmt : public BaseAST
{
private:
    /* data */
public:
    IterationStmt() { ; }
    ~IterationStmt() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "WhileStmt " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
};


// return stmt
class ReturnStmt : public BaseAST
{
private:
    /* data */
public:
    ReturnStmt() { ; }
    ~ReturnStmt() { ; }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "ReturnStmt " << White << endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(level + 1);
        }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

#endif