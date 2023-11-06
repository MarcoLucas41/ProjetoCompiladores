
%{

#include "ast.h"

int yylex(void);
void yyerror(char *);
//int yydebug=1;

struct node *program;

%}

%token INTEGER DOUBLE IF THEN ELSE LBRACE RBRACE
%token<lexeme> RESERVED CHRLIT IDENTIFIER NATURAL DECIMAL
%type<node> FunctionsAndDeclarations FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration TypeSpec Declarator Statement Expr

%left LOW
%left PLUS MINUS
%left MUL DIV

%union{
    char *lexeme;
    struct node *node;
}

/* START grammar rules section -- BNF grammar */

%%
FunctionsAndDeclarations: FunctionDefinition                            {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionDeclaration                           {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | Declaration                                   {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionsAndDeclarations FunctionDefinition   {$$ = $1; addchild($$,$2);}
                        | FunctionsAndDeclarations FunctionDeclaration  {$$ = $1; addchild($$,$2);}
                        | FunctionsAndDeclarations Declaration          {$$ = $1; addchild($$,$2);}
                               
                    

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody            {$$ = newnode(FuncDefinition,NULL); addchild($$,$1); addchild($$,$2); addchild($$,$3);}

FunctionBody: LBRACE DeclarationsAndStatements RBRACE                   {$$ = newnode(FuncBody,NULL); addchild($$,$2);}
            | LBRACE RBRACE                                             {$$ = newnode(FuncBody,NULL);}


DeclarationsAndStatements: Statement DeclarationsAndStatements          {addchild($$,$1); addchild($$,$2);}
                         | Declaration DeclarationsAndStatements        {addchild($$,$1); addchild($$,$2);}
                         | Statement                                    {addchild($$,$1);}
                         | Declaration                                  {addchild($$,$1);}

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI                   {$$ = newnode(FuncDeclaration,NULL); addchild($$,$1); addchild($$,$2);}                         

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR                  {struct node *identifier = newnode(Identifier,$1); addchild($$,identifier); addchild($$,$3);}                         

ParameterList: ParameterDeclaration ParameterList0+                     {}
             | ParameterDeclaration                                     {}

ParameterList0+: COMMA ParameterDeclaration
               | ParameterList0+ COMMA ParemeterDeclaration

ParameterDeclaration: TypeSpec IDENTIFIER
                    | TypeSpec

Declaration: TypeSpec Declarator Declaration0+ SEMI
           | TypeSpec Declarator SEMI

Declaration0+: COMMA Declarator
             | Declaration0+ COMMA Declarator

TypeSpec: CHAR                          {$$ = newnode(Char,NULL);} 
        | INT                           {$$ = newnode(Int,NULL);}
        | VOID                          {$$ = newnode(Void,NULL);}
        | SHORT                         {$$ = newnode(Short,NULL);}
        | DOUBLE                        {$$ = newnode(Double,NULL);}

Declarator: IDENTIFIER ASSIGN Expr      {struct node *identifier = newnode(Identifier,$1); addchild($$,$1); addchild($$,$3);}
          | IDENTIFIER                  {struct node *identifier = newnode(Identifier,$1); addchild($$,$1);}

Statement: OPTIONAL SEMI                                        {$$ = $1;}
         | LBRACE ZEROPLUS RBRACE                               {$$ = $2;}
         | IF LPAR Expr RPAR Statement ELSE Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); addchild($$,$7);}
         | IF LPAR Expr RPAR Statement %prec LOW                {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5);}
         | WHILE LPAR Expr RPAR Statement                       {$$ = newnode(While,NULL); addchild($$,$3); addchild($$,$5);}
         | RETURN Expr SEMI                                     {$$ = newnode(Return,NULL); addchild($$,$2);}
         | RETURN SEMI                                          {$$ = newnode(Return,NULL); addchild($$,$2);}

OPTIONAL:  SEMI                                                 {;}
         | ;

ZEROPLUS: LBRACE RBRACE                                        {;}
         | Statement1+ Statement                                {$$ = $1;}
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
    | Expr BITWISEAND Expr      {$$ = newnode(BitWiseAnd,NULL); addchild($$,$1); addchild($$,$2);}
    | Expr BITWISEOR Expr       {$$ = newnode(BitWiseOr,NULL); addchild($$,$1); addchild($$,$2);}
    | Expr BITWISEXOR Expr      {$$ = newnode(Bitwisexor, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr EQ Expr              {$$ = newnode(Eq, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr NE Expr              {$$ = newnode(Ne, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LE Expr              {$$ = newnode(Le, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GE Expr              {$$ = newnode(Ge, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LT Expr              {$$ = newnode(Lt, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GT Expr              {$$ = newnode(Gt, NULL); addchild($$, $1); addchild($$, $3);}
    | PLUS Expr                 {$$ = newnode(PLUS, NULL); addchild($$, $1); addchild($$, $3);}
    | MINUS Expr                {$$ = newnode(Minus, NULL); addchild($$, $1);}
    | NOT Expr                  {$$ = newnode(Not,NULL); addchild($$,$1);}
    | IDENTIFIER LPAR RPAR      
    | IDENTIFIER LPAR Expr RPAR
    | IDENTIFIER LPAR Expr Expr0+ RPAR
    | IDENTIFIER                {$$ = newnode(Identifier,$1);}
    | NATURAL                   {$$ = newnode(Natural,$1);}
    | CHRLIT                    {$$ = newnode(Chrlit,$1);}
    | DECIMAL                   {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR            {$$ = $2;}

Expr0+: COMMA Expr
      | Expr0+ COMMA Expr

%%

/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
