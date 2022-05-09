#ifndef __DECLARATION_H
#define __DECLARATION_H

#include <iostream>
#include <string>
#include <vector>
#include "utils.h"
using namespace std;

// variable declaration
class VarDeclAST : public BaseAST{
private:
    /* data */
    string name;
    int type;
    int length;     // for pointer
    int i_initial;  // for integer and bool
    float f_initial;
public:
    VarDeclAST(string n): name(n){
        length = -1;
    }
    VarDeclAST(string n, int len): name(n), length(len){;}
    ~VarDeclAST(){;}
    virtual void settype(int t){
        type = t;
    }
    virtual void print(int level)
    {
        padding(level);
        cout << GREEN << "VarDecl " << CYAN << name << White << " " << gettypename(type);
        if(length > 0){
            cout << "* ";
        }
        cout << endl;
        // for (int i = 0; i < children.size(); i++)
        // {
        //     children[i]->print(level + 1);
        // }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// variable declaration list (that is, a line)
class VarDeclList : public BaseAST{
private:
    /* data */
    vector<unique_ptr<VarDeclAST>> vars;
public:
    VarDeclList(/* args */){;}
    ~VarDeclList(){;}
    virtual void settype(int t){
        for(size_t i=0; i<vars.size(); i++){
            vars[i]->settype(t);
        }
    }
    void addvar(unique_ptr<VarDeclAST> var){
        vars.push_back(move(var));
    }
    size_t size(){
        return vars.size();
    }
    unique_ptr<VarDeclAST> & operator[](int i){
        return vars[i];
    }
    void clear(){
        vars.clear();
    }
    virtual void print(int level)
    {
        // cout << vars.size() << endl;
        for (size_t i = 0; i < vars.size(); i++)
        {
            vars[i]->print(level);
        }
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
        cout << GREEN << "FunctionDecl " << CYAN << funcname << White << " " << gettypename(rettype) << endl;
        // for (int i = 0; i < children.size(); i++)
        // {
        //     children[i]->print(level + 1);
        // }
        return;
    }
    // virtual llvm::Value *CodeGen();
};

// 应该没啥用
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

#endif