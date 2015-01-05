#include "word.h"
#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Reads a list of words from a data file.  Returns a pointer
 * to an array of word_t structures.
**/
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
	char * ch, line[90];


	/*read number of words from first line in file*/
	char *p;
	int num_of_words = strtol(fgets(line, 50, data_file), &p, 10);

	/*initialize array of words*/
	word_t *words = malloc(sizeof(word_t) * num_of_words);
	struct field_node *new_field;

	/*loop through file line by line until a line cannot be read*/
	for (i = 0; i < num_of_words; i++){

		/* make sure that file is not currupted and
		 * has fewer entries than listed.*/
		if (fgets(line, 90, data_file) == NULL){
			free(words);
			exit(FILE_ERROR);
		}

		ch = line;
		/*read word id from line*/
		for (j = 0; *ch != '*'; j++){
			words[i].word_id[j]=*ch++;
		}
		
		/*make sure the string is null terminated*/
		words[i].word_id[3] = '\0';

		/*loop through fields*/
		ch++;
		while(*ch != '*'){
			new_field = malloc(sizeof(struct field_node));
			/*read field name*/
			for(j = 0; *ch != ':'; j++){
				new_field->name[j] = *ch++;
			}
			new_field->name[j] = '\0';

			/*skilp colon character*/
			ch++;
			/*read field text*/
			for(j = 0; *ch != ','; j++){
				new_field->text[j] = *ch++;
			}
			ch++;
			new_field->text[j] = '\0';
			add_to_end(&(words[i].fields), new_field);

		}
	}
	fclose(data_file);
	return words;
}
/**
 * writes a given list of words to file
 **/
void write_words(word_t word){
	FILE *data_file; 	

	/*make sure file exists and can be opened*/
	if ( (data_file = fopen(WORDS_FILE, "w")) == NULL){
		printf("Could not open file\n");
		exit(FILE_ERROR);
	}
	
	fclose(data_file);
}
/**
 * searches for a field named "prompt" in the list of fields
 * for a given word.  Returns the text string
 * for that field if found, NULL otherwise.
 **/
char *getprompt(word_t word){

	struct field_node *field;
     	field = getnode(word.fields, "prompt");
	if (!field)
		return NULL;

	char *str;
	str = malloc(sizeof(char) * (strlen(field->text)) + 1);
	strcpy(str, field->text);
	return str;

}
	
/**
 * searches for a field of given name in the list of fields
 * for a given word.  Returns a "[name]:[text]" string
 * for that field if found, NULL otherwise.
 **/
char *getfield(word_t word, char *name){
	struct field_node *field;
     	field = getnode(word.fields, name);
	if (!field)
		return NULL;
	
	char *str;
	str = malloc(sizeof(char) * (strlen(field->name) + strlen(field->text) + 3));
	strcpy(str, field->name);
	strcat(str, ": ");
	strcat(str, field->text);
	return str;
}
