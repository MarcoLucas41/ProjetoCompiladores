#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ast.h"

// Counters that help with memory leaks debugging
int num_frees = 0;
int num_nodes = 0;

// Gets the respective category string given the enum constant equivalent
char* getCategoryName(enum category category)
{
    char *strings[] = { "Program","Declaration","FuncDeclaration","FuncDefinition","ParamList","FuncBody","ParamDeclaration","StatList","Or","And","Eq","Ne","Lt","Gt",
                "Le","Ge","Add","Sub","Mul","Div","Mod","Not","Minus","Plus","Store","Comma","Call","BitWiseAnd","BitWiseXor","BitWiseOr","Char","ChrLit","Identifier","Int",
                "Short","Natural","Double","Decimal","Void","Null","If","Else","While","Return","Unknown","Error"};
    return strings[category]; 
}

// Creates a node of a given category with a given lexical symbol
struct node *newnode(enum category category, struct token *token) {
    struct node *new = malloc(sizeof(struct node));
    new->category = category;
    new->token = token;
    new->children = malloc(sizeof(struct node_list));
    new->children->node = NULL;
    new->children->next = NULL;
    //printf("New node created! %s\n",getCategoryName(category));
    num_nodes +=1;
    return new;
}

// Creates a struct that stores data about a token
struct token *create_token(char *token,int line,int column)
{
    struct token *new = malloc(sizeof(struct token));
    new->token = token;
    new->line = line;
    new->column = column;
    return new;
}

// Initializes a <node_list> struct
struct node_list *newlist()
{
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = NULL;
    new->next = NULL;
    return new;
}

// Adds a node to a node list
void addbrother(struct node_list *root_list, struct node *child)
{
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *temp = root_list;
    while(temp->next != NULL)
        temp = temp->next;
    //printf("Adding child %s to list!\n",getCategoryName(child->category));
    temp->next = new;
}

// Appends all nodes in a node list as children to a parent node
void addchildren(struct node *parent, struct node_list *new_children)
{
    struct node_list *temp = new_children->next;
    struct node_list *temp2 = parent->children;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    while(temp->next != NULL)
    {
        temp2->next = temp;
        temp2= temp2->next;
        temp = temp->next;
    }

    if(temp->node != NULL)
    {
        temp2->next = temp;
    }
    // frees old node list
    free(new_children);
}

// Appends all nodes in a node list to another node list.
void addnephews(struct node_list *parent, struct node_list *new_children)
{
    struct node_list *temp = new_children->next;
    struct node_list *temp2 = parent->next;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    while(temp->next != NULL)
    {
        temp2->next = temp;
        temp2= temp2->next;
        temp = temp->next;
    }
    if(temp->node != NULL)
    {
        temp2->next = temp;
    }
    // frees old node list
    free(new_children);
}



// Appends a node to the list of children of the parent node
void addchild(struct node *parent, struct node *child) 
{
    struct node_list *new = malloc(sizeof(struct node_list));
    new->node = child;
    new->next = NULL;
    struct node_list *children = parent->children;
    while(children->next != NULL)
        children = children->next;
    children->next = new;
    //printf("Adding child %s to parent %s!\n",getCategoryName(child->category),getCategoryName(parent->category));
}


// Traverses the AST and prints its content
void show(struct node *node, int depth) 
{
    struct node_list *temp = node->children->next;    
    //if(strcmp(getCategoryName(node->category),"vasv") != 0)
    if(strcmp(getCategoryName(node->category),"Unknown") != 0)
    {
        if(depth > 0)
        {
            for(int i = 0; i < depth; i++)
            {
                printf("..");
            }
        }
        if(node->token != NULL)
        {
            printf("%s(%s)\n",getCategoryName(node->category), node->token->token);
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
    }       
}

// Frees all nodes from syntax tree given root node
void cleanup(struct node *node)
{
    struct node_list *temp = node->children->next;
    
    while(temp != NULL)
    {
        cleanup(temp->node);
        temp = temp->next;
    }
    free(node->children);
    free(node->token);
    //printf("Freeing node %s\n",getCategoryName(node->category));
    num_frees +=1;
    free(node);
}

// Frees all memory allocated in a list of nodes
void cleanlist(struct node_list *node_list)
{
    struct node_list *temp = node_list->next;
    while(temp != NULL)
    {
        cleanup(temp->node);
        temp = temp->next;
    }
    free(node_list);
}

// Inserts the category of the first Declaration in the remaining Declarations, in the scenario of all Declarations being in the same line
// Example: "int a,b,c,d"
void insertType(struct node_list *declaration_list, struct node *target)
{
    struct node_list *temp = declaration_list->next; //first declaration in a list of declaration
    while(temp->next != NULL)
    {
        //temp2->node->category = target->category;
        temp->node->children->next->node->category = target->category;
        temp = temp->next;
    }
    temp->node->children->next->node->category = target->category;
    
}

// Gets the child node given a parent node and its position, starting from zero
struct node *getchild(struct node *parent, int position) {
    struct node_list *children = parent->children;
    while((children = children->next) != NULL)
        if(position-- == 0)
            //if(strcmp(getCategoryName(children->node->category),"Unknown") != 0) return children->node;
            return children->node;
    return NULL;
}

// Gets the child node given a list of nodes and its position, starting from zero
struct node *getchild_in_list(struct node_list *parent, int position) 
{
    struct node_list *temp = parent;
    while((temp = temp->next) != NULL)
        if(position-- == 0)
            if(strcmp(getCategoryName(temp->node->category),"Unknown") != 0) return temp->node;
            //return temp->node;
    return NULL;
}

// Searchs and returns the first node which category isn't 'Unknown'
struct node *search_for_known_node(struct node_list *node_list)
{
    struct node_list *temp = node_list;
    while((temp = temp->next) != NULL)
        if(strcmp(getCategoryName(temp->node->category),"Unknown") != 0) return temp->node;
    return NULL;
}

// Counts the number of children nodes given a parent node
int count_children_in_node(struct node *node)
{
    int i = 0;
    while(getchild(node,i) != NULL)
    {
        i++;
    }
    return i;
}

// Counts the number of nodes given a list of nodes
int count_children_in_list(struct node_list *node_list)
{
    int i = 0;
    struct node_list *temp = node_list;
    while((temp = temp->next) != NULL)
        if(strcmp(getCategoryName(temp->node->category),"Unknown") != 0) i+=1;
    return i;
}

// Prints the number of created and freed nodes for memory leaks debugging
void show_stats()
{
    printf("Number of created nodes: %d\n",num_nodes);
    printf("Number of freed nodes: %d\n",num_frees);
}
