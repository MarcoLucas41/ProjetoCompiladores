
%{
#include "ast.h"
extern int yylex(void);
extern char *yytext;
extern int yyleng;
extern int line;
extern int column;
extern int type2;
void yyerror(char *);
//int yydebug=1;

%}

%left LOW
%left COMMA
%right ASSIGN
%right ELSE
%left BITWISEOR 
%left BITWISEXOR 
%left BITWISEAND
%left AND OR
%left EQ NE LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left HIGH

%nonassoc LOWER
%nonassoc HIGHER

%token CHAR INT SHORT DOUBLE RETURN VOID SEMI LBRACE LPAR RBRACE RPAR WHILE IF COMMA ASSIGN ELSE BITWISEOR BITWISEXOR BITWISEAND AND OR EQ NE LT LE GT GE PLUS MINUS MUL DIV MOD NOT
%token<lexeme> CHRLITS IDENTIFIER NATURAL DECIMAL RESERVED
%type<node> FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration TypeSpec Declarator Statement Expr ZEROPLUS1 ZEROPLUS2 ZEROPLUS3 OPTIONAL4 ErrorRule 



%union{ 
    char *lexeme;
    struct node *node;
}

/* START grammar rules section -- BNF grammar */

%%
FunctionsAndDeclarations: FunctionsAndDeclarations FunctionDefinition {;}
                        | FunctionsAndDeclarations FunctionDeclaration {;}
                        | FunctionsAndDeclarations Declaration {;}
                        | FunctionDefinition {;}
                        | FunctionDeclaration {;}
                        | Declaration {;}                          
                        ;       
FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {;}

FunctionBody: LBRACE RBRACE {;}
            | LBRACE DeclarationsAndStatements RBRACE {;}
            ;



DeclarationsAndStatements: Statement DeclarationsAndStatements {;}
                         | Declaration DeclarationsAndStatements {;}
                         | Statement {;}
                         | Declaration {;}
                         ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {;}  
                        

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {;}
                                        

ParameterList: ParameterList COMMA ParameterDeclaration {;}
             | ParameterDeclaration {;}
             ;


ParameterDeclaration: TypeSpec IDENTIFIER {;}
                    | TypeSpec {;}
                    ;


Declaration: TypeSpec Declarator ZEROPLUS1 SEMI {;}
           | ErrorRule {;}
           ;


ZEROPLUS1: ZEROPLUS1 COMMA Declarator {;}
         | {;}
         ;

TypeSpec: CHAR                          {;} 
        | INT                           {;}
        | VOID                          {;}
        | SHORT                         {;}
        | DOUBLE                        {;}
        ;

Declarator: IDENTIFIER ASSIGN Expr {;}
          | IDENTIFIER {;}
          ;

Statement: OPTIONAL4 SEMI {;}
         | LBRACE ZEROPLUS2 RBRACE {;}
         | LBRACE ErrorRule RBRACE {;}
         | IF LPAR Expr RPAR Statement ELSE Statement %prec LOW {;}
         | IF LPAR Expr RPAR Statement %prec LOW {;}
         | WHILE LPAR Expr RPAR Statement {;}
         | RETURN Expr SEMI {;}
         | RETURN SEMI {;}
         ;

ErrorRule: error SEMI {;}

OPTIONAL4: Expr {;}
         | {;}
         ;


ZEROPLUS2: ZEROPLUS2 Statement {;}
         | {;}
         ;


Expr: Expr ASSIGN Expr          {;}
    | Expr COMMA Expr           {;}
    | Expr PLUS Expr            {;}
    | Expr MINUS Expr           {;}
    | Expr MUL Expr             {;}
    | Expr DIV Expr             {;}
    | Expr MOD Expr             {;}
    | Expr OR Expr              {;}
    | Expr AND Expr             {;}
    | Expr BITWISEAND Expr      {;}
    | Expr BITWISEOR Expr       {;}
    | Expr BITWISEXOR Expr      {;}
    | Expr EQ Expr              {;}
    | Expr NE Expr              {;}
    | Expr LE Expr              {;}
    | Expr GE Expr              {;}
    | Expr LT Expr              {;}
    | Expr GT Expr              {;}
    | PLUS Expr    %prec NOT    {;}
    | MINUS Expr   %prec NOT    {;}
    | NOT Expr                   {;}
    | IDENTIFIER LPAR error RPAR {;}
    | IDENTIFIER LPAR RPAR {;}
    | IDENTIFIER LPAR ZEROPLUS3 RPAR {;}
    | IDENTIFIER                {;}
    | NATURAL                   {;}
    | CHRLITS                   {;}
    | DECIMAL                   {;}
    | LPAR Expr RPAR            {;}
    | LPAR error RPAR           {;}
    ;

ZEROPLUS3: ZEROPLUS3 COMMA Expr %prec HIGHER {;}
         | Expr %prec LOWER {;}
         ;

//if: n há problemas de associatividade
//else: é necessário associar a um IF

//NULL: #include <stdio.h>

%%
void yyerror(char *error) 
{
    if(yyleng > 1)
    {
        column -= yyleng - 1;
    }
    printf("Line %d, column %d: %s: %s\n",line,column,error,yytext);
    type2 = 0;
    if(program != NULL) cleanup(program);
   
}
/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
