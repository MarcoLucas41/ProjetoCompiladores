#ifndef _AST_H
#define _AST_H
enum category { Program,Declaration,FuncDeclaration,FuncDefinition,ParamList,FuncBody,ParamDeclaration,StatList,Or,And,Eq,Ne,Lt,Gt,
                Le,Ge,Add,Sub,Mul,Div,Mod,Not,Minus,Plus,Store,Comma,Call,BitWiseAnd,BitWiseXor,BitWiseOr,Char,ChrLit,Identifier,Int,
                Short,Natural,Double,Decimal,Void,Null,If,Else,While,Return,Unknown,Error};

enum type {integer_type, double_type, short_type, char_type, no_type};
#define type_name(type) (type == integer_type ? "int" : (type == double_type ? "double" : (type == short_type ? "short" :(type == char_type ? "char" : "void"))))
#define category_type(category) (category == Int ? integer_type : (category == Double ? double_type : (category == Short ? short_type : (category == Char ? char_type : no_type))))

//Data structure for a node
//It includes 2 enums to represent respectively the category and the type of a node.
//It also has a structure <token> for storing a token information and a structure <node_list> in order to access the children of said node

struct node {
    enum category category;
    struct token *token;
    enum type type;
    struct node_list *children;
};

//Data structure that includes the string representation of a token, as well as the line and column of the token position in a file
struct token 
{
    char *token;
    int line;
    int column;
};

//Data structure that serves as a linked list of data structure <node>
struct node_list 
{
    struct node *node;
    struct node_list *next;
};

void show_stats();
struct node *newnode(enum category category, struct token *token);
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

struct token *create_token(char *token,int line,int column);
char* getCategoryName(enum category category);
void show(struct node *node, int depth);
void cleanup(struct node *node);
void cleanlist(struct node_list *node_list);



#endif
