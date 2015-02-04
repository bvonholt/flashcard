#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#define MAX_FIELD_NAME_LENGTH 15
#define MAX_FIELD_TEXT_LENGTH 30


struct field_node {
	char *name;
	char *text;
	struct field_node *next;
};

//struct field_node *add_to_end(struct field_node **list, struct field_node *new_field);
//void free_list(struct field_node **list);

#endif
