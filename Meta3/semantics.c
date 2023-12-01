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


void check_declaration(struct node *declaration,struct table *scope) 
{
    //type of declaration is obtained through first son(<typespec> node)
    struct node *typespec = getchild(declaration, 0);
    enum type type = category_type(typespec->category);

    //id of declaration is obtained through second son(<identifier> node)
    struct node *id = getchild(declaration,1);
    if(search_symbol(scope, id->token->token) == NULL) 
    {
        insert_symbol(scope, id->token->token, type, declaration);
    } 
    else 
    {
        printf("Line %d, column %d: Symbol %s already defined\n", id->token->line,id->token->column,id->token->token);
        semantic_errors++;
    }
}

void check_statement(struct node *statement,struct table *scope)
{
    switch(statement->category)
    {
        case Store:
        case Comma:
        case Add:
        case Sub:
        case Mul:
        case Div:
        case Mod:
        case And:
        case BitWiseAnd:
        case BitWiseOr:
        case BitWiseXor:
        case Eq:
        case Ne:
        case Le:
        case Ge:
        case Lt:
        case Gt:
            check_statement(getchild(statement,0),scope);
            check_statement(getchild(statement,1),scope);
            break;
        case Plus:
        case Minus:
        case Not:
            check_statement(getchild(statement,0),scope);
            break;
        case Call: break;
        case Identifier:
            break;
        case Natural: 
            statement->type = integer_type;
            break;
        case ChrLit:
            statement->type = char_type;
        case Decimal:
            statement->type = double_type;
            break;
        case If:
            check_statement(getchild(statement,0),scope);
            check_statement(getchild(statement,1),scope);
            check_statement(getchild(statement,2),scope);
            break;
        case While:
            check_statement(getchild(statement,0),scope);
            check_statement(getchild(statement,1),scope);
            break;
        case Return:
            check_statement(getchild(statement,0),scope);
            break;
        default: break;
    }
}

void check_body(struct node *body,struct table *scope)
{
    struct node_list *temp = body->children;
    while( (temp = temp->next) != NULL )
    {
        if(strcmp(getCategoryName(temp->node->category),"Declaration") == 0)
        {
            check_declaration(temp->node,scope);
        }
        else 
        {
            check_statement(temp->node,scope);
        }
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
     // type of function is obtained through first son(<typespec> node)
    struct node *typespec = getchild(function, 0);
    enum type type_function = category_type(typespec->category);

    // id of function is obtained through second son(<Identifier> node)
    struct node *id = getchild(function,1);

    if(function->category == FuncDeclaration)
    {
        if(search_symbol(global, id->token->token) == NULL) //
        {
            insert_symbol(global, id->token->token, type_function, function);
        }
        else
        {
            printf("Line %d, column %d: Symbol %s already defined\n", id->token->line,id->token->column,id->token->token);
            semantic_errors++;
        }
    }
    if(function->category == FuncDefinition)
    {
        struct table *result = search_symbol(global, id->token->token); 
        if(result == NULL) // this function hasn't been declared or defined, so it will be added to global table and will be printed in the end
        {
            insert_symbol(global, id->token->token, type_function, function);
            struct table *scope = (struct table *) malloc(sizeof(struct table));
            scope->next = NULL;
            insert_symbol(scope, "return", type_function, newnode(Return,NULL));

            // list of parameters is obtained through third son(<ParamList> node)
            check_parameters(getchild(function,2),scope);

            // function body is obtained through 4th son(<FuncBody> node)
            check_body(getchild(function,3),scope);

            // insert table in table list
            insert_table(list_tables,scope,id->token->token);
        }
        if(result != NULL && result->node->category == FuncDeclaration)// this function has been declared before with the same identifier
        {
            int num_arguments_definition = count_children_in_node(getchild(function,2));
            int num_arguments_declaration = count_children_in_node(getchild(result->node,2));
            if(num_arguments_declaration != num_arguments_definition)
            {
                printf("Line %d, column %d: wrong number of arguments to function %s (got %d, required %d)\n", id->token->line,id->token->column,id->token->token,num_arguments_definition,num_arguments_declaration);
                semantic_errors++;
            }
            else
            {
                struct table *scope = (struct table *) malloc(sizeof(struct table));
                scope->next = NULL;
                insert_symbol(scope, "return", type_function, newnode(Return,NULL));

                // list of parameters is obtained through third son(<ParamList> node)
                check_parameters(getchild(function,2),scope);

                // function body is obtained through 4th son(<FuncBody> node)
                check_body(getchild(function,3),scope);

                // insert table in table list
                insert_table(list_tables,scope,id->token->token);
            }
            
        } 

    }
    
    

    
}


// semantic analysis begins here, with the AST root node
int check_program(struct node *program) 
{
    global = (struct table *) malloc(sizeof(struct table));
    global->next = NULL;

    struct node *temp = newnode(FuncDeclaration,NULL);
    struct node *temp2 = newnode(ParamList,NULL);
    struct node *temp3 = newnode(ParamDeclaration,NULL);
    addchild(temp,newnode(Int,NULL));
    addchild(temp,newnode(Identifier, create_token("putchar",0,0)));

    addchild(temp3,newnode(Int,NULL));
    addchild(temp2,temp3);
    addchild(temp,temp2);
    insert_symbol(global, "putchar", integer_type, temp);

    struct node *temp4 = newnode(FuncDeclaration,NULL);
    struct node *temp5 = newnode(ParamList,NULL);
    struct node *temp6 = newnode(ParamDeclaration,NULL);
    addchild(temp4,newnode(Int,NULL));
    addchild(temp4,newnode(Identifier, create_token("getchar",0,0)));

    addchild(temp6,newnode(Void,NULL));
    addchild(temp5,temp6);
    addchild(temp4,temp5);
    insert_symbol(global, "getchar", integer_type, temp4);

    list_tables = (struct table_list *) malloc(sizeof(struct table_list));
    list_tables->next = NULL;

    struct node_list *child = program->children;
    while((child = child->next) != NULL)
    {
        if( strcmp(getCategoryName(child->node->category),"Declaration") == 0 ) check_declaration(child->node,global);
        if( strcmp(getCategoryName(child->node->category),"FuncDefinition") == 0 || strcmp(getCategoryName(child->node->category),"FuncDeclaration") == 0) check_function(child->node);
    }
    return semantic_errors;
}



void show_function(struct table *symbol)
{
    //tab
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
    //int num_arguments;
    struct table *symbol;
    struct table_list *list;
    //struct node *temp;
    printf("===== Global Symbol Table =====\n");
    for(symbol = global->next; symbol != NULL; symbol = symbol->next)
    {
        if(strcmp(getCategoryName(symbol->node->category),"Declaration") == 0) printf("%s   %s\n", symbol->identifier, type_name(symbol->type));
        if(strcmp(getCategoryName(symbol->node->category),"FuncDefinition") == 0 || strcmp(getCategoryName(symbol->node->category),"FuncDeclaration") == 0) show_function(symbol);
    }

    for(list = list_tables->next; list != NULL; list = list->next)
    {
        printf("\n===== Function %s Symbol Table =====\n",list->function_name);
        for(symbol = list->table->next; symbol != NULL; symbol = symbol->next)
        {
            //tab
            printf("%s  %s", symbol->identifier, type_name(symbol->type));
            if(strcmp(getCategoryName(symbol->node->category),"ParamDeclaration") == 0)
            {
                //tab
                printf("    param\n");
            }
            else printf("\n");
            
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


