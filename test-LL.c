#include "word.h"
#include "card.h"
#include "node.h"
#include <stdio.h>

#define LIST_SIZE 9

void print_list(struct field_node *node);

int main(void){

	struct field_node *list = NULL, *node;
	
	int i = 0;

	if (LIST_SIZE){
		list = malloc(sizeof(struct field_node));
		list->name[0] = 48 + i;
		list->text[0] = 65 + i;
	}

	node = list;

	for (i = 1; i < LIST_SIZE; i++){
		printf("looping...%d\n", i);

		node->next = malloc(sizeof(struct field_node));
		//printf("node->next gets malloc()\n");
		node = node->next;
		node->name[0] = 48 + i;
		node->text[0] = 65 + i;

	}
	if (node != NULL)
		node->next = NULL;
	print_list(list);


	printf("adding node to beginning of list...\n");
	node = malloc(sizeof(struct field_node));
	node->name[0] = 'X';
        node->text[0] = 'X';	
	add_to_front(&list, node);
	print_list(list);

	printf("deleting list...\n");
	free_list(&list);
	print_list(list);

	printf("adding node to end of list...\n");
	node = malloc(sizeof(struct field_node));
	node->name[0] = 'Y';
        node->text[0] = 'Y';	
	add_to_end(&list, node);
	print_list(list);

	printf("removing node from end of list...\n");
	delete(node);
	
	

	/*delete list*/
	printf("deleting list...\n");
	free_list(&list);
	print_list(list);

	return 0;
}

void print_list(struct field_node *node){
	int i = 0;
	while (node != NULL){
		i++;
		printf(" |\n");
		printf("%c %c\n", node->name[0], node->text[0]);
		node = node->next;
	}
	printf("Number of nodes: %d\n", i);
}

