#include "node.h"

void free_list(struct field_node **list){

	struct field_node *p = *list, *temp;
	while (p != NULL){
		temp = p;
		p = p->next;
		free(temp);
	}
	*list = NULL;
}

void delete(struct field_node *field){
	;
	
}

void delete_s(struct field_node **list, char *field_name){
	
	struct field_node *node;
	for (node = *list; node != NULL; node = node->next)
		;
}


struct field_node *add_to_front(struct field_node **list,
	struct field_node *new_field){

	new_field->next = *list;
	*list = new_field;
	return *list;
}

struct field_node *add_to_end(struct field_node *list, 
		struct field_node *new_field){

	struct field_node *node;

	for(node = list; node->next != NULL; node = node->next)
		;

	node->next = new_field;

	return list;
}
