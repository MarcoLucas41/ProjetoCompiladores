/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 37 "uccompiler.y"
{ 
    char *lexeme;
    struct node *node;
}
/* Line 1529 of yacc.c.  */
#line 142 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

