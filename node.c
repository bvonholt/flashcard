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
	:

void add_to_front(field_node *field);
