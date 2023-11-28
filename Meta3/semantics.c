#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "semantics.h"

int semantic_errors = 0;

//global symbol table
struct symbol_list *symbol_table;


void check_declaration(struct node *declaration) 
{
    //type of declaration is obtained through first son(<typespec> node)
    struct node *typespec = getchild(declaration, 0);
    enum type type = category_type(typespec->category);

    //id of declaration is obtained through second son(<identifier> node)
    struct node *id = getchild(declaration,1);
    if(search_symbol(symbol_table, id->token) == NULL) 
    {
        insert_symbol(symbol_table, id->token, type, declaration);
    } 
    else 
    {
        printf("Identifier %s already declared\n", id->token);
        semantic_errors++;
    }
}



// semantic analysis begins here, with the AST root node
int check_program(struct node *program) 
{
    symbol_table = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    symbol_table->next = NULL;
    insert_symbol(symbol_table, "putchar", no_type, newnode(FuncDeclaration, NULL)); /* predeclared declarations (no children) */
    insert_symbol(symbol_table, "getchar", no_type, newnode(FuncDeclaration, NULL));
    struct node_list *child = program->children;
    while((child = child->next) != NULL)
    {
        //if(strcmp(getCategoryName(child->node->category),"FuncDefinition") == 0) check_declaration_definition(child->node);
        //if(strcmp(getCategoryName(child->node->category),"FuncDeclaration") == 0) check_declaration_declaration(child->node);
        if(strcmp(getCategoryName(child->node->category),"Declaration") == 0) check_declaration(child->node);
    }
    return semantic_errors;
}

// insert a new symbol in the list, unless it is already there
struct symbol_list *insert_symbol(struct symbol_list *table, char *identifier, enum type type, struct node *node) {
    struct symbol_list *new = (struct symbol_list *) malloc(sizeof(struct symbol_list));
    new->identifier = strdup(identifier);
    new->type = type;
    new->node = node;
    new->next = NULL;
    struct symbol_list *symbol = table;
    while(symbol != NULL) {
        if(symbol->next == NULL) {
            symbol->next = new;    /* insert new symbol at the tail of the list */
            break;
        } else if(strcmp(symbol->next->identifier, identifier) == 0) {
            free(new);
            return NULL;           /* return NULL if symbol is already inserted */
        }
        symbol = symbol->next;
    }
    return new;
}

// look up a symbol by its identifier
struct symbol_list *search_symbol(struct symbol_list *table, char *identifier) {
    struct symbol_list *symbol;
    for(symbol = table->next; symbol != NULL; symbol = symbol->next)
        if(strcmp(symbol->identifier, identifier) == 0)
            return symbol;
    return NULL;
}

void show_symbol_tables() 
{
    struct symbol_list *symbol;
    printf("==== Global Symbol Table ====\n");
    for(symbol = symbol_table->next; symbol != NULL; symbol = symbol->next)
    {
        printf("%s  %s\n", symbol->identifier, type_name(symbol->type));
    }
}