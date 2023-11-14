#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

// get the respective category string given the enum constant equivalent
char* getCategoryName(enum category category)
{
    char *strings[] = { "Program","Declaration","FuncDeclaration","FuncDefinition","ParamList","FuncBody","ParamDeclaration","StatList","Or","And","Eq","Ne","Lt","Gt",
                "Le","Ge","Add","Sub","Mul","Div","Mod","Not","Minus","Plus","Store","Comma","Call","BitWiseAnd","BitWiseXor","BitWiseOr","Char","ChrLit","Identifier","Int",
                "Short","Natural","Double","Decimal","Void","Null","If","Else","While","Return"};
    return strings[category]; 
}

// create a node of a given category with a given lexical symbol
struct node *newnode(enum category category, char *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->counter = 0;
    new->children->next = NULL;
    printf("New node created! %s\n",getCategoryName(category));
    return new;
}

struct node_list *newlist()
{
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = NULL;
    new->counter = 0;
    new->next = NULL;
    return new;
}

void addbrother(struct node_list *root_list, struct node *child)
{
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *temp = root_list;
    while(temp->next != NULL)
        temp = temp->next;
    printf("Adding child %s to list!\n",getCategoryName(child->category));
    temp->next = new;
    root_list->counter +=1;
}

void addchildren(struct node *parent, struct node_list *new_children)
{
    struct node_list *temp = new_children->next;
    struct node_list *temp2 = parent->children;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    //printf("1-Pointer is at %s\n",getCategoryName(temp2->node->category));
    while(temp->next != NULL)
    {
        temp2->next = temp;
        temp2= temp2->next;
        temp = temp->next;
        parent->children->counter +=1;
    }
    if(temp->node != NULL)
    {
        temp2->next = temp;
    }
    free(new_children);
}

void addnephews(struct node_list *parent, struct node_list *new_children)
{
    struct node_list *temp = new_children->next;
    struct node_list *temp2 = parent->next;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    //printf("1-Pointer is at %s\n",getCategoryName(temp2->node->category));
    while(temp->next != NULL)
    {
        temp2->next = temp;
        temp2= temp2->next;
        temp = temp->next;
        parent->counter += 1;
    }
    if(temp->node != NULL)
    {
        temp2->next = temp;
    }
    printf("counter: %d\n",parent->counter);
    free(new_children);
}



// append a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) 
{
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL)
        children = children->next;
    children->next = new;
    parent->children->counter += 1;
    printf("Adding child %s to parent %s!\n",getCategoryName(child->category),getCategoryName(parent->category));
}


// print the syntax tree given root node
void show(struct node *node, int depth) 
{
    struct node_list *temp = node->children->next;
    
    if(depth > 0)
    {
        for(int i = 0; i < depth; i++)
        {
            printf("..");
        }
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
    printf("Freeing node %s\n",getCategoryName(node->category));
    free(node);
}
