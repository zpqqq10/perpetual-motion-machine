#ifndef __UTILS_H
#define __UTILS_H

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
#define VALUEDEFAULT -1
#define VALUEVOID 0 
#define VALUEINT 1
#define VALUEFLOAT 2
#define VALUECHAR 3
#define VALUEBOOL 4
#define VALUEARRAY 5
#define VALUESTRING 6
#define VALUEINVALID 16

// operands
#define OPADD 0   // arithmetic
#define OPSUB 1
#define OPMUL 2
#define OPDIV 3
#define OPAND 4   // bit
#define OPOR  5
#define OPXOR 6
#define OPGT  7   // relation
#define OPLT  8   
#define OPEQ  9   
#define OPNEQ 10   
#define OPLE  11  
#define OPGE  12  


#endif