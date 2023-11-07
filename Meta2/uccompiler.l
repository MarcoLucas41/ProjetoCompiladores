%{
    #include <stdio.h>
    #include <stdbool.h>
    #include <string.h>
    bool type = false;
    int line = 1;
    int column = 0;
    int commentLine = 0;
    int commentColumn = 0;
    int commentState= 0;
    #define YY_USER_ACTION column += yyleng; 
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

"/*"                    { BEGIN(COMMENT); commentLine = line; commentColumn = column-1; commentState = 1;}
<COMMENT>.              { ; }
<COMMENT>(\n|\r\n)      { line+=1; column = 0; }
<COMMENT>"*/"           { commentState = 0; BEGIN(INITIAL);}

{reservedWords}         { if(type){printf("RESERVED(%s)\n",yytext);} PASS_TOKEN(); return RESERVED;}
{keyWords}              { 
    if(type)
    {
        for(int i = 0; i < yyleng;i++)
        {
            printf("%c",yytext[i]-32);
        } 
        printf("\n");
    } 
}   



                            
\&                      { if(type) {printf("BITWISEAND\n");} return BITWISEAND;}
\|                      { if(type) {printf("BITWISEOR\n");} return BITWISEOR;}
\^                      { if(type) {printf("BITWISEXOR\n");} return BITWISEXOR;}
\&\&                    { if(type) {printf("AND\n");} return AND;}
\=                      { if(type) {printf("ASSIGN\n");} return ASSIGN;}
\*                      { if(type) {printf("MUL\n");} return MUL;}
\,                      { if(type) {printf("COMMA\n");} return COMMA;}
\=\=                    { if(type) {printf("EQ\n");} return EQ;}
\>\=                    { if(type) {printf("GE\n");} return GE;}
\>                      { if(type) {printf("GT\n");} return GT;}

\/\/                    { BEGIN(COMMENT2);}
<COMMENT2>.             { ; }
<COMMENT2>(\n|\r\n)            { line += 1; column = 0; BEGIN(INITIAL);}
\/                      { if(type){printf("DIV\n");} return DIV;}

\{                      { if(type) {printf("LBRACE\n");} return LBRACE;}
\<\=                    { if(type) {printf("LE\n");} return LE;}
\(                      { if(type) {printf("LPAR\n");} return LPAR;}
\<                      { if(type) {printf("LT\n");} return LT;}
\-                      { if(type) {printf("MINUS\n");} return MINUS;}
\%                      { if(type) {printf("MOD\n");} return MOD;}
\!\=                    { if(type) {printf("NE\n");} return NE;}
\!                      { if(type) {printf("NOT\n");} return NOT;}
\|\|                    { if(type) {printf("OR\n");} return OR;}
\+                      { if(type) {printf("PLUS\n");} return PLUS;}
\}                      { if(type) {printf("RBRACE\n");} return RBRACE;}
\)                      { if(type) {printf("RPAR\n");} return RPAR;}
\;                      { if(type) {printf("SEMI\n");} return SEMI;}

\'([^\n\\']|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))\' { if(type) {printf("CHRLIT(%s)\n",yytext);BEGIN(INITIAL);} PASS_TOKEN(); return CHRLIT;}
\'([^\n\\']*|\\\'|\\\\|\\[^\n\\']+)+(\\)?            { column -= yyleng-1; printf("Line %d, column %d: unterminated char constant\n",line,column); column += yyleng-1;BEGIN(INITIAL);}
\'([^\n\\']*|\\\'|\\\\|\\[^\n\'])+\'                 { column -= yyleng-1; printf("Line %d, column %d: invalid char constant (%s)\n",line,column,yytext); column += yyleng-1;BEGIN(INITIAL);}
                
" "                     { ; }
\t                      { ; }
\n|\r\n|\r                      { line+=1; column = 0; }

{letter}({digit}|{letter})*                     { if(type) {printf("IDENTIFIER(%s)\n",yytext);} PASS_TOKEN(); return IDENTIFIER; }
{digit}+                                        { if(type) {printf("NATURAL(%s)\n",yytext);} PASS_TOKEN(); return NATURAL; }

{digit}+"."([eE][+-]?{digit}+)?|{digit}+"."{digit}+([eE][+-]?{digit}+)? {
    if(type) {printf("DECIMAL(%s)\n", yytext);
} PASS_TOKEN();return DECIMAL;}

"."{digit}+([eE][+-]?{digit}+)? {
    if(type) {printf("DECIMAL(%s)\n", yytext);
} PASS_TOKEN();return DECIMAL;}

{digit}+[eE][+-]?{digit}+ {
    if(type) {printf("DECIMAL(%s)\n", yytext);
} PASS_TOKEN();return DECIMAL;}

.                       { printf("Line %d, column %d: unrecognized character (%s)\n",line,column,yytext);}

%%
void show(struct node *node, int depth) 
{
    struct node_list *temp = node->children->next;
    for(int i = 0; i < depth+1; i++)
    {
        printf(".");
    }
    if(node->token != NULL)
    {
        printf("%s(%s)\n",getCategoryName(node->category), node->token);
    }
    else
    {
        printf("%s\n",getCategoryName(node->category));
    }

    while(temp != NULL)
    {
        show(temp->node,depth+1);
        temp = temp->next;
    }

    
    //printf("%s\n",getCategoryName(node->children->next->node->category));
    //printf("%s\n",getCategoryName(node->children->next->next->node->category));
    
}



void cleanup(struct node *node)
{
    struct node_list *temp = node->children->next;

    while(temp != NULL)
    {
        cleanup(temp->node);
        temp = temp->next;
    }
    free(node->children);
    free(node);

}




extern int yylex();
int main(int argc, char *argv[]) 
{
    if(argv[1] != NULL)
    {
        if(strcmp(argv[1],"-l") == 0) type = true;
        if(strcmp(argv[1],"-t") == 0);
    }
    yylex();    /* run the lexical analysis automaton */
    return 0;
}
int yywrap() {  /* called on EOF, return 1 to terminate */
    if(commentState == 1)
    {
        printf("Line %d, column %d: unterminated comment\n",commentLine,commentColumn);
    }
    return 1;
}
