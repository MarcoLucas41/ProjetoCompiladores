
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
FunctionsAndDeclarations: FunctionDefinition {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionDeclaration {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | Declaration {$$ = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionsAndDeclarations FunctionDefinition {$$ = $1; addchild($$,$2);}
                        | FunctionsAndDeclarations FunctionDeclaration {$$ = $1; addchild($$,$2);}
                        | FunctionsAndDeclarations Declaration {$$ = $1; addchild($$,$2);}
                               
                    

FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = newnode(FuncDefinition,NULL); addchild($$,$1); addchild($$,$2); addchild($$,$3);}

FunctionBody: LBRACE DeclarationsAndStatements RBRACE {$$ = newnode(FuncBody,NULL); addchild($$,$2);}
            | LBRACE RBRACE {$$ = newnode(FuncBody,NULL);}


DeclarationsAndStatements: Statement DeclarationsAndStatements {addchild($$,$1); addchild($$,$2);}
                         | Declaration DeclarationsAndStatements {addchild($$,$1); addchild($$,$2);}
                         | Statement {addchild($$,$1);}
                         | Declaration {addchild($$,$1);}

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$ = newnode(FuncDeclaration,NULL); addchild($$,$1); addchild($$,$2);}                         

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {struct node *identifier = newnode(Identifier,$1);
                                                        addchild($$,identifier);
                                                        addchild($$,$3);
                                                        }                         

ParameterList: ParameterDeclaration ParameterList0+ {}
             | ParameterDeclaration {}

ParameterList0+: COMMA ParameterDeclaration
               | ParameterList0+ COMMA ParemeterDeclaration

ParameterDeclaration: TypeSpec IDENTIFIER
                    | TypeSpec

Declaration: TypeSpec Declarator Declaration0+ SEMI
           | TypeSpec Declarator SEMI

Declaration0+: COMMA Declarator
             | Declaration0+ COMMA Declarator

TypeSpec: CHAR {$$ = newnode(Char,NULL));} 
        | INT 
        | VOID 
        | SHORT 
        | DOUBLE 

Declarator: IDENTIFIER ASSIGN Expr {struct node *identifier = newnode(Identifier,$1); addchild($$,$1); addchild($$,$3);}
          | IDENTIFIER {struct node *identifier = newnode(Identifier,$1); addchild($$,$1);}

Statement: Expr SEMI {$$ = $1;}
         | SEMI {;}
         | LBRACE RBRACE {;}
         | LBRACE Statement0+ RBRACE {$$ = $2;}
         | IF LPAR Expr RPAR Statement ELSE Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5); addchild($$,$7);}
         | IF LPAR Expr RPAR Statement %prec LOW {$$ = newnode(If,NULL); addchild($$,$3); addchild($$,$5);}
         | WHILE LPAR Expr RPAR Statement {$$ = newnode(While,NULL); addchild($$,$3); addchild($$,$5);}
         | RETURN Expr SEMI {$$ = newnode(Return,NULL); addchild($$,$2);}
         | RETURN SEMI {$$ = newnode(Return,NULL); addchild($$,$2);}

Statement0+: Statement {$$ = $1;}
           | Statement0+ Statement         
/*

if []: LBRACE RBRACE
     | LBRACE Statement RBRACE

if {}: LBRACE RBRACE
     | LBRACE Statement0+ RBRACE

Statement0+: Statement
           | Stament0+ Statement
*/

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
    | NOT Expr {$$ = newnode(Not,NULL); addchild($$,$1);}
    | IDENTIFIER LPAR RPAR {$$ = newnode(Plus,NULL); addchild($$,$1);}
    | IDENTIFIER LPAR Expr RPAR
    | IDENTIFIER LPAR Expr Expr0+ RPAR
    | IDENTIFIER {$$ = newnode(Identifier,$1);}
    | NATURAL {$$ = newnode(Natural,$1);}
    | CHRLIT {$$ = newnode(Chrlit,$1);}
    | DECIMAL {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR {$$ = $2;}

Expr0+: COMMA Expr
      | Expr0+ COMMA Expr

%%

/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
