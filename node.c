#include "node.h"
#include <string.h>

/**
 * Takes a pointer to a pointer to a field_node structure
 * (representing a pointer to a list of fields), and iterates
 * through the list, freeing the memory for each node.  Last,
 * it sets the list pointed to to NULL.
 **/
void free_list(struct field_node **list){

	struct field_node *p = *list, *temp;
	while (p != NULL){
		temp = p;
		p = p->next;
		free(temp);
	}
	*list = NULL;
}

void deletenext(struct field_node *field){
	struct field_node *temp = field->next;

	if(temp)
		field = temp->next;
	
}

void delete_s(struct field_node **list, char *field_name){
	
	struct field_node *node;
	for (node = *list; node != NULL; node = node->next)
		;
}

/**
 * adds a field to the front of a list.
 **/
struct field_node *add_to_front(struct field_node **list,
	struct field_node *new_field){

	if (*list != NULL)
		new_field->next = *list;
	*list = new_field;
	return *list;
}
/**
 * Adds a field to the end of a list.
 **/
struct field_node *add_to_end(struct field_node **list, 
		struct field_node *new_field){

	struct field_node *node;

	if(*list == NULL){
		*list = new_field;
		return *list;
	}

	for(node = *list; node->next != NULL; node = node->next)
		;

	node->next = new_field;

	return *list;
}

char *tostr(struct field_node *node){

	if (node == NULL)
		return NULL;

	char *str = malloc(sizeof(char) * (strlen(node->name) + strlen(node->text) + 3));

	if(str == NULL)
		exit(1);

	strcpy(str, node->name);
	strcat(str, ": ");
	strcat(str, node->text);
	return str;
}

/**
 * Searches for a node with a given name.  Returns the node if
 * found, NULL otherwise.
 **/
struct field_node *getnode(struct field_node *list, char *name){
	struct field_node *node;
	for (node = list; node != NULL; node = node->next){
	      	if (strcmp(node->name, name) == 0)	
			return node;
	}
	return NULL;
}
/**
 * Iterates through the list, counting nodes.  Returns the count.
 **/
int count_fields(struct field_node *list){

	int i;
	for (i = 0; list != NULL; list = list->next)
		i++;
	return i;
}
