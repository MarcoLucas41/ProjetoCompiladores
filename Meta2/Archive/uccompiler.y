
%{

#include "ast.h"
extern int yylex(void);
extern char *yytext;
extern int yyleng;
extern int line;
extern int column;
void yyerror(char *);
int yydebug=1;

%}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL EQ GE GT DIV LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI
%token<lexeme> CHRLITS IDENTIFIER NATURAL DECIMAL RESERVED
%type<node> Expr
%type<node> FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration TypeSpec Declarator Statement ZEROPLUS1 ZEROPLUS2 ZEROPLUS3 OPTIONAL4 OPTIONAL5 OPTIONAL6

%left LOW
%left PLUS MINUS
%left MUL DIV
%left COMMA

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




DeclarationsAndStatements: Statement DeclarationsAndStatements {;}
                         | Declaration DeclarationsAndStatements {;}
                         | Statement {; }
                         | Declaration {; }
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
           | error SEMI
           ;

ZEROPLUS1: ZEROPLUS1 COMMA Declarator {;}
         | ;

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
         | error SEMI {;}
         | LBRACE ZEROPLUS2 RBRACE {;}
         | LBRACE error RBRACE {;}
         | IF LPAR Expr RPAR Statement OPTIONAL5 %prec LOW {;}
         | IF LPAR Expr RPAR Statement %prec LOW {;}
         | WHILE LPAR Expr RPAR Statement {;}
         | RETURN OPTIONAL4 SEMI {;}
         ;

OPTIONAL4: Expr {;}
         | ;

OPTIONAL5: ELSE Statement {;}
         |
         ;

ZEROPLUS2: ZEROPLUS2 Statement {;}
         | ;


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
    | PLUS Expr                 {;}
    | MINUS Expr                {;}
    | NOT Expr                  {;}
    | IDENTIFIER LPAR error RPAR
    | IDENTIFIER LPAR OPTIONAL6 RPAR {;}
    | IDENTIFIER                {;}
    | NATURAL                   {;}
    | CHRLITS                    {;}
    | DECIMAL                   {;}
    | LPAR Expr RPAR            {;}
    | LPAR error RPAR 
    ;

OPTIONAL6: ZEROPLUS3  {;}
         | ;

ZEROPLUS3: ZEROPLUS3 COMMA Expr {;}
         | Expr {;}
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
    if(program != NULL) cleanup(program);
   
}
/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
