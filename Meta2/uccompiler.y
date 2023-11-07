
%{

#include "ast.h"

int yylex(void);
void yyerror(char *);
//int yydebug=1;

struct node *program;

%}

%token 
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
FunctionsAndDeclarations: FunctionDefinition ZEROPLUS1
                        | FunctionDeclaration ZEROPLUS1
                        | Declaration ZEROPLUS1

ZEROPLUS1: ZEROPLUS1 FunctionDefinition
         | ZEROPLUS1 FunctionDeclaration
         | ZEROPLUS1 Declaration
         | ;
                                
                               
FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {}

FunctionBody: LBRACE OPTIONAL1 RBRACE {}

OPTIONAL1: DeclarationsAndStatements {}
        | ;


DeclarationsAndStatements: Statement DeclarationsAndStatements {}
                         | Declaration DeclarationsAndStatements {}
                         | Statement {}
                         | Declaration {}
                         ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {}  
                   | ;                       

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {}
                  | ;                                    

ParameterList: ParameterList COMMA ParameterDeclaration
             | ParameterDeclaration
             ;


             

ParameterDeclaration: TypeSpec OPTIONAL2
                    | ;

OPTIONAL2: IDENTIFIER
        | ;

Declaration: TypeSpec Declarator ZEROPLUS1 SEMI
           | ERROR SEMI;

ZEROPLUS1: ZEROPLUS1 COMMA Declarator
         | ;

TypeSpec: CHAR 
        | INT 
        | VOID 
        | SHORT 
        | DOUBLE 
        ;

Declarator: IDENTIFIER OPTIONAL3{}
          ;

OPCIONAL3: ASSIGN Expr
        | ;         

Statement: OPTIONAL4 SEMI
         | LBRACE ZEROPLUS2 RBRACE
         | LBRACE ERROR RBRACE
         | IF LPAR Expr RPAR Statement OPTIONAL5 %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); addchild($$,$7);}
         | IF LPAR Expr RPAR Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5);}
         | WHILE LPAR Expr RPAR Statement {$$ = newnode(While,NULL); addchild($$,$3); addchild($$,$5);}
         | RETURN OPCIONAL4 SEMI {}
         | ERROR SEMI
         ;

OPTIONAL4: Expr
         | ;

OPTIONAL5: ELSE Statement
        | ;

ZEROPLUS2: ZEROPLUS2 Statement
        | ;


Expr: Expr ASSIGN Expr 
    | Expr COMMA Expr 
    | Expr PLUS Expr 
    | Expr MINUS Expr 
    | Expr MUL Expr 
    | Expr DIV Expr 
    | Expr MOD Expr 
    | Expr OR Expr 
    | Expr AND Expr 
    | Expr BITWISEAND Expr {}
    | Expr BITWISEOR Expr {}
    | Expr BITWISEXOR Expr 
    | Expr EQ Expr 
    | Expr NE Expr 
    | Expr LE Expr 
    | Expr GE Expr 
    | Expr LT Expr 
    | Expr GT Expr 
    | PLUS Expr 
    | MINUS Expr
    | NOT Expr {+}
    | IDENTIFIER LPAR ERROR RPAR
    | IDENTIFIER LPAR OPTIONAL6 RPAR 
    | IDENTIFIER {$$ = newnode(Identifier,$1);}
    | NATURAL {$$ = newnode(Natural,$1);}
    | CHRLIT {$$ = newnode(Chrlit,$1);}
    | DECIMAL {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR {$$ = $2;}
    | LPAR ERROR RPAR
    ;

OPTIONAL6: ZEROPLUS3  
         | ;

ZEROPLUS3: ZEROPLUS3 COMMA Expr
         | Expr;
//if: n há problemas de associatividade
//else: é necessário associar a um IF

//NULL: #include <stdio.h>


%%

/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
