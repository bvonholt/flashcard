#include "node.h"
#include "word.h"
#include "card.h"
#include <stdio.h>

card_t *make_deck(word_t *words, char *field1, char *field2);
void play_deck(card_t *deck, int deck_size);
int main(void){
	word_t *words = read_words();

	int i;	
	struct field_node *f;

	printf("~~~flashcard~~~\n");
	char input;
	bool quit = false;

	card_t *deck = make_deck(words, "prompt", "word");
	while(!quit){
		printf("~ (V)iew cards, (Q)uit >");
		input = getchar();
		while (input != '\n' && getchar() != '\n')
			input = '\0';
		switch(input){
			case 'v': case 'V':
				play_deck(deck, 3);
				/*view_cards();*/
				break;
			case 'q': case 'Q':
				quit = true;
				break;
			default:
				printf("~ Invalid input.\n");
				
		}
	}
	return 0;

}
/**
 * Creates an array of cards based on a given set of tags
 **/
card_t *make_deck(word_t *words, char *field1, char *field2){
	char *front, *back;
	card_t *cards = malloc(sizeof(card_t) * 3);
	int i;
	for (i = 0; i < 3; i++){
		
		
		cards[i].front = getprompt(words[i], field1);
		cards[i].back = getfield(words[i], field2);
	}
	return cards;
}
/**
 * Takes a user through the process of playing a given deck of
 * cards
 **/
void play_deck(card_t *deck, int deck_size){
	int i;
	for(i = 0; i < deck_size; i++){
		print_front(&deck[i]);
		while (getchar() != '\n')
			;
		print_back(&deck[i]);
		while (getchar() != '\n')
			;
	}
}
