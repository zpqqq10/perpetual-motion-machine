/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COLON = 258,
    SEMICOLON = 259,
    COMMA = 260,
    LEFTP = 261,
    RIGHTP = 262,
    LEFTB = 263,
    RIGHTB = 264,
    LEFTSB = 265,
    RIGHTSB = 266,
    MAIN = 267,
    RETURN = 268,
    FOR = 269,
    IN = 270,
    TO = 271,
    WHILE = 272,
    IF = 273,
    ELSE = 274,
    BREAK = 275,
    IDENTIFIER = 276,
    STRING_VALUE = 277,
    COMMENT = 278,
    INT = 279,
    FLOAT = 280,
    BOOL = 281,
    VOID = 282,
    STRING = 283,
    INTEGER_VALUE = 284,
    FLOAT_VALUE = 285,
    FALSE = 286,
    TRUE = 287,
    ASSIGN = 288,
    GT = 289,
    LT = 290,
    EQ = 291,
    NEQ = 292,
    GE = 293,
    LE = 294,
    AND = 295,
    OR = 296,
    XOR = 297,
    ADD = 298,
    SUB = 299,
    MUL = 300,
    DIV = 301
  };
#endif
/* Tokens.  */
#define COLON 258
#define SEMICOLON 259
#define COMMA 260
#define LEFTP 261
#define RIGHTP 262
#define LEFTB 263
#define RIGHTB 264
#define LEFTSB 265
#define RIGHTSB 266
#define MAIN 267
#define RETURN 268
#define FOR 269
#define IN 270
#define TO 271
#define WHILE 272
#define IF 273
#define ELSE 274
#define BREAK 275
#define IDENTIFIER 276
#define STRING_VALUE 277
#define COMMENT 278
#define INT 279
#define FLOAT 280
#define BOOL 281
#define VOID 282
#define STRING 283
#define INTEGER_VALUE 284
#define FLOAT_VALUE 285
#define FALSE 286
#define TRUE 287
#define ASSIGN 288
#define GT 289
#define LT 290
#define EQ 291
#define NEQ 292
#define GE 293
#define LE 294
#define AND 295
#define OR 296
#define XOR 297
#define ADD 298
#define SUB 299
#define MUL 300
#define DIV 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "src/maggot.ypp"

	/* Block* block; */

	int valueType;
	/* int intval;
	Decl* decl;
	DeclList* declList;
	Stmt* stmt;
	StmtList* stmtList;
	Expr* expr;
	ExprList* exprList;

	FuncBody* funcbody;
	FuncImpl* funcImpl;
	FuncList* funcList;
	char Char; */
	char Op;
	char* valueStr;
    string* Str;

#line 170 "src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
