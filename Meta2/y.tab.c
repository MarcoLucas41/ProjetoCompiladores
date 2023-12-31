/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LOW = 258,
     COMMA = 259,
     ASSIGN = 260,
     ELSE = 261,
     BITWISEOR = 262,
     BITWISEXOR = 263,
     BITWISEAND = 264,
     OR = 265,
     AND = 266,
     GE = 267,
     GT = 268,
     LE = 269,
     LT = 270,
     NE = 271,
     EQ = 272,
     MINUS = 273,
     PLUS = 274,
     MOD = 275,
     DIV = 276,
     MUL = 277,
     NOT = 278,
     HIGH = 279,
     LOWER = 280,
     HIGHER = 281,
     CHAR = 282,
     INT = 283,
     SHORT = 284,
     DOUBLE = 285,
     RETURN = 286,
     VOID = 287,
     SEMI = 288,
     LBRACE = 289,
     LPAR = 290,
     RBRACE = 291,
     RPAR = 292,
     WHILE = 293,
     IF = 294,
     CHRLITS = 295,
     IDENTIFIER = 296,
     NATURAL = 297,
     DECIMAL = 298,
     RESERVED = 299
   };
#endif
/* Tokens.  */
#define LOW 258
#define COMMA 259
#define ASSIGN 260
#define ELSE 261
#define BITWISEOR 262
#define BITWISEXOR 263
#define BITWISEAND 264
#define OR 265
#define AND 266
#define GE 267
#define GT 268
#define LE 269
#define LT 270
#define NE 271
#define EQ 272
#define MINUS 273
#define PLUS 274
#define MOD 275
#define DIV 276
#define MUL 277
#define NOT 278
#define HIGH 279
#define LOWER 280
#define HIGHER 281
#define CHAR 282
#define INT 283
#define SHORT 284
#define DOUBLE 285
#define RETURN 286
#define VOID 287
#define SEMI 288
#define LBRACE 289
#define LPAR 290
#define RBRACE 291
#define RPAR 292
#define WHILE 293
#define IF 294
#define CHRLITS 295
#define IDENTIFIER 296
#define NATURAL 297
#define DECIMAL 298
#define RESERVED 299




/* Copy the first part of user declarations.  */
#line 2 "uccompiler.y"

#include "ast.h"
#include <stdio.h>
#include <stdbool.h>
struct node *program;
struct node *helper;
struct node_list *error_list; 
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
extern int yyleng;
extern int syn_line;
extern int syn_column;
extern bool type2;

int error_flag = 1;
//int yydebug=1;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 45 "uccompiler.y"
{ 
    char *lexeme;
    struct node *root;
    struct node_list *root_list;
}
/* Line 193 of yacc.c.  */
#line 210 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 223 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  132

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    14,    16,    18,    22,
      25,    29,    32,    35,    37,    39,    43,    48,    52,    54,
      57,    59,    64,    66,    70,    71,    73,    75,    77,    79,
      81,    85,    87,    90,    94,    98,   106,   112,   118,   122,
     125,   128,   130,   131,   134,   135,   139,   143,   147,   151,
     155,   159,   163,   167,   171,   175,   179,   183,   187,   191,
     195,   199,   203,   207,   210,   213,   216,   221,   225,   230,
     232,   234,   236,   238,   242,   246,   250
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    46,    47,    -1,    46,    50,    -1,    46,
      54,    -1,    47,    -1,    50,    -1,    54,    -1,    56,    51,
      48,    -1,    34,    36,    -1,    34,    49,    36,    -1,    58,
      49,    -1,    54,    49,    -1,    58,    -1,    54,    -1,    56,
      51,    33,    -1,    41,    35,    52,    37,    -1,    52,     4,
      53,    -1,    53,    -1,    56,    41,    -1,    56,    -1,    56,
      57,    55,    33,    -1,    59,    -1,    55,     4,    57,    -1,
      -1,    27,    -1,    28,    -1,    32,    -1,    29,    -1,    30,
      -1,    41,     5,    62,    -1,    41,    -1,    60,    33,    -1,
      34,    61,    36,    -1,    34,    59,    36,    -1,    39,    35,
      62,    37,    58,     6,    58,    -1,    39,    35,    62,    37,
      58,    -1,    38,    35,    62,    37,    58,    -1,    31,    62,
      33,    -1,    31,    33,    -1,     1,    33,    -1,    62,    -1,
      -1,    61,    58,    -1,    -1,    62,     5,    62,    -1,    62,
       4,    62,    -1,    62,    19,    62,    -1,    62,    18,    62,
      -1,    62,    22,    62,    -1,    62,    21,    62,    -1,    62,
      20,    62,    -1,    62,    10,    62,    -1,    62,    11,    62,
      -1,    62,     9,    62,    -1,    62,     7,    62,    -1,    62,
       8,    62,    -1,    62,    17,    62,    -1,    62,    16,    62,
      -1,    62,    14,    62,    -1,    62,    12,    62,    -1,    62,
      15,    62,    -1,    62,    13,    62,    -1,    19,    62,    -1,
      18,    62,    -1,    23,    62,    -1,    41,    35,     1,    37,
      -1,    41,    35,    37,    -1,    41,    35,    63,    37,    -1,
      41,    -1,    42,    -1,    40,    -1,    43,    -1,    35,    62,
      37,    -1,    35,     1,    37,    -1,    63,     4,    62,    -1,
      62,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    54,    54,    55,    56,    57,    58,    59,    61,    63,
      64,    69,    70,    71,    72,    75,    78,    81,    82,    86,
      87,    91,    92,    96,    97,   100,   101,   102,   103,   104,
     107,   108,   111,   112,   126,   127,   128,   129,   130,   131,
     134,   136,   137,   141,   142,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   178,   179
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LOW", "COMMA", "ASSIGN", "ELSE",
  "BITWISEOR", "BITWISEXOR", "BITWISEAND", "OR", "AND", "GE", "GT", "LE",
  "LT", "NE", "EQ", "MINUS", "PLUS", "MOD", "DIV", "MUL", "NOT", "HIGH",
  "LOWER", "HIGHER", "CHAR", "INT", "SHORT", "DOUBLE", "RETURN", "VOID",
  "SEMI", "LBRACE", "LPAR", "RBRACE", "RPAR", "WHILE", "IF", "CHRLITS",
  "IDENTIFIER", "NATURAL", "DECIMAL", "RESERVED", "$accept",
  "FunctionsAndDeclarations", "FunctionDefinition", "FunctionBody",
  "DeclarationsAndStatements", "FunctionDeclaration", "FunctionDeclarator",
  "ParameterList", "ParameterDeclaration", "Declaration", "ZEROPLUS1",
  "TypeSpec", "Declarator", "Statement", "ErrorRule", "OPTIONAL4",
  "ZEROPLUS2", "Expr", "ZEROPLUS3", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    46,    47,    48,
      48,    49,    49,    49,    49,    50,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     3,     2,
       3,     2,     2,     1,     1,     3,     4,     3,     1,     2,
       1,     4,     1,     3,     0,     1,     1,     1,     1,     1,
       3,     1,     2,     3,     3,     7,     5,     5,     3,     2,
       2,     1,     0,     2,     0,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     4,     3,     4,     1,
       1,     1,     1,     3,     3,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    25,    26,    28,    29,    27,     0,     5,     6,
       7,     0,    22,    40,     1,     2,     3,     4,    31,     0,
      24,     0,     0,    15,     0,     8,     0,     0,     0,     0,
       0,    71,    69,    70,    72,    30,     0,    18,    20,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,    41,
       0,    21,    64,    63,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    19,    39,
       0,     0,    42,     0,     0,    10,    12,    31,    11,    32,
      23,    74,    73,     0,    67,    76,     0,    46,    45,    55,
      56,    54,    52,    53,    60,    62,    59,    61,    58,    57,
      48,    47,    51,    50,    49,    17,    38,    34,    33,    43,
       0,     0,    66,     0,    68,    42,    42,    75,    37,    36,
      42,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,    25,    44,     9,    19,    36,    37,    45,
      26,    46,    20,    47,    12,    48,    82,    49,    96
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
     112,   -28,   -71,   -71,   -71,   -71,   -71,    77,   -71,   -71,
     -71,   -30,   -71,   -71,   -71,   -71,   -71,   -71,    22,    48,
     -71,   380,   -13,   -71,    57,   -71,     0,   380,   380,   380,
     201,   -71,   -11,   -71,   -71,   438,    -3,   -71,   -15,   367,
     165,   -71,    66,    68,    47,    93,    67,   129,    81,   420,
      67,   -71,   -71,   -71,   -71,    73,   241,   174,   380,   380,
     380,   380,   380,   380,   380,   380,   380,   380,   380,   380,
     380,   380,   380,   380,   380,   380,   -13,   -71,   -71,   -71,
     334,    79,   339,   380,   380,   -71,   -71,   113,   -71,   -71,
     -71,   -71,   -71,    80,   -71,   438,    -2,   438,   438,   453,
     467,   480,    52,    52,    10,    10,    10,    10,    10,    10,
       1,     1,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     272,   303,   -71,   380,   -71,   353,   353,   438,   -71,   131,
     353,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -71,   -71,   136,   -71,    14,   138,   -71,   -71,    43,    13,
     -71,     3,    88,   -70,   106,   -71,   -71,   -21,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -45
static const yytype_int16 yytable[] =
{
      35,    76,   123,    11,    50,    13,    52,    53,    54,    56,
      11,    18,   119,    10,     2,     3,     4,     5,    80,     6,
      17,    73,    74,    75,    57,    38,    78,    21,    71,    72,
      73,    74,    75,    51,    77,   124,    95,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   128,   129,    22,     1,    86,
     131,    88,   120,   121,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    27,    28,    14,     1,    38,
      29,    23,    24,    85,     2,     3,     4,     5,    39,     6,
     -42,    40,    30,    41,     1,    42,    43,    31,    32,    33,
      34,    83,   127,    84,     2,     3,     4,     5,    87,     6,
      91,    27,    28,     1,    89,   117,    29,   122,    21,   115,
       2,     3,     4,     5,    39,     6,   -42,    40,    30,   -14,
       1,    42,    43,    31,    32,    33,    34,   130,    90,     2,
       3,     4,     5,    15,     6,    16,    81,    27,    28,     0,
       0,     0,    29,     0,     0,     0,     2,     3,     4,     5,
      39,     6,   -42,    40,    30,   -13,     1,    42,    43,    31,
      32,    33,    34,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,   -44,   -44,     0,     0,     0,   -44,     0,
       0,     0,    27,    28,     0,     0,   -44,    29,   -44,   -44,
     -44,   -44,    55,   -44,   -44,   -44,   -44,   -44,   -44,    30,
       0,    94,     0,     0,    31,    32,    33,    34,     0,    27,
      28,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,    31,    32,    33,    34,    58,    59,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    92,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,   125,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    58,    59,
     126,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    27,    28,     0,
       0,     0,    29,     0,     0,     0,     0,   116,     0,     0,
      39,    27,    28,    40,    30,   118,    29,    42,    43,    31,
      32,    33,    34,     0,    39,    27,    28,    40,    30,     0,
      29,    42,    43,    31,    32,    33,    34,     0,    27,    28,
      79,     0,    30,    29,     0,     0,     0,    31,    32,    33,
      34,     0,     0,     0,     0,    30,     0,     0,     0,     0,
      31,    32,    33,    34,    58,    59,     0,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    59,     0,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75
};

static const yytype_int16 yycheck[] =
{
      21,     4,     4,     0,     4,    33,    27,    28,    29,    30,
       7,    41,    82,     0,    27,    28,    29,    30,    39,    32,
       7,    20,    21,    22,    35,    22,    41,     5,    18,    19,
      20,    21,    22,    33,    37,    37,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,   125,   126,    35,     1,    45,
     130,    47,    83,    84,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    18,    19,     0,     1,    76,
      23,    33,    34,    36,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,     1,    38,    39,    40,    41,    42,
      43,    35,   123,    35,    27,    28,    29,    30,    41,    32,
      37,    18,    19,     1,    33,    36,    23,    37,     5,    76,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
       1,    38,    39,    40,    41,    42,    43,     6,    50,    27,
      28,    29,    30,     7,    32,     7,    40,    18,    19,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,     1,    38,    39,    40,
      41,    42,    43,    -1,    -1,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    23,    -1,
      -1,    -1,    18,    19,    -1,    -1,    31,    23,    33,    34,
      35,    36,     1,    38,    39,    40,    41,    42,    43,    35,
      -1,    37,    -1,    -1,    40,    41,    42,    43,    -1,    18,
      19,    -1,    -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    37,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,    37,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
      37,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    18,    19,    -1,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      31,    18,    19,    34,    35,    36,    23,    38,    39,    40,
      41,    42,    43,    -1,    31,    18,    19,    34,    35,    -1,
      23,    38,    39,    40,    41,    42,    43,    -1,    18,    19,
      33,    -1,    35,    23,    -1,    -1,    -1,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      40,    41,    42,    43,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    27,    28,    29,    30,    32,    46,    47,    50,
      54,    56,    59,    33,     0,    47,    50,    54,    41,    51,
      57,     5,    35,    33,    34,    48,    55,    18,    19,    23,
      35,    40,    41,    42,    43,    62,    52,    53,    56,    31,
      34,    36,    38,    39,    49,    54,    56,    58,    60,    62,
       4,    33,    62,    62,    62,     1,    62,    35,     4,     5,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,     4,    37,    41,    33,
      62,    59,    61,    35,    35,    36,    49,    41,    49,    33,
      57,    37,    37,     1,    37,    62,    63,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    53,    33,    36,    36,    58,
      62,    62,    37,     4,    37,    37,    37,    62,    58,    58,
       6,    58
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

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
#line 54 "uccompiler.y"
    {(yyval.root) = (yyvsp[(1) - (2)].root); addchild((yyval.root),(yyvsp[(2) - (2)].root));}
    break;

  case 3:
#line 55 "uccompiler.y"
    {(yyval.root) = (yyvsp[(1) - (2)].root); addchild((yyval.root),(yyvsp[(2) - (2)].root));}
    break;

  case 4:
#line 56 "uccompiler.y"
    {(yyval.root) = (yyvsp[(1) - (2)].root); addchildren((yyval.root),(yyvsp[(2) - (2)].root_list));}
    break;

  case 5:
#line 57 "uccompiler.y"
    {(yyval.root) = program = newnode(Program,NULL); addchild((yyval.root),(yyvsp[(1) - (1)].root));}
    break;

  case 6:
#line 58 "uccompiler.y"
    {(yyval.root) = program = newnode(Program,NULL); addchild((yyval.root),(yyvsp[(1) - (1)].root));}
    break;

  case 7:
#line 59 "uccompiler.y"
    {(yyval.root) = program = newnode(Program,NULL); addchildren((yyval.root),(yyvsp[(1) - (1)].root_list));}
    break;

  case 8:
#line 61 "uccompiler.y"
    {(yyval.root) = newnode(FuncDefinition,NULL); addchild((yyval.root),(yyvsp[(1) - (3)].root)); addchildren((yyval.root),(yyvsp[(2) - (3)].root_list)); addchild((yyval.root),(yyvsp[(3) - (3)].root));}
    break;

  case 9:
#line 63 "uccompiler.y"
    {(yyval.root) = newnode(FuncBody,NULL); addchild((yyval.root),newnode(Null,NULL));}
    break;

  case 10:
#line 64 "uccompiler.y"
    {(yyval.root) = newnode(FuncBody,NULL); addchildren((yyval.root),(yyvsp[(2) - (3)].root_list));}
    break;

  case 11:
#line 69 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (2)].root_list); addnephews((yyval.root_list),(yyvsp[(2) - (2)].root_list));}
    break;

  case 12:
#line 70 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (2)].root_list); addnephews((yyval.root_list),(yyvsp[(2) - (2)].root_list));}
    break;

  case 13:
#line 71 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (1)].root_list);}
    break;

  case 14:
#line 72 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (1)].root_list);}
    break;

  case 15:
#line 75 "uccompiler.y"
    {(yyval.root) = newnode(FuncDeclaration,NULL); addchild((yyval.root),(yyvsp[(1) - (3)].root)); addchildren((yyval.root),(yyvsp[(2) - (3)].root_list));}
    break;

  case 16:
#line 78 "uccompiler.y"
    {(yyval.root_list) = newlist(); addbrother((yyval.root_list),newnode(Identifier,(yyvsp[(1) - (4)].lexeme))); addbrother((yyval.root_list),(yyvsp[(3) - (4)].root));}
    break;

  case 17:
#line 81 "uccompiler.y"
    {(yyval.root) = (yyvsp[(1) - (3)].root); addchild((yyval.root),(yyvsp[(3) - (3)].root));}
    break;

  case 18:
#line 82 "uccompiler.y"
    {(yyval.root) = newnode(ParamList,NULL); addchild((yyval.root),(yyvsp[(1) - (1)].root));}
    break;

  case 19:
#line 86 "uccompiler.y"
    {(yyval.root) = newnode(ParamDeclaration,NULL); addchild((yyval.root),(yyvsp[(1) - (2)].root)); addchild((yyval.root),newnode(Identifier,(yyvsp[(2) - (2)].lexeme)));}
    break;

  case 20:
#line 87 "uccompiler.y"
    {(yyval.root) = newnode(ParamDeclaration,NULL); addchild((yyval.root),(yyvsp[(1) - (1)].root));}
    break;

  case 21:
#line 91 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(Declaration,NULL); addchild(temp,(yyvsp[(1) - (4)].root)); addchildren(temp,(yyvsp[(2) - (4)].root_list)); addbrother((yyval.root_list),temp); addnephews((yyval.root_list),(yyvsp[(3) - (4)].root_list)); }
    break;

  case 22:
#line 92 "uccompiler.y"
    {;}
    break;

  case 23:
#line 96 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (3)].root_list); struct node *temp = newnode(Declaration,NULL); addchildren(temp,(yyvsp[(3) - (3)].root_list)); addbrother((yyval.root_list),temp);}
    break;

  case 24:
#line 97 "uccompiler.y"
    {(yyval.root_list) = newlist();}
    break;

  case 25:
#line 100 "uccompiler.y"
    {(yyval.root) = newnode(Char,NULL);}
    break;

  case 26:
#line 101 "uccompiler.y"
    {(yyval.root) = newnode(Int,NULL);}
    break;

  case 27:
#line 102 "uccompiler.y"
    {(yyval.root) = newnode(Void,NULL);}
    break;

  case 28:
#line 103 "uccompiler.y"
    {(yyval.root) = newnode(Short,NULL);}
    break;

  case 29:
#line 104 "uccompiler.y"
    {(yyval.root) = newnode(Double,NULL);}
    break;

  case 30:
#line 107 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(Identifier,(yyvsp[(1) - (3)].lexeme));addbrother((yyval.root_list),temp); addbrother((yyval.root_list),(yyvsp[(3) - (3)].root)); }
    break;

  case 31:
#line 108 "uccompiler.y"
    {(yyval.root_list) = newlist(); addbrother((yyval.root_list),newnode(Identifier,(yyvsp[(1) - (1)].lexeme)));}
    break;

  case 32:
#line 111 "uccompiler.y"
    {(yyval.root_list) = newlist(); addbrother((yyval.root_list),(yyvsp[(1) - (2)].root));}
    break;

  case 33:
#line 112 "uccompiler.y"
    { (yyval.root_list) = newlist(); 
                                     struct node_list *temp = newlist(); addnephews(temp,(yyvsp[(2) - (3)].root_list));
                                
                                    if(temp->counter >= 2)
                                    {
                                        struct node *statlist = newnode(StatList,NULL);
                                        addchildren(statlist,(yyvsp[(2) - (3)].root_list));
                                        addbrother((yyval.root_list),statlist);
                                    }
                                    else
                                    {
                                        addnephews((yyval.root_list),(yyvsp[(2) - (3)].root_list));
                                    }
                                    }
    break;

  case 34:
#line 126 "uccompiler.y"
    {;}
    break;

  case 35:
#line 127 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(If,NULL); addchild(temp,(yyvsp[(3) - (7)].root)); addchildren(temp,(yyvsp[(5) - (7)].root_list)); addchildren(temp,(yyvsp[(7) - (7)].root_list)); addbrother((yyval.root_list),temp);}
    break;

  case 36:
#line 128 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(If,NULL); addchild(temp,(yyvsp[(3) - (5)].root)); addchildren(temp,(yyvsp[(5) - (5)].root_list)); addbrother((yyval.root_list),temp);}
    break;

  case 37:
#line 129 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(While,NULL); addchild(temp,(yyvsp[(3) - (5)].root)); addchildren(temp,(yyvsp[(5) - (5)].root_list)); addbrother((yyval.root_list),temp);}
    break;

  case 38:
#line 130 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(Return,NULL); addchild(temp,(yyvsp[(2) - (3)].root)); addbrother((yyval.root_list),temp);}
    break;

  case 39:
#line 131 "uccompiler.y"
    {(yyval.root_list) = newlist(); struct node *temp = newnode(Return,NULL); addchild(temp,newnode(Null,NULL)); addbrother((yyval.root_list),temp);}
    break;

  case 40:
#line 134 "uccompiler.y"
    {;}
    break;

  case 41:
#line 136 "uccompiler.y"
    {(yyval.root) = (yyvsp[(1) - (1)].root);}
    break;

  case 42:
#line 137 "uccompiler.y"
    {;}
    break;

  case 43:
#line 141 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (2)].root_list); addnephews((yyval.root_list),(yyvsp[(2) - (2)].root_list));}
    break;

  case 44:
#line 142 "uccompiler.y"
    {(yyval.root_list) = newlist();}
    break;

  case 45:
#line 146 "uccompiler.y"
    {(yyval.root) = newnode(Store, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 46:
#line 147 "uccompiler.y"
    {(yyval.root) = newnode(Comma, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 47:
#line 148 "uccompiler.y"
    {(yyval.root) = newnode(Add, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 48:
#line 149 "uccompiler.y"
    {(yyval.root) = newnode(Sub, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 49:
#line 150 "uccompiler.y"
    {(yyval.root) = newnode(Mul, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 50:
#line 151 "uccompiler.y"
    {(yyval.root) = newnode(Div, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 51:
#line 152 "uccompiler.y"
    {(yyval.root) = newnode(Mod, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 52:
#line 153 "uccompiler.y"
    {(yyval.root) = newnode(Or, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 53:
#line 154 "uccompiler.y"
    {(yyval.root) = newnode(And, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 54:
#line 155 "uccompiler.y"
    {(yyval.root) = newnode(BitWiseAnd,NULL); addchild((yyval.root),(yyvsp[(1) - (3)].root)); addchild((yyval.root),(yyvsp[(3) - (3)].root));}
    break;

  case 55:
#line 156 "uccompiler.y"
    {(yyval.root) = newnode(BitWiseOr,NULL); addchild((yyval.root),(yyvsp[(1) - (3)].root)); addchild((yyval.root),(yyvsp[(3) - (3)].root));}
    break;

  case 56:
#line 157 "uccompiler.y"
    {(yyval.root) = newnode(BitWiseXor, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 57:
#line 158 "uccompiler.y"
    {(yyval.root) = newnode(Eq, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 58:
#line 159 "uccompiler.y"
    {(yyval.root) = newnode(Ne, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 59:
#line 160 "uccompiler.y"
    {(yyval.root) = newnode(Le, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 60:
#line 161 "uccompiler.y"
    {(yyval.root) = newnode(Ge, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 61:
#line 162 "uccompiler.y"
    {(yyval.root) = newnode(Lt, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 62:
#line 163 "uccompiler.y"
    {(yyval.root) = newnode(Gt, NULL); addchild((yyval.root), (yyvsp[(1) - (3)].root)); addchild((yyval.root), (yyvsp[(3) - (3)].root));}
    break;

  case 63:
#line 164 "uccompiler.y"
    {(yyval.root) = newnode(Plus,NULL); addchild((yyval.root),(yyvsp[(2) - (2)].root));}
    break;

  case 64:
#line 165 "uccompiler.y"
    {(yyval.root) = newnode(Minus,NULL); addchild((yyval.root),(yyvsp[(2) - (2)].root));}
    break;

  case 65:
#line 166 "uccompiler.y"
    {(yyval.root) = newnode(Not,NULL); addchild((yyval.root),(yyvsp[(2) - (2)].root));}
    break;

  case 66:
#line 167 "uccompiler.y"
    {;}
    break;

  case 67:
#line 168 "uccompiler.y"
    {;}
    break;

  case 68:
#line 169 "uccompiler.y"
    {(yyval.root) = newnode(Call,NULL); addchild((yyval.root),newnode(Identifier,(yyvsp[(1) - (4)].lexeme))); addchildren((yyval.root),(yyvsp[(3) - (4)].root_list));}
    break;

  case 69:
#line 170 "uccompiler.y"
    {(yyval.root) = newnode(Identifier,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 70:
#line 171 "uccompiler.y"
    {(yyval.root) = newnode(Natural,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 71:
#line 172 "uccompiler.y"
    {(yyval.root) = newnode(ChrLit,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 72:
#line 173 "uccompiler.y"
    {(yyval.root) = newnode(Decimal,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 73:
#line 174 "uccompiler.y"
    {(yyval.root) = (yyvsp[(2) - (3)].root);}
    break;

  case 74:
#line 175 "uccompiler.y"
    {;}
    break;

  case 75:
#line 178 "uccompiler.y"
    {(yyval.root_list) = (yyvsp[(1) - (3)].root_list); addbrother((yyval.root_list),(yyvsp[(3) - (3)].root));}
    break;

  case 76:
#line 179 "uccompiler.y"
    {(yyval.root_list) = newlist(); addbrother((yyval.root_list),(yyvsp[(1) - (1)].root));}
    break;


/* Line 1267 of yacc.c.  */
#line 2001 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 188 "uccompiler.y"

void yyerror(char *error) 
{
    printf("Line %d, column %d: %s: %s\n",syn_line,syn_column,error,yytext);
    
    error_flag = 0;
    //if(program != NULL) cleanup(program);

                    //PROGRAM
                    //DECLARATION DECLARATION
                    //INT ++

    //show(program,0);
   
}
/* START subroutines section */

// all needed functions are collected in the .l and ast.* files

