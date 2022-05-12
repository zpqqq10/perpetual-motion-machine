/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/maggot.ypp"

#include <iostream>
#include <string>
#include "main.h"
#include "declaration.h"
#include "expression.h"
#include "statement.h"
using namespace std;

extern Program* prog;

extern int yylex(void);

extern int yyparse();
int yyerror(const char *s);


#line 88 "src/y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_SRC_Y_TAB_HPP_INCLUDED
# define YY_YY_SRC_Y_TAB_HPP_INCLUDED
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
#line 20 "src/maggot.ypp"

	BaseAST* node;
	BaseAST** list;
	int valueType;
	std::string* str;
	char Op;
	std::string* valuetext;
	// BaseAST* node;

#line 246 "src/y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_HPP_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    53,    54,    58,    59,    60,    61,    65,
      68,    69,    72,    73,    74,    77,    78,    79,    80,    81,
      85,    89,    94,    95,    96,    98,    99,   102,   103,   107,
     111,   120,   123,   124,   125,   126,   127,   128,   129,   133,
     134,   139,   140,   144,   148,   149,   153,   154,   158,   159,
     162,   163,   164,   165,   166,   167,   168,   173,   174,   175,
     179,   180,   181,   184,   185,   186,   187,   188,   191,   192,
     193,   194,   195,   199,   203,   204,   207,   208
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COLON", "SEMICOLON", "COMMA", "LEFTP",
  "RIGHTP", "LEFTB", "RIGHTB", "LEFTSB", "RIGHTSB", "DQUOTE", "SQUOTE",
  "RETURN", "FOR", "IN", "TO", "WHILE", "IF", "ELSE", "BREAK",
  "IDENTIFIER", "STRING_VALUE", "COMMENT", "INT", "FLOAT", "BOOL", "VOID",
  "STRING", "INTEGER_VALUE", "FLOAT_VALUE", "FALSE", "TRUE", "ASSIGN",
  "GT", "LT", "EQ", "NEQ", "GE", "LE", "AND", "OR", "XOR", "ADD", "SUB",
  "MUL", "DIV", "UMINUS", "$accept", "program", "decl_list", "decl",
  "var_decl", "vars", "var", "type_specifier", "func_decl", "proto_decl",
  "params", "param_list", "param", "compound_stmt", "stmt_list", "stmt",
  "expression_stmt", "selection_stmt", "iteration_stmt", "return_stmt",
  "expression", "variable", "relation_expr", "addition", "term", "factor",
  "value", "call", "args", "arg_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF (-112)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,  -112,  -112,  -112,  -112,  -112,  -112,     6,   -10,  -112,
    -112,    -9,  -112,  -112,  -112,  -112,    -5,    91,  -112,    38,
      -2,    88,  -112,     1,    24,    15,    52,    46,  -112,    63,
      88,    44,  -112,  -112,  -112,  -112,  -112,    88,  -112,    55,
      65,    25,    51,  -112,  -112,  -112,    -7,  -112,    83,    49,
     119,  -112,   101,    88,    88,  -112,  -112,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    98,  -112,
    -112,  -112,  -112,  -112,  -112,   105,   123,   121,  -112,    25,
      25,    25,    25,    25,    25,    51,    51,  -112,  -112,  -112,
      16,  -112,    88,  -112,  -112,  -112,    84,   143,   144,  -112,
    -112,     1,  -112,  -112,  -112,  -112,  -112,  -112,   147,  -112,
    -112,   148,    88,    88,  -112,  -112,   146,   149,    54,    54,
    -112,   134,    54,  -112
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     8,    15,    16,    17,    18,    19,     0,     2,     4,
       5,     0,     6,     7,     1,     3,    12,     0,    11,    24,
       0,     0,     9,     0,    18,     0,     0,    22,    26,     0,
       0,    48,    70,    68,    69,    72,    71,     0,    14,    65,
      47,    56,    59,    62,    67,    66,    12,    10,    27,     0,
       0,    13,     0,    75,     0,    65,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      31,    20,    25,    63,    77,     0,    74,     0,    46,    52,
      51,    54,    55,    53,    50,    57,    58,    60,    61,    28,
       0,    73,     0,    49,    40,    29,     0,     0,     0,    38,
      37,     0,    33,    30,    32,    34,    35,    36,     0,    76,
      44,     0,     0,     0,    39,    45,     0,     0,     0,     0,
      43,    41,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -112,  -112,  -112,   150,     4,  -112,   132,     2,  -112,  -112,
    -112,  -112,   107,   110,  -112,  -111,  -112,  -112,  -112,  -112,
     -21,    76,  -112,    64,    66,   -11,  -112,  -112,  -112,  -112
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,   100,    17,    18,   101,    12,    13,
      26,    27,    28,   102,    90,   103,   104,   105,   106,   107,
     108,    39,    40,    41,    42,    43,    44,    45,    75,    76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      38,    19,    11,    20,    10,    20,    14,   120,   121,    52,
      11,   123,    10,    16,     1,     2,     3,     4,     5,     6,
      94,    25,    30,    46,    70,    95,    56,    21,    29,    21,
      96,   -23,    74,    77,    97,    98,    78,    48,    31,    32,
      99,     2,     3,     4,     5,     6,    33,    34,    35,    36,
      53,    50,    25,    69,    54,    87,    88,    70,    94,    49,
      30,    37,    70,     2,     3,     4,    24,     6,    96,    64,
      65,   109,    97,    98,    51,   111,    31,    32,    99,     2,
       3,     4,     5,     6,    33,    34,    35,    36,   110,    57,
      30,   116,   117,    68,    30,    22,    23,    66,    67,    37,
      58,    59,    60,    61,    62,    63,    31,    32,    73,    89,
      31,    32,    91,    55,    33,    34,    35,    36,    33,    34,
      35,    36,    79,    80,    81,    82,    83,    84,    92,    37,
      85,    86,    93,    37,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,     2,     3,     4,     5,     6,   112,
     113,   114,   115,   118,   122,    47,   119,    72,    15,    71
};

static const yytype_int8 yycheck[] =
{
      21,     6,     0,    10,     0,    10,     0,   118,   119,    30,
       8,   122,     8,    22,    24,    25,    26,    27,    28,    29,
       4,    19,     6,    22,     8,     9,    37,    34,    30,    34,
      14,     7,    53,    54,    18,    19,    57,    22,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       6,     5,    50,     4,    10,    66,    67,     8,     4,     7,
       6,    45,     8,    25,    26,    27,    28,    29,    14,    44,
      45,    92,    18,    19,    11,    96,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,     4,    34,
       6,   112,   113,    10,     6,     4,     5,    46,    47,    45,
      35,    36,    37,    38,    39,    40,    22,    23,     7,    11,
      22,    23,     7,    37,    30,    31,    32,    33,    30,    31,
      32,    33,    58,    59,    60,    61,    62,    63,     5,    45,
      64,    65,    11,    45,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    25,    26,    27,    28,    29,     6,
       6,     4,     4,     7,    20,    23,     7,    50,     8,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    25,    26,    27,    28,    29,    50,    51,    52,
      53,    56,    57,    58,     0,    52,    22,    54,    55,     6,
      10,    34,     4,     5,    28,    56,    59,    60,    61,    30,
       6,    22,    23,    30,    31,    32,    33,    45,    69,    70,
      71,    72,    73,    74,    75,    76,    22,    55,    22,     7,
       5,    11,    69,     6,    10,    70,    74,    34,    35,    36,
      37,    38,    39,    40,    44,    45,    46,    47,    10,     4,
       8,    62,    61,     7,    69,    77,    78,    69,    69,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    11,
      63,     7,     5,    11,     4,     9,    14,    18,    19,    24,
      53,    56,    62,    64,    65,    66,    67,    68,    69,    69,
       4,    69,     6,     6,     4,     4,    69,    69,     7,     7,
      64,    64,    20,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    52,    53,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    56,
      57,    58,    59,    59,    59,    60,    60,    61,    61,    62,
      63,    63,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    66,    66,    67,    68,    68,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    77,    77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     4,     3,     1,     1,     1,     1,     1,
       6,     6,     1,     1,     0,     3,     1,     2,     4,     3,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     5,     2,     3,     3,     1,     1,     4,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 50 "src/maggot.ypp"
                   {;}
#line 1518 "src/y.tab.cpp"
    break;

  case 3:
#line 53 "src/maggot.ypp"
                          {if((yyvsp[0].node)) prog->children.push_back((yyvsp[0].node));}
#line 1524 "src/y.tab.cpp"
    break;

  case 4:
#line 54 "src/maggot.ypp"
                        {if((yyvsp[0].node)) prog->children.push_back((yyvsp[0].node));}
#line 1530 "src/y.tab.cpp"
    break;

  case 5:
#line 58 "src/maggot.ypp"
               {(yyval.node) = (yyvsp[0].node);}
#line 1536 "src/y.tab.cpp"
    break;

  case 6:
#line 59 "src/maggot.ypp"
                    {(yyval.node) = (yyvsp[0].node);}
#line 1542 "src/y.tab.cpp"
    break;

  case 7:
#line 60 "src/maggot.ypp"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1548 "src/y.tab.cpp"
    break;

  case 8:
#line 61 "src/maggot.ypp"
                  {(yyval.node) = nullptr;}
#line 1554 "src/y.tab.cpp"
    break;

  case 9:
#line 65 "src/maggot.ypp"
                                        {(yyval.node) = (yyvsp[-1].node); dynamic_cast<VarDeclList *>(yyvsp[-1].node)->settype((yyvsp[-2].valueType));}
#line 1560 "src/y.tab.cpp"
    break;

  case 10:
#line 68 "src/maggot.ypp"
                     {(yyval.node) = (yyvsp[-2].node);dynamic_cast<VarDeclList *>(yyval.node)->addvar(dynamic_cast<VarDeclAST *>(yyvsp[0].node));}
#line 1566 "src/y.tab.cpp"
    break;

  case 11:
#line 69 "src/maggot.ypp"
              {(yyval.node) = new VarDeclList();dynamic_cast<VarDeclList *>(yyval.node)->addvar(dynamic_cast<VarDeclAST *>(yyvsp[0].node));}
#line 1572 "src/y.tab.cpp"
    break;

  case 12:
#line 72 "src/maggot.ypp"
                {(yyval.node) = new VarDeclAST(*(yyvsp[0].str));}
#line 1578 "src/y.tab.cpp"
    break;

  case 13:
#line 73 "src/maggot.ypp"
                                             {(yyval.node) = new VarDeclAST(*(yyvsp[-3].str), stoi(*(yyvsp[-1].valuetext)));}
#line 1584 "src/y.tab.cpp"
    break;

  case 14:
#line 74 "src/maggot.ypp"
                                  {(yyval.node) = new VarDeclAST(*(yyvsp[-2].str)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1590 "src/y.tab.cpp"
    break;

  case 15:
#line 77 "src/maggot.ypp"
                    {(yyval.valueType) = TYPEINT;}
#line 1596 "src/y.tab.cpp"
    break;

  case 16:
#line 78 "src/maggot.ypp"
                                  {(yyval.valueType) = TYPEFLOAT;}
#line 1602 "src/y.tab.cpp"
    break;

  case 17:
#line 79 "src/maggot.ypp"
                                 {(yyval.valueType) = TYPEBOOL;}
#line 1608 "src/y.tab.cpp"
    break;

  case 18:
#line 80 "src/maggot.ypp"
                                 {(yyval.valueType) = TYPEVOID;}
#line 1614 "src/y.tab.cpp"
    break;

  case 19:
#line 81 "src/maggot.ypp"
                                   {(yyval.valueType) = TYPESTRING;}
#line 1620 "src/y.tab.cpp"
    break;

  case 20:
#line 85 "src/maggot.ypp"
                                                                       {BaseAST* f = new FuncAST((yyvsp[-5].valueType), *(yyvsp[-4].str));f->children.push_back((yyvsp[-2].node));f->children.push_back((yyvsp[0].node));(yyval.node) = f;}
#line 1626 "src/y.tab.cpp"
    break;

  case 21:
#line 89 "src/maggot.ypp"
                                                                    {BaseAST* f = new ProtoAST((yyvsp[-5].valueType), *(yyvsp[-4].str));f->children.push_back((yyvsp[-2].node));(yyval.node) = f;}
#line 1632 "src/y.tab.cpp"
    break;

  case 22:
#line 94 "src/maggot.ypp"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1638 "src/y.tab.cpp"
    break;

  case 23:
#line 95 "src/maggot.ypp"
                 {(yyval.node) = new ParmVarDeclList(true);}
#line 1644 "src/y.tab.cpp"
    break;

  case 24:
#line 96 "src/maggot.ypp"
            {(yyval.node) = new ParmVarDeclList(true);}
#line 1650 "src/y.tab.cpp"
    break;

  case 25:
#line 98 "src/maggot.ypp"
                                   {(yyval.node) = (yyvsp[-2].node);dynamic_cast<ParmVarDeclList *>(yyval.node)->addvar(dynamic_cast<ParmVarDeclAST *>(yyvsp[0].node));}
#line 1656 "src/y.tab.cpp"
    break;

  case 26:
#line 99 "src/maggot.ypp"
                          {(yyval.node) = new ParmVarDeclList();dynamic_cast<ParmVarDeclList *>(yyval.node)->addvar(dynamic_cast<ParmVarDeclAST *>(yyvsp[0].node));}
#line 1662 "src/y.tab.cpp"
    break;

  case 27:
#line 102 "src/maggot.ypp"
                                 {(yyval.node) = new ParmVarDeclAST(*(yyvsp[0].str)); dynamic_cast<ParmVarDeclAST *>(yyval.node)->settype((yyvsp[-1].valueType));}
#line 1668 "src/y.tab.cpp"
    break;

  case 28:
#line 103 "src/maggot.ypp"
                                                    {(yyval.node) = new ParmVarDeclAST(*(yyvsp[-2].str), true); dynamic_cast<ParmVarDeclAST *>(yyval.node)->settype((yyvsp[-3].valueType));}
#line 1674 "src/y.tab.cpp"
    break;

  case 29:
#line 107 "src/maggot.ypp"
                                      {(yyval.node) = (yyvsp[-1].node);}
#line 1680 "src/y.tab.cpp"
    break;

  case 30:
#line 111 "src/maggot.ypp"
                          {
							if((yyvsp[-1].node) == nullptr)
								(yyval.node) = new CompoundStmtAST();
							else
								(yyval.node) = (yyvsp[-1].node);
							if((yyvsp[0].node) != nullptr)
								(yyval.node)->children.push_back((yyvsp[0].node));

							}
#line 1694 "src/y.tab.cpp"
    break;

  case 31:
#line 120 "src/maggot.ypp"
                   {(yyval.node) = new CompoundStmtAST();}
#line 1700 "src/y.tab.cpp"
    break;

  case 32:
#line 123 "src/maggot.ypp"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1706 "src/y.tab.cpp"
    break;

  case 33:
#line 124 "src/maggot.ypp"
                        {(yyval.node) = (yyvsp[0].node);}
#line 1712 "src/y.tab.cpp"
    break;

  case 34:
#line 125 "src/maggot.ypp"
                         {(yyval.node) = (yyvsp[0].node);}
#line 1718 "src/y.tab.cpp"
    break;

  case 35:
#line 126 "src/maggot.ypp"
                         {(yyval.node) = (yyvsp[0].node);}
#line 1724 "src/y.tab.cpp"
    break;

  case 36:
#line 127 "src/maggot.ypp"
                      {(yyval.node) = (yyvsp[0].node);}
#line 1730 "src/y.tab.cpp"
    break;

  case 37:
#line 128 "src/maggot.ypp"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1736 "src/y.tab.cpp"
    break;

  case 38:
#line 129 "src/maggot.ypp"
                  {(yyval.node) = nullptr;}
#line 1742 "src/y.tab.cpp"
    break;

  case 39:
#line 133 "src/maggot.ypp"
                                      {(yyval.node) = (yyvsp[-1].node);}
#line 1748 "src/y.tab.cpp"
    break;

  case 40:
#line 134 "src/maggot.ypp"
                                       {;}
#line 1754 "src/y.tab.cpp"
    break;

  case 41:
#line 139 "src/maggot.ypp"
                                                {(yyval.node) = new SelectionStmtAST(); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1760 "src/y.tab.cpp"
    break;

  case 42:
#line 140 "src/maggot.ypp"
                                                                      {(yyval.node) = new SelectionStmtAST(); (yyval.node)->children.push_back((yyvsp[-4].node)); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1766 "src/y.tab.cpp"
    break;

  case 43:
#line 144 "src/maggot.ypp"
                                                   {(yyval.node) = new IterationStmtAST(); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1772 "src/y.tab.cpp"
    break;

  case 44:
#line 148 "src/maggot.ypp"
                              {(yyval.node) = new ReturnStmtAST();}
#line 1778 "src/y.tab.cpp"
    break;

  case 45:
#line 149 "src/maggot.ypp"
                                                 {(yyval.node) = new ReturnStmtAST(); (yyval.node)->children.push_back((yyvsp[-1].node));}
#line 1784 "src/y.tab.cpp"
    break;

  case 46:
#line 153 "src/maggot.ypp"
                                       {(yyval.node) = new BinaryOpAST(OPASSIGN); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1790 "src/y.tab.cpp"
    break;

  case 47:
#line 154 "src/maggot.ypp"
                                  {(yyval.node) = (yyvsp[0].node);}
#line 1796 "src/y.tab.cpp"
    break;

  case 48:
#line 158 "src/maggot.ypp"
                     {(yyval.node) = new RefAST(*(yyvsp[0].str), REFVAR);}
#line 1802 "src/y.tab.cpp"
    break;

  case 49:
#line 159 "src/maggot.ypp"
                                                       {(yyval.node) = new ArraySubscriptExpr(); (yyval.node)->children.push_back(new RefAST(*(yyvsp[-3].str), REFVAR)); (yyval.node)->children.push_back((yyvsp[-1].node));}
#line 1808 "src/y.tab.cpp"
    break;

  case 50:
#line 162 "src/maggot.ypp"
                                         { (yyval.node) = new BinaryOpAST(OPLE); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1814 "src/y.tab.cpp"
    break;

  case 51:
#line 163 "src/maggot.ypp"
                                                     { (yyval.node) = new BinaryOpAST(OPLT); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1820 "src/y.tab.cpp"
    break;

  case 52:
#line 164 "src/maggot.ypp"
                                                     { (yyval.node) = new BinaryOpAST(OPGT); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1826 "src/y.tab.cpp"
    break;

  case 53:
#line 165 "src/maggot.ypp"
                                                     { (yyval.node) = new BinaryOpAST(OPGE); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1832 "src/y.tab.cpp"
    break;

  case 54:
#line 166 "src/maggot.ypp"
                                                     { (yyval.node) = new BinaryOpAST(OPEQ); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1838 "src/y.tab.cpp"
    break;

  case 55:
#line 167 "src/maggot.ypp"
                                                      {(yyval.node) = new BinaryOpAST(OPNEQ); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1844 "src/y.tab.cpp"
    break;

  case 56:
#line 168 "src/maggot.ypp"
                                {(yyval.node) = (yyvsp[0].node);}
#line 1850 "src/y.tab.cpp"
    break;

  case 57:
#line 173 "src/maggot.ypp"
                            { (yyval.node) = new BinaryOpAST(OPADD); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1856 "src/y.tab.cpp"
    break;

  case 58:
#line 174 "src/maggot.ypp"
                                    { (yyval.node) = new BinaryOpAST(OPSUB); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1862 "src/y.tab.cpp"
    break;

  case 59:
#line 175 "src/maggot.ypp"
                       {(yyval.node) = (yyvsp[0].node);}
#line 1868 "src/y.tab.cpp"
    break;

  case 60:
#line 179 "src/maggot.ypp"
                      { (yyval.node) = new BinaryOpAST(OPMUL); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1874 "src/y.tab.cpp"
    break;

  case 61:
#line 180 "src/maggot.ypp"
                          { (yyval.node) = new BinaryOpAST(OPDIV); (yyval.node)->children.push_back((yyvsp[-2].node)); (yyval.node)->children.push_back((yyvsp[0].node));}
#line 1880 "src/y.tab.cpp"
    break;

  case 62:
#line 181 "src/maggot.ypp"
                 {(yyval.node) = (yyvsp[0].node);}
#line 1886 "src/y.tab.cpp"
    break;

  case 63:
#line 184 "src/maggot.ypp"
                                {(yyval.node) = (yyvsp[-1].node);}
#line 1892 "src/y.tab.cpp"
    break;

  case 64:
#line 185 "src/maggot.ypp"
                                    {(yyval.node) = new UnaryOpAST(OPUMINUS); (yyval.node)->children.push_back((yyvsp[0].node)); }
#line 1898 "src/y.tab.cpp"
    break;

  case 65:
#line 186 "src/maggot.ypp"
                     {(yyval.node) = (yyvsp[0].node);}
#line 1904 "src/y.tab.cpp"
    break;

  case 66:
#line 187 "src/maggot.ypp"
                 {(yyval.node) = (yyvsp[0].node);}
#line 1910 "src/y.tab.cpp"
    break;

  case 67:
#line 188 "src/maggot.ypp"
                  {(yyval.node) = (yyvsp[0].node);}
#line 1916 "src/y.tab.cpp"
    break;

  case 68:
#line 191 "src/maggot.ypp"
                     {(yyval.node) = new IntegerAST(stoi(*(yyvsp[0].valuetext)));}
#line 1922 "src/y.tab.cpp"
    break;

  case 69:
#line 192 "src/maggot.ypp"
                       {(yyval.node) = new FloatAST(stof(*(yyvsp[0].valuetext)));}
#line 1928 "src/y.tab.cpp"
    break;

  case 70:
#line 193 "src/maggot.ypp"
                        {(yyval.node) = new StringAST(*(yyvsp[0].str));}
#line 1934 "src/y.tab.cpp"
    break;

  case 71:
#line 194 "src/maggot.ypp"
                {(yyval.node) = new BoolAST(true);}
#line 1940 "src/y.tab.cpp"
    break;

  case 72:
#line 195 "src/maggot.ypp"
                 {(yyval.node) = new BoolAST(false);}
#line 1946 "src/y.tab.cpp"
    break;

  case 73:
#line 199 "src/maggot.ypp"
                                   {(yyval.node) = new CallExpr(); (yyval.node)->children.push_back(new RefAST(*(yyvsp[-3].str), REFFUNC));if((yyvsp[-1].node)) (yyval.node)->children.push_back((yyvsp[-1].node)); }
#line 1952 "src/y.tab.cpp"
    break;

  case 74:
#line 203 "src/maggot.ypp"
               {(yyval.node) = (yyvsp[0].node);}
#line 1958 "src/y.tab.cpp"
    break;

  case 75:
#line 204 "src/maggot.ypp"
          {(yyval.node) = nullptr;}
#line 1964 "src/y.tab.cpp"
    break;

  case 76:
#line 207 "src/maggot.ypp"
                                    {(yyval.node) = (yyvsp[-2].node); dynamic_cast<ArgsList *>(yyval.node)->addvar(dynamic_cast<BaseAST *>(yyvsp[0].node));}
#line 1970 "src/y.tab.cpp"
    break;

  case 77:
#line 208 "src/maggot.ypp"
                             {(yyval.node) = new ArgsList(); dynamic_cast<ArgsList *>(yyval.node)->addvar(dynamic_cast<BaseAST *>(yyvsp[0].node));}
#line 1976 "src/y.tab.cpp"
    break;


#line 1980 "src/y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 211 "src/maggot.ypp"



int yyerror(const char *s)
{
	error("%s", s);
	return 0;
}
