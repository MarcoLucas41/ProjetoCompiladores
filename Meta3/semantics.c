#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

//global symbol table
struct table *global;

//list of function tables
struct table_list *list_tables;


void check_declaration(struct node *declaration) 
{
    //type of declaration is obtained through first son(<typespec> node)
    struct node *typespec = getchild(declaration, 0);
    enum type type = category_type(typespec->category);

    //id of declaration is obtained through second son(<identifier> node)
    struct node *id = getchild(declaration,1);
    if(search_symbol(global, id->token->token) == NULL) 
    {
        insert_symbol(global, id->token->token, type, declaration);
    } 
    else 
    {
        printf("Line %d, column %d: Symbol %s already defined\n", id->token->line,id->token->column,id->token->token);
        semantic_errors++;
    }
}

void check_parameters(struct node *param_list,struct table *scope)
{
    struct node *typespec;
    struct node *identifier;
    enum type type_parameter;
    struct node_list *parameter = param_list->children;
    while((parameter = parameter->next) != NULL)
    {
        typespec = getchild(parameter->node, 0);
        type_parameter = category_type(typespec->category);
        identifier = getchild(parameter->node,1);
        if(identifier != NULL)
        {
            if(search_symbol(scope,identifier->token->token) == NULL)
            {
                insert_symbol(scope,identifier->token->token,type_parameter,parameter->node);
            }
            else
            {
                printf("Line %d, column %d: Symbol %s already defined\n", identifier->token->line,identifier->token->column,identifier->token->token);
                semantic_errors++;
            }
        }
    }
}

void check_function(struct node *function)
{
     //type of function is obtained through first son(<typespec> node)
    struct node *typespec = getchild(function, 0);
    enum type type_function = category_type(typespec->category);

    //id of function is obtained through second son(<Identifier> node)
    struct node *id = getchild(function,1);
    if(search_symbol(global, id->token->token) == NULL) 
    {
        insert_symbol(global, id->token->token, type_function, function);
        struct table *scope = (struct table *) malloc(sizeof(struct table));
        scope->next = NULL;

        insert_symbol(scope, "return", type_function, newnode(Return,NULL)); 

        //list of parameters is obtained through third son(<ParamList> node)
        check_parameters(getchild(function,2),scope);

        //insert table in table list
        insert_table(list_tables,scope,id->token->token);
    } 
    else 
    {
        printf("Line %d, column %d: Symbol %s already defined\n", id->token->line,id->token->column,id->token->token);
        semantic_errors++;
    }

    
}


// semantic analysis begins here, with the AST root node
int check_program(struct node *program) 
{
    global = (struct table *) malloc(sizeof(struct table));
    global->next = NULL;

    list_tables = (struct table_list *) malloc(sizeof(struct table_list));
    list_tables->next = NULL;

    struct node_list *child = program->children;
    while((child = child->next) != NULL)
    {
        if( strcmp(getCategoryName(child->node->category),"Declaration") == 0 ) check_declaration(child->node);
        if( strcmp(getCategoryName(child->node->category),"FuncDefinition") == 0 || strcmp(getCategoryName(child->node->category),"FuncDeclaration") == 0) check_function(child->node);
    }
    return semantic_errors;
}



void show_function(struct table *symbol)
{
    printf("%s  %s(", symbol->identifier, type_name(symbol->type));
    struct node *typespec;
    struct node *param_list = getchild(symbol->node,2);
    enum type type_parameter;

    struct node_list *parameter = param_list->children;
    while((parameter = parameter->next) != NULL)
    {
        typespec = getchild(parameter->node, 0);
        type_parameter = category_type(typespec->category);
        if(parameter->next == NULL) printf("%s",type_name(type_parameter));
        else printf("%s,",type_name(type_parameter));
    }
    printf(")\n");
}
void show_symbol_tables() 
{
    struct table *symbol;
    struct table_list *list;
    printf("==== Global Symbol Table ====\n");
    for(symbol = global->next; symbol != NULL; symbol = symbol->next)
    {
        if(strcmp(getCategoryName(symbol->node->category),"Declaration") == 0) printf("%s  %s\n", symbol->identifier, type_name(symbol->type));
        if(strcmp(getCategoryName(symbol->node->category),"FuncDefinition") == 0 ) show_function(symbol);
    }

    for(list = list_tables->next; list != NULL; list = list->next)
    {
        printf("\n==== Function %s Symbol Table ====\n",list->function_name);
        for(symbol = list->table->next; symbol != NULL; symbol = symbol->next)
        {
            printf("%s  %s\n", symbol->identifier, type_name(symbol->type));
        }


    }
}










struct table_list *insert_table(struct table_list *table_list,struct table *table,char *function_name)
{
    struct table_list *new = (struct table_list *) malloc(sizeof(struct table_list));
    new->table = table;
    new->function_name = function_name;
    new->next = NULL;
    struct table_list *temp = table_list;
    while(temp != NULL) 
    {
        if(temp->next == NULL) 
        {
            temp->next = new;    /* insert new symbol at the tail of the list */
            break;
        } /*else if(strcmp(temp->next->identifier, identifier) == 0) {
            free(new);
            return NULL;           // return NULL if symbol is already inserted 
        }*/
        temp = temp->next;
    }
    return new;
}




// insert a new symbol in the list, unless it is already there
struct table *insert_symbol(struct table *table, char *identifier, enum type type, struct node *node) {
    struct table *new = (struct table *) malloc(sizeof(struct table));
    new->identifier = strdup(identifier);
    new->type = type;
    new->node = node;
    new->next = NULL;
    struct table *temp = table;
    while(temp != NULL) {
        if(temp->next == NULL) {
            temp->next = new;    /* insert new symbol at the tail of the list */
            break;
        } else if(strcmp(temp->next->identifier, identifier) == 0) {
            free(new);
            return NULL;           /* return NULL if symbol is already inserted */
        }
        temp = temp->next;
    }
    return new;
}

// look up a symbol by its identifier
struct table *search_symbol(struct table *table, char *identifier) {
    struct table *symbol;
    for(symbol = table->next; symbol != NULL; symbol = symbol->next)
        if(strcmp(symbol->identifier, identifier) == 0)
            return symbol;
    return NULL;
}


