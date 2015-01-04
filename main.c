#include "node.h"
#include "word.h"
#include "card.h"
#include <stdio.h>

int main(void){
	word_t *words = read_words();

	//while(words++ != NULL)
	int i;	
	struct field_node *f;
	for(i = 0; i < 3; i++){
		printf("id: %s\n", words[i].word_id);
		for(f = words[i].fields; f != NULL; f = f->next){
			printf("name: %s\t", f->name);
			printf("text: %s\n", f->text);
		}
	}
	return 0;
}
