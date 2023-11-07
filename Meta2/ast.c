#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// get the respective category string given the enum constant equivalent
char* getCategoryName(enum category category)
{
    char *strings[] = { "Program","Declaration","FuncDeclaration","FuncDefinition","ParamList","FuncBody","ParamDeclaration","StatList","If","Else","While","Return","Or","And","Eq","Ne","Ly","Gt",
                "Le","Ge","Add","Sub","Mul","Div","Mod","Not","Minus","Plus","Store","Comma","Call","BitWiseAnd","BitWiseXor","BitWiseOr","Char","ChrLit","Identifier","Int",
                "Short","Natural","Double","Decimal","Void","Null" };
    return strings[category]; 
}

// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    printf("New node created! %s\n",getCategoryName(category));
    return new;
}

// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) {
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL)
        children = children->next;
    children->next = new;
    printf("Adding child %s to parent %s!\n",getCategoryName(child->category),getCategoryName(parent->category));
}

// print the syntax tree given root node
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

// frees all nodes from syntax tree given root node
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
