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
     CHAR = 258,
     ELSE = 259,
     WHILE = 260,
     IF = 261,
     INT = 262,
     SHORT = 263,
     DOUBLE = 264,
     RETURN = 265,
     VOID = 266,
     BITWISEAND = 267,
     BITWISEOR = 268,
     BITWISEXOR = 269,
     AND = 270,
     ASSIGN = 271,
     MUL = 272,
     COMMA = 273,
     EQ = 274,
     GE = 275,
     GT = 276,
     DIV = 277,
     LBRACE = 278,
     LE = 279,
     LPAR = 280,
     LT = 281,
     MINUS = 282,
     MOD = 283,
     NE = 284,
     NOT = 285,
     OR = 286,
     PLUS = 287,
     RBRACE = 288,
     RPAR = 289,
     SEMI = 290,
     CHRLITS = 291,
     IDENTIFIER = 292,
     NATURAL = 293,
     DECIMAL = 294,
     LOW = 295
   };
#endif
/* Tokens.  */
#define CHAR 258
#define ELSE 259
#define WHILE 260
#define IF 261
#define INT 262
#define SHORT 263
#define DOUBLE 264
#define RETURN 265
#define VOID 266
#define BITWISEAND 267
#define BITWISEOR 268
#define BITWISEXOR 269
#define AND 270
#define ASSIGN 271
#define MUL 272
#define COMMA 273
#define EQ 274
#define GE 275
#define GT 276
#define DIV 277
#define LBRACE 278
#define LE 279
#define LPAR 280
#define LT 281
#define MINUS 282
#define MOD 283
#define NE 284
#define NOT 285
#define OR 286
#define PLUS 287
#define RBRACE 288
#define RPAR 289
#define SEMI 290
#define CHRLITS 291
#define IDENTIFIER 292
#define NATURAL 293
#define DECIMAL 294
#define LOW 295




/* Copy the first part of user declarations.  */
#line 2 "uccompiler.y"


#include "ast.h"
extern int yylex(void);
extern char *yytext;
extern int line;
extern int column;
void yyerror(char *);
int yydebug=1;



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
#line 23 "uccompiler.y"
{ 
    char *lexeme;
    struct node *node;
}
/* Line 193 of yacc.c.  */
#line 193 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 206 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   445

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    12,    14,    16,    18,    22,
      26,    28,    29,    32,    35,    37,    39,    43,    44,    49,
      50,    54,    56,    59,    60,    62,    63,    68,    71,    75,
      76,    78,    80,    82,    84,    86,    89,    90,    93,    94,
      97,   100,   104,   108,   115,   121,   127,   131,   133,   134,
     137,   138,   141,   142,   146,   150,   154,   158,   162,   166,
     170,   174,   178,   182,   186,   190,   194,   198,   202,   206,
     210,   214,   217,   220,   223,   228,   233,   235,   237,   239,
     241,   245,   249,   251,   252,   256
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    42,    43,    -1,    42,    47,    -1,    42,
      55,    -1,    43,    -1,    47,    -1,    52,    -1,    54,    48,
      44,    -1,    23,    45,    33,    -1,    46,    -1,    -1,    57,
      46,    -1,    52,    46,    -1,    57,    -1,    52,    -1,    54,
      48,    35,    -1,    -1,    37,    25,    49,    34,    -1,    -1,
      49,    18,    50,    -1,    50,    -1,    54,    51,    -1,    -1,
      37,    -1,    -1,    54,    55,    53,    35,    -1,     1,    35,
      -1,    53,    18,    55,    -1,    -1,     3,    -1,     7,    -1,
      11,    -1,     8,    -1,     9,    -1,    37,    56,    -1,    -1,
      16,    61,    -1,    -1,    58,    35,    -1,     1,    35,    -1,
      23,    60,    33,    -1,    23,     1,    33,    -1,     6,    25,
      61,    34,    57,    59,    -1,     6,    25,    61,    34,    57,
      -1,     5,    25,    61,    34,    57,    -1,    10,    58,    35,
      -1,    61,    -1,    -1,     4,    57,    -1,    -1,    60,    57,
      -1,    -1,    61,    16,    61,    -1,    61,    18,    61,    -1,
      61,    32,    61,    -1,    61,    27,    61,    -1,    61,    17,
      61,    -1,    61,    22,    61,    -1,    61,    28,    61,    -1,
      61,    31,    61,    -1,    61,    15,    61,    -1,    61,    12,
      61,    -1,    61,    13,    61,    -1,    61,    14,    61,    -1,
      61,    19,    61,    -1,    61,    29,    61,    -1,    61,    24,
      61,    -1,    61,    20,    61,    -1,    61,    26,    61,    -1,
      61,    21,    61,    -1,    32,    61,    -1,    27,    61,    -1,
      30,    61,    -1,    37,    25,     1,    34,    -1,    37,    25,
      62,    34,    -1,    37,    -1,    38,    -1,    36,    -1,    39,
      -1,    25,    61,    34,    -1,    25,     1,    34,    -1,    63,
      -1,    -1,    63,    18,    61,    -1,    61,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    31,    31,    32,    33,    34,    35,    36,    38,    40,
      42,    43,    46,    47,    48,    49,    52,    53,    55,    56,
      58,    59,    65,    66,    68,    69,    71,    72,    75,    76,
      78,    79,    80,    81,    82,    85,    86,    88,    89,    91,
      92,    93,    94,    95,    96,    97,    98,   101,   102,   104,
     105,   107,   108,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   142,   143,   145,   146
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "WHILE", "IF", "INT",
  "SHORT", "DOUBLE", "RETURN", "VOID", "BITWISEAND", "BITWISEOR",
  "BITWISEXOR", "AND", "ASSIGN", "MUL", "COMMA", "EQ", "GE", "GT", "DIV",
  "LBRACE", "LE", "LPAR", "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS",
  "RBRACE", "RPAR", "SEMI", "CHRLITS", "IDENTIFIER", "NATURAL", "DECIMAL",
  "LOW", "$accept", "FunctionsAndDeclarations", "FunctionDefinition",
  "FunctionBody", "OPTIONAL1", "DeclarationsAndStatements",
  "FunctionDeclaration", "FunctionDeclarator", "ParameterList",
  "ParameterDeclaration", "OPTIONAL2", "Declaration", "ZEROPLUS1",
  "TypeSpec", "Declarator", "OPTIONAL3", "Statement", "OPTIONAL4",
  "OPTIONAL5", "ZEROPLUS2", "Expr", "OPTIONAL6", "ZEROPLUS3", 0
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
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    42,    42,    42,    42,    42,    43,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    48,    48,
      49,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    62,    62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     1,     1,     3,     3,
       1,     0,     2,     2,     1,     1,     3,     0,     4,     0,
       3,     1,     2,     0,     1,     0,     4,     2,     3,     0,
       1,     1,     1,     1,     1,     2,     0,     2,     0,     2,
       2,     3,     3,     6,     5,     5,     3,     1,     0,     2,
       0,     2,     0,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     4,     4,     1,     1,     1,     1,
       3,     3,     1,     0,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    30,    31,    33,    34,    32,     0,     5,     6,
       7,    19,    27,     1,    38,     2,     3,    19,     4,    38,
       0,    29,     0,    35,     0,    23,     0,    16,     8,     0,
       0,     0,     0,     0,    78,    76,    77,    79,    37,     0,
      21,    25,     0,     0,     0,    48,     0,     0,    10,     0,
      36,     0,     0,    47,    36,    26,     0,     0,    72,    73,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    18,    24,    22,    27,     0,     0,     0,     0,     0,
       9,    13,    12,    39,    28,    81,    80,     0,    85,     0,
      82,    62,    63,    64,    61,    53,    57,    54,    65,    68,
      70,    58,    67,    69,    56,    59,    66,    60,    55,    20,
       0,     0,    46,    42,     0,    41,    51,    74,    75,     0,
       0,     0,    40,    84,    45,    44,     0,    43,    49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,    28,    47,    48,     9,    20,    39,    40,
      83,    49,    29,    50,    21,    23,    51,    52,   137,    89,
      53,    99,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -72
static const yytype_int16 yypact[] =
{
      25,   -31,   -72,   -72,   -72,   -72,   -72,   265,   -72,   -72,
     -72,   -17,   -72,   -72,    -3,   -72,   -72,   -13,   -72,    -9,
     -20,   -72,   406,   -72,    -8,    75,    65,   -72,   -72,   -16,
     199,   406,   406,   406,   -72,     2,   -72,   -72,   360,   -12,
     -72,    -6,     0,     4,    12,   406,   183,    34,   -72,   105,
       1,   144,    23,   360,     1,   -72,    35,   291,   381,   360,
     381,   160,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
      75,   -72,   -72,   -72,   -72,   406,   406,    42,    46,   222,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,    47,   360,    53,
      62,   360,   360,   360,   360,   360,   401,   360,   360,   360,
     360,   401,   360,   360,   381,   360,   360,   360,   381,   -72,
     314,   337,   -72,   -72,    54,   -72,   -72,   -72,   -72,   406,
     261,   261,   -72,   360,   -72,    87,   261,   -72,   -72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,    86,   -72,   -72,   -28,    89,   -72,   -72,    14,
     -72,    99,   -72,     5,     7,   -72,   -71,    60,   -72,   -72,
     -22,   -72,   -72
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      38,   -36,    54,    26,    12,    11,    80,    22,    57,    58,
      59,    60,    17,    22,    18,    27,    25,    25,   126,    55,
      19,    91,    81,    92,    24,   -17,     1,    61,     2,    85,
      41,    82,     3,     4,     5,    84,     6,    86,    14,    98,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,    93,   134,
     135,    94,   -17,   120,   121,   138,    42,    90,     2,    95,
      43,    44,     3,     4,     5,    45,     6,   122,     2,   123,
     129,   127,     3,     4,     5,    41,     6,   128,    46,   132,
      30,   136,    31,    15,   119,    32,    16,    33,   -11,    10,
     -48,    34,    35,    36,    37,    87,    42,   133,     2,     0,
      43,    44,     3,     4,     5,    45,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    46,     0,
      30,     0,    31,     0,     0,    32,     0,    33,   -15,     0,
     -48,    34,    35,    36,    37,    42,     0,     2,     0,    43,
      44,     3,     4,     5,    45,     6,     0,     0,     0,     0,
       0,    97,     0,     0,     0,     0,     0,    46,     0,    30,
       0,    31,     0,     0,    32,     0,    33,   -14,     0,   -48,
      34,    35,    36,    37,    88,    30,     0,    31,   -52,   -52,
      32,     0,    33,   -52,   -83,     0,    34,    35,    36,    37,
      56,     0,     0,     0,     0,     0,   -52,     0,   -52,     0,
     -52,     0,     0,   -52,     0,   -52,   -52,     0,   -52,   -52,
     -52,   -52,   -52,   124,    30,     0,    31,    43,    44,    32,
       0,    33,    45,     0,     0,    34,    35,    36,    37,     0,
       0,     0,     0,     0,     0,    46,     0,    30,     0,    31,
       0,     0,    32,     0,    33,   125,     0,   -48,    34,    35,
      36,    37,   124,     0,     0,    13,    43,    44,     2,     0,
       0,    45,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     0,     0,    46,     0,    30,     0,    31,     0,
       0,    32,     0,    33,     0,     0,   -48,    34,    35,    36,
      37,     0,    14,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,    73,     0,    74,    75,    76,
      77,     0,    78,    79,     0,    96,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,    73,     0,
      74,    75,    76,    77,     0,    78,    79,     0,   130,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,    73,     0,    74,    75,    76,    77,     0,    78,    79,
       0,   131,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,    73,     0,    74,    75,    76,    77,
       0,    78,    79,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,    73,     0,    74,     0,    76,
      77,     0,    78,    62,    63,    64,    65,    66,     0,    68,
      69,    70,    71,     0,     0,    73,     0,    74,     0,    76,
      77,    30,    78,    31,     0,     0,    32,     0,    33,     0,
       0,     0,    34,    35,    36,    37
};

static const yytype_int16 yycheck[] =
{
      22,    18,    18,    23,    35,     0,    18,    16,    30,    31,
      32,    33,     7,    16,     7,    35,    25,    25,    89,    35,
      37,    49,    34,    51,    37,     0,     1,    25,     3,    25,
      25,    37,     7,     8,     9,    35,    11,    25,    37,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    35,   130,
     131,    54,    37,    85,    86,   136,     1,    33,     3,    34,
       5,     6,     7,     8,     9,    10,    11,    35,     3,    33,
      18,    34,     7,     8,     9,    80,    11,    34,    23,    35,
      25,     4,    27,     7,    80,    30,     7,    32,    33,     0,
      35,    36,    37,    38,    39,    45,     1,   129,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,
      35,    36,    37,    38,    39,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,
      -1,    27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,
      36,    37,    38,    39,     1,    25,    -1,    27,     5,     6,
      30,    -1,    32,    10,    34,    -1,    36,    37,    38,    39,
       1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,
      27,    -1,    -1,    30,    -1,    32,    33,    -1,    35,    36,
      37,    38,    39,     1,    25,    -1,    27,     5,     6,    30,
      -1,    32,    10,    -1,    -1,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,
      -1,    -1,    30,    -1,    32,    33,    -1,    35,    36,    37,
      38,    39,     1,    -1,    -1,     0,     5,     6,     3,    -1,
      -1,    10,     7,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    23,    -1,    25,    -1,    27,    -1,
      -1,    30,    -1,    32,    -1,    -1,    35,    36,    37,    38,
      39,    -1,    37,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    27,    28,
      29,    -1,    31,    32,    -1,    34,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    27,    28,    29,    -1,    31,    32,    -1,    34,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      -1,    24,    -1,    26,    27,    28,    29,    -1,    31,    32,
      -1,    34,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    -1,    24,    -1,    26,    27,    28,    29,
      -1,    31,    32,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    -1,    28,
      29,    -1,    31,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    -1,    -1,    24,    -1,    26,    -1,    28,
      29,    25,    31,    27,    -1,    -1,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,    38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     7,     8,     9,    11,    42,    43,    47,
      52,    54,    35,     0,    37,    43,    47,    54,    55,    37,
      48,    55,    16,    56,    37,    25,    23,    35,    44,    53,
      25,    27,    30,    32,    36,    37,    38,    39,    61,    49,
      50,    54,     1,     5,     6,    10,    23,    45,    46,    52,
      54,    57,    58,    61,    18,    35,     1,    61,    61,    61,
      61,    25,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    24,    26,    27,    28,    29,    31,    32,
      18,    34,    37,    51,    35,    25,    25,    58,     1,    60,
      33,    46,    46,    35,    55,    34,    34,     1,    61,    62,
      63,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    50,
      61,    61,    35,    33,     1,    33,    57,    34,    34,    18,
      34,    34,    35,    61,    57,    57,     4,    59,    57
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
#line 31 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyval.node),(yyvsp[(1) - (2)].node));}
    break;

  case 3:
#line 32 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyval.node),(yyvsp[(1) - (2)].node));}
    break;

  case 4:
#line 33 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node); addchild((yyval.node),(yyvsp[(1) - (2)].node));}
    break;

  case 5:
#line 34 "uccompiler.y"
    {(yyval.node) = newnode(Program,NULL); addchild((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 6:
#line 35 "uccompiler.y"
    {(yyval.node) = newnode(Program,NULL); addchild((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 7:
#line 36 "uccompiler.y"
    {(yyval.node) = newnode(Program,NULL); addchild((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 8:
#line 38 "uccompiler.y"
    {(yyval.node) = newnode(FuncDefinition,NULL); addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(2) - (3)].node)); addchild((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 9:
#line 40 "uccompiler.y"
    {(yyval.node) = newnode(FuncBody,NULL); addchild((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 10:
#line 42 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 12:
#line 46 "uccompiler.y"
    {addchild((yyval.node),(yyvsp[(1) - (2)].node)); addchild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 13:
#line 47 "uccompiler.y"
    {addchild((yyval.node),(yyvsp[(1) - (2)].node)); addchild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 14:
#line 48 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 15:
#line 49 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 16:
#line 52 "uccompiler.y"
    {(yyval.node) = newnode(FuncDeclaration,NULL); addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 18:
#line 55 "uccompiler.y"
    {addchild((yyval.node),(yyvsp[(1) - (4)].lexeme)); addchild((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 20:
#line 58 "uccompiler.y"
    {addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 21:
#line 59 "uccompiler.y"
    {(yyval.node) = newnode(ParamList,NULL); addchild((yyval.node),(yyvsp[(1) - (1)].node));}
    break;

  case 22:
#line 65 "uccompiler.y"
    {(yyval.node) = newnode(ParamDeclaration,NULL); addchild((yyval.node),(yyvsp[(1) - (2)].node)); addchild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 24:
#line 68 "uccompiler.y"
    {(yyval.node)= newnode(Identifier,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 26:
#line 71 "uccompiler.y"
    {(yyval.node) = newnode(Declaration,NULL); addchild((yyval.node),(yyvsp[(1) - (4)].node)); addchild((yyval.node),(yyvsp[(2) - (4)].node)); addchild((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 28:
#line 75 "uccompiler.y"
    { addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 30:
#line 78 "uccompiler.y"
    {(yyval.node) = newnode(Char,NULL);}
    break;

  case 31:
#line 79 "uccompiler.y"
    {(yyval.node) = newnode(Int,NULL);}
    break;

  case 32:
#line 80 "uccompiler.y"
    {(yyval.node) = newnode(Void,NULL);}
    break;

  case 33:
#line 81 "uccompiler.y"
    {(yyval.node) = newnode(Short,NULL);}
    break;

  case 34:
#line 82 "uccompiler.y"
    {(yyval.node) = newnode(Double,NULL);}
    break;

  case 35:
#line 85 "uccompiler.y"
    {addchild((yyval.node),newnode(Identifier,(yyvsp[(1) - (2)].lexeme))); addchild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 37:
#line 88 "uccompiler.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 39:
#line 91 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (2)].node);}
    break;

  case 40:
#line 92 "uccompiler.y"
    {;}
    break;

  case 41:
#line 93 "uccompiler.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 42:
#line 94 "uccompiler.y"
    {;}
    break;

  case 43:
#line 95 "uccompiler.y"
    {(yyval.node) = newnode(If,NULL); addchild((yyval.node),(yyvsp[(3) - (6)].node)); addchild((yyval.node),(yyvsp[(5) - (6)].node)); addchild((yyval.node),(yyvsp[(6) - (6)].node));}
    break;

  case 44:
#line 96 "uccompiler.y"
    {(yyval.node) = newnode(If,NULL); addchild((yyval.node),(yyvsp[(3) - (5)].node)); addchild((yyval.node),(yyvsp[(5) - (5)].node));}
    break;

  case 45:
#line 97 "uccompiler.y"
    {(yyval.node) = newnode(While,NULL); addchild((yyval.node),(yyvsp[(3) - (5)].node)); addchild((yyval.node),(yyvsp[(5) - (5)].node));}
    break;

  case 46:
#line 98 "uccompiler.y"
    {(yyval.node) = newnode(Return,NULL); addchild((yyval.node),(yyvsp[(2) - (3)].node));}
    break;

  case 47:
#line 101 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 49:
#line 104 "uccompiler.y"
    {(yyval.node) = newnode(Else,NULL); addchild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 51:
#line 107 "uccompiler.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 53:
#line 111 "uccompiler.y"
    {(yyval.node) = newnode(Assign, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 54:
#line 112 "uccompiler.y"
    {(yyval.node) = newnode(Comma, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 55:
#line 113 "uccompiler.y"
    {(yyval.node) = newnode(Plus, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 56:
#line 114 "uccompiler.y"
    {(yyval.node) = newnode(Minus, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 57:
#line 115 "uccompiler.y"
    {(yyval.node) = newnode(Mul, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 58:
#line 116 "uccompiler.y"
    {(yyval.node) = newnode(Div, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 59:
#line 117 "uccompiler.y"
    {(yyval.node) = newnode(Mod, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 60:
#line 118 "uccompiler.y"
    {(yyval.node) = newnode(Or, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 61:
#line 119 "uccompiler.y"
    {(yyval.node) = newnode(And, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 62:
#line 120 "uccompiler.y"
    {(yyval.node) = newnode(BitWiseAnd,NULL); addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 63:
#line 121 "uccompiler.y"
    {(yyval.node) = newnode(BitWiseOr,NULL); addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 64:
#line 122 "uccompiler.y"
    {(yyval.node) = newnode(BitWiseXor, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 65:
#line 123 "uccompiler.y"
    {(yyval.node) = newnode(Eq, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 66:
#line 124 "uccompiler.y"
    {(yyval.node) = newnode(Ne, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 67:
#line 125 "uccompiler.y"
    {(yyval.node) = newnode(Le, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 68:
#line 126 "uccompiler.y"
    {(yyval.node) = newnode(Ge, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 69:
#line 127 "uccompiler.y"
    {(yyval.node) = newnode(Lt, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 70:
#line 128 "uccompiler.y"
    {(yyval.node) = newnode(Gt, NULL); addchild((yyval.node), (yyvsp[(1) - (3)].node)); addchild((yyval.node), (yyvsp[(3) - (3)].node));}
    break;

  case 71:
#line 129 "uccompiler.y"
    {(yyval.node) = newnode(PLUS, NULL);  addchild((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 72:
#line 130 "uccompiler.y"
    {(yyval.node) = newnode(Minus, NULL); addchild((yyval.node), (yyvsp[(2) - (2)].node));}
    break;

  case 73:
#line 131 "uccompiler.y"
    {(yyval.node) = newnode(Not,NULL); addchild((yyval.node),(yyvsp[(2) - (2)].node));}
    break;

  case 75:
#line 133 "uccompiler.y"
    {struct node *identifier = newnode(Identifier,(yyvsp[(1) - (4)].lexeme)); addchild((yyval.node),(yyvsp[(1) - (4)].lexeme)); addchild((yyval.node),(yyvsp[(3) - (4)].node));}
    break;

  case 76:
#line 134 "uccompiler.y"
    {(yyval.node) = newnode(Identifier,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 77:
#line 135 "uccompiler.y"
    {(yyval.node) = newnode(Natural,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 78:
#line 136 "uccompiler.y"
    {(yyval.node) = newnode(ChrLit,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 79:
#line 137 "uccompiler.y"
    {(yyval.node) = newnode(Decimal,(yyvsp[(1) - (1)].lexeme));}
    break;

  case 80:
#line 138 "uccompiler.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 82:
#line 142 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 84:
#line 145 "uccompiler.y"
    {addchild((yyval.node),(yyvsp[(1) - (3)].node)); addchild((yyval.node),(yyvsp[(3) - (3)].node));}
    break;

  case 85:
#line 146 "uccompiler.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;


/* Line 1267 of yacc.c.  */
#line 1935 "y.tab.c"
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


#line 153 "uccompiler.y"

void yyerror(char *error) {
    printf("Line %d, column %d: %s '%s'\n",line,column,error,yytext);
    cleanup(program);
}
/* START subroutines section */

// all needed functions are collected in the .l and ast.* files

