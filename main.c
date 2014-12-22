#include "word.h"
#include "card.h"

int main(void){
	word_t *words = read_words();
	for (int i = 0; i < sizeof words / sizeof(word_t); i++)
		free(words[i].field
	free(words);
	return 0;
}

	
