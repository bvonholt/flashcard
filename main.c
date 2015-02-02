#include "node.h"
#include "word.h"
#include "card.h"
#include <stdio.h>
#include <string.h>

card_t *make_deck(word_t *words, char *field1, char *field2);
void modify_word(word_t *word);
void edit_words(word_t *word);
void play_deck(card_t *deck, int deck_size);

int main(void){
	word_t *words = read_words();

	int i;	

	printf("%s", getprompt(words[0]));		
	printf("~~~flashcard~~~\n");
	char input;
	bool quit = false;

	card_t *deck = make_deck(words, "prompt", "word");
	while(!quit){
		printf("~ (V)iew cards, (A)dd words, (Q)uit >");
		input = getchar();
		while (input != '\n' && getchar() != '\n')
			input = '\0';
		switch(input){
			case 'v': case 'V':
				play_deck(deck, 3);
				/*view_cards();*/
				break;
			case 'a': case 'A':
				edit_words(words);
			case 'q': case 'Q':
				quit = true;
				break;
			default:
				printf("~ Invalid input.\n");
				
		}
	}
	write_words(words);

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
void edit_words(word_t *word){
	
	char input;
	bool quit = false;

	while(!quit){
		printf("(A)dd, (D)elete, (M)odify, (Q)uit >");
		input = getchar();
		while (input != '\n' && getchar() != '\n')
			input = '\0';
		switch(input){
			case 'a': case 'A':	//add word
				break;
			case 'd': case 'D':	//delete word
				break;
			case 'm': case 'M':	//modify word
				modify_word(&word[0]);
				break;

			case 'q': case 'Q':	//quit
				return;
			default:
				printf("~ Invalid input.\n");
				
		}
	}

}
void modify_word(word_t *word){
	char *str, *name, *text;
	str = malloc(sizeof(char) * 80);
	int i;
 
	char *fieldstr = getprompt(word->fields);
	nextfield(NULL, NULL, word->fields);
	do {
		//get change for field name
		printf("%s", fieldstr);
		printf("Type change to name (enter=no change):");
		for (i = 0; (str[i] = getchar()) != '\n' && i < 80; i++)
			;
		str[i] = '\0';
		if(i != 0){		//no change was entered
			name = malloc(sizeof(char) * (i + 1));
			strcpy(name, str);
		}

		//get change for field text
		printf("Type change to text (enter=no change):");
		for (i = 0; (str[i] = getchar()) != '\n' && i < 80; i++)
			;
		str[i] = '\0';

		if(i != 0){		//no change was entered
			name = malloc(sizeof(char) * (i + 1));
			strcpy(name, str);
		}
		fieldstr = nextfield(name, text, NULL);
		name = NULL, text = NULL;		//reset so for nextfield() next iteration
	} while (fieldstr != NULL);

	free(str);
	return;
}
