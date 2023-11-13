#ifndef _AST_H
#define _AST_H
enum category { Program,Declaration,FuncDeclaration,FuncDefinition,ParamList,FuncBody,ParamDeclaration,StatList,Or,And,Eq,Ne,Lt,Gt,
                Le,Ge,Add,Sub,Mul,Div,Mod,Not,Minus,Plus,Store,Comma,Call,BitWiseAnd,BitWiseXor,BitWiseOr,Char,ChrLit,Identifier,Int,
                Short,Natural,Double,Decimal,Void,Null,If,Else,While,Return};
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
struct node_list *newlist();
void addchild(struct node *parent, struct node *child);
void addchildren(struct node *parent, struct node_list *new_children);
void addnephews(struct node_list *parent, struct node_list *new_children);
void addbrother(struct node_list *root_list, struct node *child);
char* getCategoryName(enum category category);
void show(struct node *node, int depth); 
void cleanup(struct node *node);

#endif
