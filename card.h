#ifndef CARD_H
#define CARD_H

#include <stdbool.h>

/*#define ID_LENGTH 4*/

typedef struct{
	char *front;
	char *back;
	short int word_id;
	bool sucess;
} card_t;

int print_front(card_t card);
int print_back(card_t card);
void shuffle(card_t *deck, int size);

#endif
