/*  --------Authors---------*/
/*  Marco Lucas 2021219146  */
/*  Rui Coelho  2021235407  */


%{
    #include "y.tab.h"
    #include "ast.h"
    #include "semantics.h"
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <string.h>
    int yyparse(void);
    bool type = false;
    bool type2 = false;
    extern struct node *program;
    extern struct table *global;
    int error_flag = 0;
    int lex_line = 1, lex_column = 1;
    int syn_line = -1, syn_column = -1;
    int commentLine = 0;
    int commentColumn = 0;
    int commentState= 0;
    #define YY_USER_ACTION { syn_line = lex_line; syn_column = lex_column; lex_column += yyleng; }
    #define PASS_TOKEN() yylval.token = create_token(strdup(yytext),syn_line,syn_column);   
%}


digit   [0-9]
letter  [a-zA-Z_]
punctuation "("|")"|","|"*"|"="|"+"|"-"|"|"
keyWords "char"|"else"|"while"|"if"|"int"|"short"|"double"|"return"|"void"
reservedWords "++"|"--"|"["|"]"|"_Bool"|"_Complex"|"_Imaginary"|"auto"|"break"|"case"|"const"|"continue"|"default"|"do"|"long"|"register"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"volatile"|"enum"|"extern"|"float"|"for"|"goto"|"inline"|"restrict"



%X COMMENT
%X COMMENT2
%X CHRLIT


%%

"/*"                    { BEGIN(COMMENT); commentLine = lex_line; commentColumn = lex_column-1; commentState = 1;}
<COMMENT>.              { ; }
<COMMENT>(\n|\r\n)      { lex_line+=1; lex_column = 1; }
<COMMENT>"*/"           { commentState = 0; BEGIN(INITIAL);}

{reservedWords}         { if(type){printf("RESERVED(%s)\n",yytext);} if(type2){ PASS_TOKEN();return RESERVED; } }
{keyWords}              { 
    if(type)
    {
        for(int i = 0; i < yyleng;i++)
        {
            printf("%c",yytext[i]-32);
        } 
        printf("\n");
    } 
    if(strcmp(yytext,"char")==0){ if(type2) return CHAR;}
    if(strcmp(yytext,"else")==0){ if(type2) return ELSE;}
    if(strcmp(yytext,"while")==0){ if(type2) return WHILE;}
    if(strcmp(yytext,"if")==0){if(type2) return IF;}
    if(strcmp(yytext,"int")==0){if(type2) return INT;}
    if(strcmp(yytext,"short")==0){if(type2) return SHORT;}
    if(strcmp(yytext,"double")==0){if(type2) return DOUBLE;}
    if(strcmp(yytext,"return")==0){if(type2) return RETURN;}
    if(strcmp(yytext,"void")==0){if(type2) return VOID;}    
       
    }
   



                            
\&                      { if(type) {printf("BITWISEAND\n");} if(type2) return BITWISEAND;}
\|                      { if(type) {printf("BITWISEOR\n");} if(type2) return BITWISEOR;}
\^                      { if(type) {printf("BITWISEXOR\n");} if(type2) return BITWISEXOR;}
\&\&                    { if(type) {printf("AND\n");} if(type2) return AND;}
\=                      { if(type) {printf("ASSIGN\n");} if(type2) return ASSIGN;}
\*                      { if(type) {printf("MUL\n");} if(type2) return MUL;}
\,                      { if(type) {printf("COMMA\n");} if(type2) return COMMA;}
\=\=                    { if(type) {printf("EQ\n");} if(type2) return EQ;}
\>\=                    { if(type) {printf("GE\n");} if(type2) return GE;}
\>                      { if(type) {printf("GT\n");} if(type2) return GT;}

\/\/                    { BEGIN(COMMENT2);}
<COMMENT2>.             { ; }
<COMMENT2>(\n|\r\n)            { lex_line += 1; lex_column = 0; BEGIN(INITIAL);}
\/                      { if(type){printf("DIV\n");} if(type2) return DIV;}

\{                      { if(type) {printf("LBRACE\n");}if(type2) return LBRACE;}
\<\=                    { if(type) {printf("LE\n");} if(type2) return LE;}
\(                      { if(type) {printf("LPAR\n");} if(type2) return LPAR;}
\<                      { if(type) {printf("LT\n");} if(type2) return LT;}
\-                      { if(type) {printf("MINUS\n");} if(type2) return MINUS;}
\%                      { if(type) {printf("MOD\n");} if(type2) return MOD;}
\!\=                    { if(type) {printf("NE\n");} if(type2) return NE;}
\!                      { if(type) {printf("NOT\n");} if(type2) return NOT;}
\|\|                    { if(type) {printf("OR\n");} if(type2) return OR;}
\+                      { if(type) {printf("PLUS\n");} if(type2) return PLUS;}
\}                      { if(type) {printf("RBRACE\n");} if(type2) return RBRACE;}
\)                      { if(type) {printf("RPAR\n");} if(type2) return RPAR;}
\;                      { if(type) {printf("SEMI\n");} if(type2) return SEMI;}

\'([^\n\\']|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))\' { if(type) {printf("CHRLIT(%s)\n",yytext);BEGIN(INITIAL);} if(type2) {PASS_TOKEN(); return CHRLITS;}}
\'([^\n\\']*|\\\'|\\\\|\\[^\n\\']+)+(\\)?            { lex_column -= yyleng-1; printf("Line %d, column %d: unterminated char constant\n",lex_line,lex_column); lex_column += yyleng-1;BEGIN(INITIAL);}
\'([^\n\\']*|\\\'|\\\\|\\[^\n\'])+\'                 { lex_column -= yyleng-1; printf("Line %d, column %d: invalid char constant (%s)\n",lex_line,lex_column,yytext); lex_column += yyleng-1;BEGIN(INITIAL);}
                
" "                     { ; }
\t                      { ; }
\n|\r\n|\r                      { lex_line+=1; lex_column = 1; }

{letter}({digit}|{letter})*                     { if(type) {printf("IDENTIFIER(%s)\n",yytext);} if(type2){PASS_TOKEN(); return IDENTIFIER; } }
{digit}+                                        { if(type) {printf("NATURAL(%s)\n",yytext);} if(type2){PASS_TOKEN(); return NATURAL;} }

{digit}+"."([eE][+-]?{digit}+)?|{digit}+"."{digit}+([eE][+-]?{digit}+)? {
    if(type) {printf("DECIMAL(%s)\n", yytext);
} if(type2){PASS_TOKEN();return DECIMAL;} }

"."{digit}+([eE][+-]?{digit}+)? {
    if(type) {printf("DECIMAL(%s)\n", yytext);
} if(type2){PASS_TOKEN();return DECIMAL;} }

{digit}+[eE][+-]?{digit}+ {
    if(type) {printf("DECIMAL(%s)\n", yytext);
} if(type2){PASS_TOKEN();return DECIMAL;} }

.                       { printf("Line %d, column %d: unrecognized character (%s)\n",syn_line,syn_column,yytext);}
<<EOF>>                 { YY_USER_ACTION; return 0; }
%%

extern int yylex();

int main(int argc, char *argv[]) 
{
    switch(argc)
    {
        case 1:
            type = false;
            type2 = true;
            error_flag = 1;
            yyparse();
            break;
            
        case 2:
            if(strcmp(argv[1],"-l") == 0)
            {
                type = true;
                type2 = false;
                error_flag = 1;
                yylex();
            }
            if(strcmp(argv[1],"-t") == 0)
            {
                type = false;
                type2 = true;
                yyparse(); 
            }
            if(strcmp(argv[1],"-s") == 0)
            {
                type = false;
                type2 = true;
                error_flag = 1;
                yyparse();
            }
    }
                 
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    if(commentState == 1)
    {
        printf("Line %d, column %d: unterminated comment\n",commentLine,commentColumn);
    }
    if(error_flag == 0 && type2 == true && program != NULL)
    {
        show(program,0);
    }
    int errors = check_program(program);
    //printf("ERRORS: %d\n",errors);

    if(errors >= 0)
    {
        show_symbol_tables();
        printf("\n");
        show_annoted_AST(program, 0, global);
        cleanup_symbol_tables();

    }    
    if(program != NULL) cleanup(program); //show_stats(); cleanup_symbol_tables()
    return 1;
}
