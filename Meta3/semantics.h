#ifndef _SEMANTICS_H
#define _SEMANTICS_H

#include "ast.h"

int check_program(struct node *program);

struct table {
	char *identifier;
	enum type type;
	struct node *node;
	struct table *next;
};

struct table_list {
	struct table *table;
	char *function_name;
	struct table_list *next;
};

struct table *insert_symbol(struct table *table, char *identifier, enum type type, struct node *node);
struct table *search_symbol(struct table *table, char *identifier);

struct table_list *insert_table(struct table_list *table_list,struct table *table,char *function_name);
struct table_list *search_function(struct table_list *table_list, char *identifier);

void show_symbol_tables();
void show_annoted_AST(struct node *node, int depth, struct table *table);
void cleanup_symbol_tables();

#endif
