
%{
#include "ast.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct node *program = NULL;
extern int yylex(void);
void yyerror(char *);
extern char *yytext;
extern int yyleng;
extern int syn_line;
extern int syn_column;
extern bool type2;

extern int error_flag;
//int yydebug=1;

%}

%left LOW
%left COMMA
%right ASSIGN
%right ELSE

%left OR
%left AND
%left BITWISEOR 
%left BITWISEXOR 
%left BITWISEAND

%left EQ NE LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left HIGH

%nonassoc LOWER
%nonassoc HIGHER

%token CHAR INT SHORT DOUBLE RETURN VOID SEMI LBRACE LPAR RBRACE RPAR WHILE IF COMMA ASSIGN ELSE BITWISEOR BITWISEXOR BITWISEAND AND OR EQ NE LT LE GT GE PLUS MINUS MUL DIV MOD NOT RESERVED
%token<token> CHRLITS IDENTIFIER NATURAL DECIMAL 
%type<node_list> FunctionDeclarator Declarator DeclarationsAndStatements ZEROPLUS1 ZEROPLUS2 ZEROPLUS3 Declaration
%type<node> FunctionsAndDeclarations FunctionDefinition FunctionBody FunctionDeclaration ParameterList ParameterDeclaration TypeSpec Statement Expr OPTIONAL ErrorRule 


%union{ 
    struct token *token;
    struct node *node;
    struct node_list *node_list;
}

/* START grammar rules section -- BNF grammar */

%%
FunctionsAndDeclarations: FunctionsAndDeclarations FunctionDefinition {$$ = $1; addchild($$,$2);}
                        | FunctionsAndDeclarations FunctionDeclaration {$$ = $1; addchild($$,$2);}
                        | FunctionsAndDeclarations Declaration {$$ = $1; addchildren($$,$2);}
                        | FunctionDefinition {$$ = program = newnode(Program,NULL); addchild($$,$1);}
                        | FunctionDeclaration {$$ = program = newnode(Program,NULL); addchild($$,$1);}
                        | Declaration {$$ = program = newnode(Program,NULL); addchildren($$,$1);}                        
                        ;       
FunctionDefinition: TypeSpec FunctionDeclarator FunctionBody {$$ = newnode(FuncDefinition,NULL); addchild($$,$1); addchildren($$,$2); addchild($$,$3);}

FunctionBody: LBRACE RBRACE {$$ = newnode(FuncBody,NULL); addchild($$,newnode(Unknown,NULL));}
            | LBRACE DeclarationsAndStatements RBRACE {$$ = newnode(FuncBody,NULL); addchildren($$,$2);}
            ;



DeclarationsAndStatements: Statement DeclarationsAndStatements {$$ = newlist(); addbrother($$,$1); addnephews($$,$2);}
                         | Declaration DeclarationsAndStatements {$$ = $1; addnephews($$,$2);}
                         | Statement {$$ = newlist(); addbrother($$,$1);}
                         | Declaration {$$ = $1;}
                         ;

FunctionDeclaration: TypeSpec FunctionDeclarator SEMI {$$ = newnode(FuncDeclaration,NULL); addchild($$,$1); addchildren($$,$2);}  
                        

FunctionDeclarator: IDENTIFIER LPAR ParameterList RPAR {$$ = newlist(); addbrother($$,newnode(Identifier,$1)); addbrother($$,$3);}
                                        

ParameterList: ParameterList COMMA ParameterDeclaration {$$ = $1; addchild($$,$3);}
             | ParameterDeclaration {$$ = newnode(ParamList,NULL); addchild($$,$1);}
             ;


ParameterDeclaration: TypeSpec IDENTIFIER {$$ = newnode(ParamDeclaration,NULL); addchild($$,$1); addchild($$,newnode(Identifier,$2));}
                    | TypeSpec {$$ = newnode(ParamDeclaration,NULL); addchild($$,$1);}
                    ;


Declaration: TypeSpec Declarator ZEROPLUS1 SEMI {$$ = newlist(); struct node *temp = newnode(Declaration,NULL); addchild(temp,$1); addchildren(temp,$2); addbrother($$,temp); 

                                                if(count_children_in_list($3) > 0)
                                                {
                                                    insertType($3,$1);
                                                    addnephews($$,$3);
                                                }}
           | error SEMI {$$ = newlist(); addbrother($$,newnode(Error,NULL));}
           ;


ZEROPLUS1: ZEROPLUS1 COMMA Declarator {$$ = $1; struct node *temp = newnode(Declaration,NULL); addchild(temp,newnode(Unknown,NULL)); addchildren(temp,$3); addbrother($$,temp);}
         | {$$ = newlist(); }
         ;

TypeSpec: CHAR                          {$$ = newnode(Char,NULL);} 
        | INT                           {$$ = newnode(Int,NULL);}
        | VOID                          {$$ = newnode(Void,NULL);}
        | SHORT                         {$$ = newnode(Short,NULL);}
        | DOUBLE                        {$$ = newnode(Double,NULL);}
        ;

Declarator: IDENTIFIER ASSIGN Expr {$$ = newlist(); struct node *temp = newnode(Identifier,$1);addbrother($$,temp); addbrother($$,$3); }
          | IDENTIFIER {$$ = newlist(); addbrother($$,newnode(Identifier,$1));}
          ;

Statement: OPTIONAL SEMI {$$ = $1;}
         | LBRACE ZEROPLUS2 RBRACE { if(count_children_in_list($2) == 0)
                                     {
                                        //printf("1\n");
                                        $$ = newnode(Unknown,NULL);
                                        cleanlist($2);
                                        //addchildren($$,$2); 
                                     }
                                     if(count_children_in_list($2) == 1)
                                     {
                                        //printf("2\n");
                                        $$ = search_for_known_node($2);
                                     } 
                                    if(count_children_in_list($2) >= 2)
                                     {
                                        $$ = newnode(StatList,NULL);
                                        addchildren($$,$2);   
                                     }
                                    }
         | IF LPAR Expr RPAR ErrorRule ELSE ErrorRule %prec LOW {$$ = newnode(If,NULL); enum category cat = Null; addchild($$,$3);
                                                                 if(strcmp(getCategoryName($5->category),"Unknown") == 0){$5->category = cat;}
                                                                 if(strcmp(getCategoryName($7->category),"Unknown") == 0){$7->category = cat;}
                                                                 addchild($$,$5);addchild($$,$7); }
                                                               
         | IF LPAR Expr RPAR ErrorRule %prec LOW {$$ = newnode(If,NULL); enum category cat = Null; addchild($$,$3); if(strcmp(getCategoryName($5->category),"Unknown") == 0){$5->category = cat;}
                                                    addchild($$,$5); addchild($$,newnode(Null,NULL));
                                                } 
         | WHILE LPAR Expr RPAR ErrorRule {$$ = newnode(While,NULL); enum category cat = Null; addchild($$,$3); if(strcmp(getCategoryName($5->category),"Unknown") == 0){$5->category = cat;}
                                                    addchild($$,$5);}
            
         | RETURN Expr SEMI {$$ = newnode(Return,NULL); addchild($$,$2);}
         | RETURN SEMI {$$ = newnode(Return,NULL); addchild($$,newnode(Null,NULL));}
         ;

ErrorRule: error {$$ = newnode(Error,NULL);}
         | Statement {$$ = $1;}
         ;
OPTIONAL: Expr {$$ = $1;}
        | {$$ = newnode(Unknown,NULL);}
        ;


ZEROPLUS2: ZEROPLUS2 ErrorRule { $$ = $1; addbrother($$,$2);}
         | {$$ = newlist(); }
         ;


Expr: Expr ASSIGN Expr          {$$ = newnode(Store, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr COMMA Expr           {$$ = newnode(Comma, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr PLUS Expr            {$$ = newnode(Add, NULL); addchild($$, $1); addchild($$, $3);}
    | Expr MINUS Expr           {$$ = newnode(Sub, NULL); addchild($$, $1); addchild($$, $3);}
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
    | IDENTIFIER LPAR error RPAR {$$ = newnode(Call,NULL); addchild($$,newnode(Identifier,$1)); addchild($$,newnode(Error,NULL));}
    | IDENTIFIER LPAR RPAR       {$$ = newnode(Call,NULL); addchild($$,newnode(Identifier,$1));}
    | IDENTIFIER LPAR ZEROPLUS3 RPAR {$$ = newnode(Call,NULL); addchild($$,newnode(Identifier,$1));addchildren($$,$3);}
    | IDENTIFIER                {$$ = newnode(Identifier,$1);}
    | NATURAL                   {$$ = newnode(Natural,$1);}
    | CHRLITS                   {$$ = newnode(ChrLit,$1);}
    | DECIMAL                   {$$ = newnode(Decimal,$1);}
    | LPAR Expr RPAR            {$$ = $2;}
    | LPAR error RPAR           {$$ = newnode(Error,NULL);}
    ;

ZEROPLUS3: ZEROPLUS3 COMMA Expr %prec HIGHER {$$ = $1; addbrother($$,$3);}
         | Expr %prec LOWER {$$ = newlist(); addbrother($$,$1);}
         ;

%%
void yyerror(char *error) 
{
    printf("Line %d, column %d: %s: %s\n",syn_line,syn_column,error,yytext);
    error_flag = 1;
}
/* START subroutines section */

// all needed functions are collected in the .l and ast.* files
