%{
#include <iostream>
#include <string>
#include "../include/main.h"
#include "../include/utils.h"
using namespace std;

extern int yylex(void);

extern int yyparse();
int yyerror(const char *s);

%}

%union
{
	int valueType;

	char Op;
	char* valueStr;
}

%token COLON SEMICOLON COMMA LEFTP RIGHTP LEFTB RIGHTB LEFTSB RIGHTSB DQUOTE SQUOTE
%token RETURN FOR IN TO WHILE IF ELSE BREAK
%token IDENTIFIER STRING_VALUE COMMENT
%token <valueStr> INT FLOAT BOOL VOID STRING
%token <valueStr> INTEGER_VALUE FLOAT_VALUE FALSE TRUE

%token ASSIGN GT LT EQ NEQ GE LE AND OR XOR
%left <Op> ADD SUB
%left <Op> MUL DIV
%right <Op> UMINUS

%start program


%%

program: decl_list {;}
	   ;

decl_list: decl_list decl {;}
		 | decl {;}
		 ;

// one declaration of a variable or a function
decl: var_decl {;}
	| func_decl {;}
	| COMMENT {;}
	;

// variable declaration
// var_decl: type_specifier IDENTIFIER SEMICOLON {;}
// 		| type_specifier IDENTIFIER LEFTSB INTEGER_VALUE RIGHTSB SEMICOLON {;}
// 		; 
var_decl: type_specifier vars SEMICOLON {;}
		; 

vars: vars COMMA var {;}
	| var {;}
	;

var: IDENTIFIER {;}
   | IDENTIFIER LEFTSB INTEGER_VALUE RIGHTSB {;}
   ;

type_specifier: INT {;}
			  | FLOAT {;}
			  | BOOL {;}
			  | VOID {;}
			  | STRING {;}
			  ;

// function declaration
func_decl: type_specifier IDENTIFIER LEFTP params RIGHTP compound_stmt {;}
		 | type_specifier IDENTIFIER LEFTP params RIGHTP SEMICOLON {;}
		 ;

// parameters of a function declaration or a function definition
params: param_list {;}
	  | {;}
	  ;

param_list: param_list COMMA param {;}
		  | param {;}
		  ;

param: type_specifier IDENTIFIER {;}
	 | type_specifier IDENTIFIER LEFTSB RIGHTSB {;}
	 ;

// begin with { and end with }
compound_stmt: LEFTB local_decls stmt_list RIGHTB {;}
			 ;

local_decls: local_decls var_decl {;}
		   | {;}
		   
		   ;

// statements
stmt_list: stmt_list stmt {;}
		 | {;}
		 ;

stmt: expression_stmt {;}
	| compound_stmt {;}
	| selection_stmt {;}
	| iteration_stmt {;}
	| return_stmt {;}
	| COMMENT {;}
	;

// expression
expression_stmt: expression SEMICOLON {;}
			   | SEMICOLON {;}
			   ;

// if else
selection_stmt: IF LEFTP expression RIGHTP stmt {;}
			  | IF LEFTP expression RIGHTP stmt ELSE stmt {;}
			  ;
// stmt: matched_stmt {;}
// 	| unmatched_stmt {;}
// 	;

// matched_stmt: IF LEFTP expression RIGHTP matched_stmt ELSE matched_stmt {;}
// 			| expression_stmt {;}
// 			| compound_stmt {;}
// 			| iteration_stmt {;}
// 			| return_stmt {;}
// 			;

// unmatched_stmt: IF LEFTP expression RIGHTP stmt {;}
// 			  | IF LEFTP expression RIGHTP matched_stmt ELSE unmatched_stmt {;}
// 			  ;

// while
iteration_stmt: WHILE LEFTP expression RIGHTP stmt {;}
			  ;

// return
return_stmt: RETURN SEMICOLON {;}
		   | RETURN expression SEMICOLON {;}
		   ;

expression: variable ASSIGN expression {;}
		  | simple_expr {;}
		  ;

variable: IDENTIFIER {;}
		| IDENTIFIER LEFTSB expression RIGHTSB {;}
		;

simple_expr: addition relationop addition {;}
		   | addition {;}
		   ;

relationop: LE {;}
		  | LT {;}
		  | GT {;}
		  | GE {;}
		  | EQ {;}
		  | NEQ {;}
		  ;

// + or -
addition: addition ADD term {;}
		| addition SUB term {;}
		| term {;}
		;

term: term MUL factor {;}
	| term DIV factor {;}
	| factor {;}
	;

factor: LEFTP expression RIGHTP {;}
	//   | '-' expression %prec UMINUS {cout << "---" << endl;}
	  | variable {;}
	  | call {;}
	  | value {;}
	  ;

value: INTEGER_VALUE {;}
	//  | SUB INTEGER_VALUE {;}
	 | FLOAT_VALUE {;}
	 | TRUE {;}
	 | FALSE {;}
	 ;

// function call
call: IDENTIFIER LEFTP args RIGHTP {;}
	;

// args of a function call
args: arg_list {;}
	| {;}
	;

arg_list: arg_list COMMA expression {;}
		| expression {;}
		;

%%


int yyerror(const char *s)
{
	error("%s", s);
	return 0;
}

