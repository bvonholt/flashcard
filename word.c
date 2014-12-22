#include "word.h"
#include <stdlib.h>
#include <stdio.h>

word_t *read_words(){

	/*file pointer*/
	FILE *data_file;

	/*make sure file exists and can be opened*/
	if ( (data_file = fopen(WORDS_FILE, "r")) == NULL){
		printf("Could not open file\n");
		exit(FILE_ERROR);
	}

	//counters
	int i, j;
	//containers
	char * ch, line[50];


	/*read number of words from first line in file*/
	char *p;
	int num_of_words = strtol(fgets(line, 50, data_file), &p, 10);
	printf("%d", num_of_words);


	/*initialize array of words*/
	word_t *words = malloc(sizeof(word_t) * num_of_words);

	/*loop through file line by line until a line cannot be read*/
	for (i = 0; i < num_of_words; i++){

		/* make sure that file is not currupted and
		 * has fewer entries than listed.*/
		if (fgets(line, 50, data_file) == NULL){
			free(words);
			exit(FILE_ERROR);
		}

		ch = line;

		/*read word id from line*/
		for (j = 0; *ch != '*'; j++){
			words[i]->word_id[j]=*ch++;
		}
		
		/*make sure the string is null terminated*/
		words[i]->word_id[3] = '\0';

		/*loop through fields*/
		field_node *fn = words[i].fields;
		while(++ch != '*'){
			/*read field name*/
			for(j = 0; *ch != ':'; j++){
				words[i]->[j] = *ch++;
			}
			/*read field text*/
			for(j = 0; *ch != ','; j++){
				words[i]->back[j] = *ch++;
			}
		}
		words[i]->back[j--] = '\0';
	}
	fclose(data_file);
	return words;
}
