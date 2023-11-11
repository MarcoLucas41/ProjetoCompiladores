
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
FunctionsAndDeclarations: FunctionsAndDeclarations FunctionDefinition {$$ = $1; addchild($$,$1);}
                        | FunctionsAndDeclarations FunctionDeclaration {$$ = $1; addchild($$,$1);}
                        | FunctionsAndDeclarations Declarator {$$ = $1; addchild($$,$1);}
                        | FunctionDefinition {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionDeclaration {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | Declaration {$$ = newnode(Program,NULL); addchild($$,$1);}                        
                        ;       
FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = newnode(FuncDefinition,NULL); addchild($$,$1); addchild($$,$2); addchild($$,$3);}

FunctionBody: LBRACE RBRACE {;}
            | LBRACE DeclarationsAndStatements RBRACE {$$ = newnode(FuncBody,NULL); addchild($$,$2);}
            ;



DeclarationsAndStatements: Statement DeclarationsAndStatements {;}
                         | Declaration DeclarationsAndStatements {;}
                         | Statement {$$ = $1;}
                         | Declaration {$$ = $1;}
                         ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {;}  
                        

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {;}
                                        

ParameterList: ParameterList COMMA ParameterDeclaration {;}
             | ParameterDeclaration {;}
             ;


ParameterDeclaration: TypeSpec IDENTIFIER {$$ = newnode(ParamDeclaration,NULL); addchild($$,$1); addchild($$,newnode(Identifier,$2));}
                    | TypeSpec {$$ = newnode(ParamDeclaration,NULL); addchild($$,$1);}
                    ;


Declaration: TypeSpec Declarator ZEROPLUS1 SEMI {$$ = newnode(Declaration,NULL); addchild($$,$1); addchild($$,$2); addchild($$,$3);}
           | ErrorRule {;}
           ;


ZEROPLUS1: ZEROPLUS1 COMMA Declarator {;}
         | {;}
         ;

TypeSpec: CHAR                          {$$ = newnode(Char,NULL);} 
        | INT                           {$$ = newnode(Int,NULL);}
        | VOID                          {$$ = newnode(Void,NULL);}
        | SHORT                         {$$ = newnode(Short,NULL);}
        | DOUBLE                        {$$ = newnode(Double,NULL);}
        ;

Declarator: IDENTIFIER ASSIGN Expr {;}
          | IDENTIFIER {;}
          ;

Statement: OPTIONAL4 SEMI {$$ = $1;}
         | LBRACE ZEROPLUS2 RBRACE {$$ = $2;}
         | LBRACE ErrorRule RBRACE {;}
         | IF LPAR Expr RPAR Statement ELSE Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); addchild($$,$7);}
         | IF LPAR Expr RPAR Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); }
         | WHILE LPAR Expr RPAR Statement {$$ = newnode(While,NULL); addchild($$,$3); addchild($$,$5);}
         | RETURN Expr SEMI {$$ = newnode(Return,NULL); addchild($$,$2);}
         | RETURN SEMI {$$ = newnode(Return,NULL); addchild($$,newnode(Null,NULL););}
         ;

ErrorRule: error SEMI {;}

OPTIONAL4: Expr {$$ = $1;}
         | {$$ = newnode(Null,NULL);}
         ;


ZEROPLUS2: ZEROPLUS2 Statement {;}
         | {;}
         ;


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
    | Expr BITWISEXOR Expr      {$$ = newnode(BitWiseXor, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr EQ Expr              {$$ = newnode(Eq, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr NE Expr              {$$ = newnode(Ne, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LE Expr              {$$ = newnode(Le, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GE Expr              {$$ = newnode(Ge, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr LT Expr              {$$ = newnode(Lt, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr GT Expr              {$$ = newnode(Gt, NULL); addchild($$, $1); addchild($$, $3);}
    | PLUS Expr    %prec NOT    {$$ = newnode(Plus,NULL); addchild($$,$2);}
    | MINUS Expr   %prec NOT    {$$ = newnode(Minus,NULL); addchild($$,$2);}
    | NOT Expr                  {$$ = newnode(Not,NULL); addchild($$,$2);}
    | IDENTIFIER LPAR error RPAR {;}
    | IDENTIFIER LPAR RPAR {;}
    | IDENTIFIER LPAR ZEROPLUS3 RPAR {;}
    | IDENTIFIER                {$$ = newnode(Identifier,$1);}
    | NATURAL                   {$$ = newnode(Natural,$1);}
    | CHRLITS                   {$$ = newnode(ChrLit,$1);}
    | DECIMAL                   {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR            {$$ = $2;}
    | LPAR error RPAR           {;}
    ;

ZEROPLUS3: ZEROPLUS3 COMMA Expr %prec HIGHER {;}
         | Expr %prec LOWER {$$ = $1;}
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
