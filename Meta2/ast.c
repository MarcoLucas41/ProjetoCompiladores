#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

// get the respective category string given the enum constant equivalent
char* getCategoryName(enum category category)
{
    switch(category)
    {
        case Program: return "Program"; break;
        case Function: return "Function"; break;
        case Parameters: return "Parameters"; break;
        case Parameter: return "Parameter"; break;
        case Arguments: return "Arguments";break;
        case Integer: return "Integer"; break;
        case Double: return "Double"; break;
        case Identifier: return "Identifier"; break;
        case Natural: return "Natural"; break;
        case Decimal: return "Decimal"; break;
        case Call: return "Call"; break;
        case If: return "If"; break;
        case Add: return "Add"; break;
        case Sub: return "Sub"; break;
        case Mul: return "Mul"; break;
        case Div: return "Div"; break;
        default: return NULL;
    }
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
