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
    DQUOTE = 267,
    SQUOTE = 268,
    RETURN = 269,
    FOR = 270,
    IN = 271,
    TO = 272,
    WHILE = 273,
    IF = 274,
    ELSE = 275,
    BREAK = 276,
    IDENTIFIER = 277,
    STRING_VALUE = 278,
    COMMENT = 279,
    INT = 280,
    FLOAT = 281,
    BOOL = 282,
    VOID = 283,
    STRING = 284,
    INTEGER_VALUE = 285,
    FLOAT_VALUE = 286,
    FALSE = 287,
    TRUE = 288,
    ASSIGN = 289,
    GT = 290,
    LT = 291,
    EQ = 292,
    NEQ = 293,
    GE = 294,
    LE = 295,
    AND = 296,
    OR = 297,
    XOR = 298,
    ADD = 299,
    SUB = 300,
    MUL = 301,
    DIV = 302,
    UMINUS = 303
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
#define DQUOTE 267
#define SQUOTE 268
#define RETURN 269
#define FOR 270
#define IN 271
#define TO 272
#define WHILE 273
#define IF 274
#define ELSE 275
#define BREAK 276
#define IDENTIFIER 277
#define STRING_VALUE 278
#define COMMENT 279
#define INT 280
#define FLOAT 281
#define BOOL 282
#define VOID 283
#define STRING 284
#define INTEGER_VALUE 285
#define FLOAT_VALUE 286
#define FALSE 287
#define TRUE 288
#define ASSIGN 289
#define GT 290
#define LT 291
#define EQ 292
#define NEQ 293
#define GE 294
#define LE 295
#define AND 296
#define OR 297
#define XOR 298
#define ADD 299
#define SUB 300
#define MUL 301
#define DIV 302
#define UMINUS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "src/maggot.ypp"

	int valueType;

	char Op;
	char* valueStr;

#line 160 "src/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
