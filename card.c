#include "card.h"
#include <stdio.h>

void print_front(card_t* c){
	printf("\t\t....................\n");
	printf("\t\t.                  .\n");
	printf("\t\t." " %-17s"       ".\n", c->front);
	printf("\t\t.                  .\n");
	printf("\t\t....................\n");
}
void print_back(card_t* c){
	printf("\t\t....................\n");
	printf("\t\t.                  .\n");
	printf("\t\t." " %-17s"       ".\n", c->back);
	printf("\t\t.                  .\n");
	printf("\t\t....................\n");
}

void shuffle(card_t *deck, int size){
	;
}
