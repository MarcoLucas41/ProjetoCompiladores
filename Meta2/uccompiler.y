
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

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {}                         

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {}                         

ParameterList: ParameterDeclaration ZEROPLUS2{}

ZEROPLUS2: ZEROPLUS2 COMMA ParameterDeclaration
        | ;
             

ParameterDeclaration: TypeSpec OPCIONAL2

OPCIONAL2: IDENTIFIER
        | ;

Declaration: TypeSpec Declarator ZEROPLUS3 SEMI

ZEROPLUS3: ZEROPLUS3 COMMA Declarator
        | ;

TypeSpec: CHAR 
        | INT 
        | VOID 
        | SHORT 
        | DOUBLE 

Declarator: IDENTIFIER OPCIONAL3{}

OPCIONAL3: ASSIGN Expr
        | ;         

Statement: OPCIONAL4 SEMI
         | LBRACE ZEROPLUS4 RBRACE
         | IF LPAR Expr RPAR Statement OPCIONAL5 %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); addchild($$,$7);}
         | IF LPAR Expr RPAR Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5);}
         | WHILE LPAR Expr RPAR Statement {$$ = newnode(While,NULL); addchild($$,$3); addchild($$,$5);}
         | RETURN OPCIONAL4 SEMI {}

OPCIONAL4: Expr
         | ;
OPCIONAL5: ELSE Statement
        | ;

ZEROPLUS4: ZEROPLUS4 Statement
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
    | Expr BITWISEAND Expr {$$ = newnode(BitWiseAnd,NULL); addchild($$,$1); addchild($$,$2);}
    | Expr BITWISEOR Expr {$$ = newnode(BitWiseOr,NULL); addchild($$,$1); addchild($$,$2);}
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
    | IDENTIFIER LPAR OPCIONAL6 RPAR 
    | IDENTIFIER {$$ = newnode(Identifier,$1);}
    | NATURAL {$$ = newnode(Natural,$1);}
    | CHRLIT {$$ = newnode(Chrlit,$1);}
    | DECIMAL {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR {$$ = $2;}

OPCIONAL6: Expr ZEROPLUS5  
        | ;

ZEROPLUS5: ZEROPLUS5 COMMA Expr
     | ;
//if: n há problemas de associatividade
//else: é necessário associar a um IF

%%

/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
