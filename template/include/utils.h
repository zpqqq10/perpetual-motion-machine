#ifndef __UTILS_H
#define __UTILS_H

#include <vector>
#include <memory>
#include <string>
#include <iostream>
// type of statements
#define STMTDEFAULT -1
#define STMTEXPRESSION 0
#define STMTCOMPOUND 1
#define STMTSELECTION 2
#define STMTFOR 4
#define STMTWHILE 5
#define STMTRETURN 6

// type of expression
#define EXPRDEFAULT -1
#define EXPRID 0
#define EXPRVALUE 1
#define EXPRCAL 2
#define EXPRCALL 3
#define EXPRARRAY 4

// the type of returned value of the expression
#define TYPEDEFAULT -1
#define TYPEVOID 0
#define TYPEINT 1
#define TYPEFLOAT 2
#define TYPECHAR 3
#define TYPEBOOL 4
#define TYPEINTPTR 5
#define TYPEFLOATPTR 6
#define TYPECHARPTR 7
#define TYPEINVALID 16

// operands
#define OPADD 0 // arithmetic
#define OPSUB 1
#define OPMUL 2
#define OPDIV 3
#define OPAND 4 // bit
#define OPOR 5
#define OPXOR 6
#define OPGT 7 // relation
#define OPLT 8
#define OPEQ 9
#define OPNEQ 10
#define OPLE 11
#define OPGE 12
#define OPASSIGN 13
#define OPUMINUS 14
// COLOR
#define CANCEL "\e[0m"
#define RED "\e[1;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define BLUE "\e[1;34m"
#define PURPLE "\e[1;35m"
#define CYAN "\e[1;36m"
#define WHITE "\e[1;37m"
#define White "\e[0m"
#define CLEAR "\e[1;1H\e[2J"

#define REFVAR 0
#define REFFUNC 1
std::string get_type_name(int type);
std::string get_op_name(int op);
std::string get_ref_name(int ref);
void padding(int level);

class BaseAST
{
public:
    std::vector<BaseAST*> children;
    BaseAST(){;}
    ~BaseAST() {;}
    virtual void print(int level){
        padding(level);
        std::cout << "BASE" << std::endl;
    }
};

class Program: public BaseAST
{
private:
    /* data */
public:
    Program(/* args */){;}
    ~Program(){;}
    virtual void print(int level = 0){
        std::cout << "AST: " << std::endl;
        for (size_t i = 0; i < children.size(); i++)
        {
            children[i]->print(0);
        }
    }
};


#endif