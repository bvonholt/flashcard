#include "node.h"

void delete_list(field_node **list){

	field_node p = *list, temp;
	while (p != NULL){
		temp = p;
		p = p.next;
		free(temp);
	}
	*list = NULL;
}

void delete(field_node *field){

void delete_s(field_node **list, char *field_name){
	
	for (node = *list; node != NULL; node = node.next)
}


field_node *add_to_front(field_node **list, field_node *new_field){
	new_field.next = *list;
	*list = new_field;
	return list;
}

field_node *add_to_end(field_node *list, field_node *new_field){

	field_node *node;

	for(node = list; node.next != NULL; node = node.next)
		;

	node.next = new_field;

	return list;
}
