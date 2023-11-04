#ifndef _AST_H
#define _AST_H

enum category { Program,Declaration,FuncDeclaration,FuncDefinition,ParamList,FuncBody,ParamDeclaration,StatList,Or,And,Eq,Ne,Ly,Gt,
                Le,Ge,Add,Sub,Mul,Div,Mod,Not,Minus,Plus,Store,Comma,Call,BitWiseAnd,BitWiseXor,BitWiseOr,Char,ChrLit,Identifier,Int,
                Short,Natural,Double,Decimal,Void,Null };
struct node {
    enum category category;
    char *token;
    struct node_list *children;
};

struct node_list {
    struct node *node;
    struct node_list *next;
};

struct node *newnode(enum category category, char *token);
void addchild(struct node *parent, struct node *child);
char* getCategoryName(enum category category);

#endif
