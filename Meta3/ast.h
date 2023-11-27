#ifndef _AST_H
#define _AST_H
enum category { Program,Declaration,FuncDeclaration,FuncDefinition,ParamList,FuncBody,ParamDeclaration,StatList,Or,And,Eq,Ne,Lt,Gt,
                Le,Ge,Add,Sub,Mul,Div,Mod,Not,Minus,Plus,Store,Comma,Call,BitWiseAnd,BitWiseXor,BitWiseOr,Char,ChrLit,Identifier,Int,
                Short,Natural,Double,Decimal,Void,Null,If,Else,While,Return,Unknown,Error};

enum type {integer_type, double_type, no_type};
#define type_name(type) (type == integer_type ? "integer" : (type == double_type ? "double" : "none"))
#define category_type(category) (category == Int ? integer_type : (category == Double ? double_type : no_type))

struct node {
    enum category category;
    struct token *token;
    int token_line, token_column;
    enum type type;
    struct node_list *children;
};

struct node_list 
{
    struct node *node;
    int counter;
    struct node_list *next;
};
void show_stats();
struct node *newnode(enum category category, char *token);
struct node_list *newlist();
void addchild(struct node *parent, struct node *child);
void addchildren(struct node *parent, struct node_list *new_children);
void addnephews(struct node_list *parent, struct node_list *new_children);
void addbrother(struct node_list *root_list, struct node *child);
void insertType(struct node_list *declaration_list, struct node *target);

struct node *getchild(struct node *parent, int position);
struct node *getchild_in_list(struct node_list *parent, int position);
struct node *search_for_known_node(struct node_list *node_list);
int count_children_in_node(struct node *node);
int count_children_in_list(struct node_list *node_list);

char* getCategoryName(enum category category);
void show(struct node *node, int depth);
void cleanup(struct node *node);
void cleanlist(struct node_list *node_list);



#endif
