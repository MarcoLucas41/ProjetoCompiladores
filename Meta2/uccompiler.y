
%{

#include "ast.h"

void yyerror(char *);
//int yydebug=1;

%}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA EQ GE GT DIV LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI
%token<lexeme> RESERVED CHRLIT IDENTIFIER NATURAL DECIMAL
%type<node> FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration TypeSpec Declarator Statement Expr ZEROPLUS1 ZEROPLUS2 ZEROPLUS3 OPTIONAL1 OPTIONAL2 OPTIONAL3 OPTIONAL4 OPTIONAL5 OPTIONAL6

%left LOW
%left PLUS MINUS
%left MUL DIV

%union{
    char *lexeme;
    struct node *node;
}

/* START grammar rules section -- BNF grammar */

%%
FunctionsAndDeclarations: FunctionsAndDeclarations FunctionDefinition {$$ = $1; addchild($$,$1);}
                        | FunctionsAndDeclarations FunctionDeclaration {$$ = $1; addchild($$,$1);}
                        | FunctionsAndDeclarations Declarator {$$ = $1; addchild($$,$1);}
                        | FunctionDefinition {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionDeclaration {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | Declaration {$$ = newnode(Program,NULL); addchild($$,$1);}                          
                               
FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = newnode(FuncDefinition,NULL); addchild($$,$1); addchild($$,$2); addchild($$,$3);}

FunctionBody: LBRACE OPTIONAL1 RBRACE {$$ = newnode(FuncBody,NULL); addchild($$,$2);}

OPTIONAL1: DeclarationsAndStatements {$$ = $1;}
         | ;


DeclarationsAndStatements: Statement DeclarationsAndStatements {addchild($$,$1); addchild($$,$2);}
                         | Declaration DeclarationsAndStatements {addchild($$,$1); addchild($$,$2);}
                         | Statement {$$ = $1; }
                         | Declaration {$$ = $1; }
                         ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$ = newnode(FuncDeclaration,NULL); addchild($$,$1); addchild($$,$2);}  
                   | ;                       

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {$$ = newnode(FuncDeclarator,NULL); addchild($$,$1); addchild($$,$3);}
                  | ;                                    

ParameterList: ParameterList COMMA ParameterDeclaration {addchild($$,$1); addchild($$,$3);}
             | ParameterDeclaration {$$ = newnode(ParamList,NULL); addchild($$,$1);}
             ;


             

ParameterDeclaration: TypeSpec OPTIONAL2 {$$ = newnode(ParamDeclaration,NULL); addchild($$,$1); addchild($$,$2);}
                    | ;

OPTIONAL2: IDENTIFIER {$$= newnode(Identifier,$1);}
         | ;

Declaration: TypeSpec Declarator ZEROPLUS1 SEMI {$$ = newnode(Declaration,NULL); addchild($$,$1); addchild($$,$2);}
           | error SEMI
           ;

ZEROPLUS1: ZEROPLUS1 COMMA Declarator { addchild($$,$1); addchild($$,$3);}
         | ;

TypeSpec: CHAR                          {$$ = newnode(Char,NULL);} 
        | INT                           {$$ = newnode(Int,NULL);}
        | VOID                          {$$ = newnode(Void,NULL);}
        | SHORT                         {$$ = newnode(Short,NULL);}
        | DOUBLE                        {$$ = newnode(Double,NULL);}
        ;

Declarator: IDENTIFIER OPTIONAL3 {struct node *identifier = newnode(Identifier,$1); addchild($$,$1); addchild($$,$2);}
          ;

OPTIONAL3: ASSIGN Expr {$$ = $2;}
        | ;         

Statement: OPTIONAL4 SEMI {$$ = $1;}
         | error SEMI
         | LBRACE ZEROPLUS2 RBRACE {$$ = $2;}
         | LBRACE error RBRACE
         | IF LPAR Expr RPAR Statement OPTIONAL5 %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); addchild($$,$6);}
         | IF LPAR Expr RPAR Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5);}
         | WHILE LPAR Expr RPAR Statement {$$ = newnode(While,NULL); addchild($$,$3); addchild($$,$5);}
         | RETURN OPTIONAL4 SEMI {$$ = newnode(Return,NULL); addchild($$,$2);}
         ;

OPTIONAL4: Expr {$$ = $1;}
         | ;

OPTIONAL5: ELSE Statement {$$ = newnode(Else,NULL); addchild($$,$2);}
         | ;

ZEROPLUS2: ZEROPLUS2 Statement {$$ = $2;}
         | ;


Expr: Expr ASSIGN Expr          {$$ = newnode(Assign, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr COMMA Expr           {$$ = newnode(Comma, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr PLUS Expr            {$$ = newnode(Plus, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr MINUS Expr           {$$ = newnode(Minus, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr MUL Expr             {$$ = newnode(Mul, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr DIV Expr             {$$ = newnode(Div, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr MOD Expr             {$$ = newnode(Mod, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr OR Expr              {$$ = newnode(Or, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr AND Expr             {$$ = newnode(And, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr BITWISEAND Expr      {$$ = newnode(BitWiseAnd,NULL); addchild($$,$1); addchild($$,$3);}
    | Expr BITWISEOR Expr       {$$ = newnode(BitWiseOr,NULL); addchild($$,$1); addchild($$,$3);}
    | Expr BITWISEXOR Expr      {$$ = newnode(Bitwisexor, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr EQ Expr              {$$ = newnode(Eq, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr NE Expr              {$$ = newnode(Ne, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LE Expr              {$$ = newnode(Le, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GE Expr              {$$ = newnode(Ge, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LT Expr              {$$ = newnode(Lt, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GT Expr              {$$ = newnode(Gt, NULL); addchild($$, $1); addchild($$, $3);}
    | PLUS Expr                 {$$ = newnode(PLUS, NULL);  addchild($$, $2);}
    | MINUS Expr                {$$ = newnode(Minus, NULL); addchild($$, $2);}
    | NOT Expr                  {$$ = newnode(Not,NULL); addchild($$,$2);}
    | IDENTIFIER LPAR error RPAR
    | IDENTIFIER LPAR OPTIONAL6 RPAR {struct node *identifier = newnode(Identifier,$1); addchild($$,$1); addchild($$,$3);}
    | IDENTIFIER                {$$ = newnode(Identifier,$1);}
    | NATURAL                   {$$ = newnode(Natural,$1);}
    | CHRLIT                    {$$ = newnode(Chrlit,$1);}
    | DECIMAL                   {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR            {$$ = $2;}
    | LPAR error RPAR 
    ;

OPTIONAL6: ZEROPLUS3  {$$ = $1;}
         | ;

ZEROPLUS3: ZEROPLUS3 COMMA Expr {addchild($$,$1); addchild($$,$3);}
         | Expr {$$ = $1;}
         ;
//if: n há problemas de associatividade
//else: é necessário associar a um IF

//NULL: #include <stdio.h>

%%
void yyerror(char *error) {
    printf("Line %d, column %d: %s '%s'\n",line,column,error,yytext);
    cleanup(program);
}
/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
