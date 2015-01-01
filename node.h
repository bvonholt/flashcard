#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#define MAX_FIELD_NAME_LENGTH 15
#define MAX_FIELD_TEXT_LENGTH 30


struct field_node {
	char name[MAX_FIELD_NAME_LENGTH];
	char text[MAX_FIELD_TEXT_LENGTH];
	struct field_node *next;
};
#endif
