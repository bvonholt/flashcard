#ifndef WORD_H
#define WORD_H

#include "node.h"

#define FILE_ERROR 1
#define MAX_FIELD_NAME_LENGTH 15
#define MAX_FIELD_TEXT_LENGTH 30
#define TAG_FIELD_LENGTH 40
#define NUM_ID_DIGITS 4

#define WORDS_FILE "words.data"

typedef struct {
	struct field_node *fields;
	char *tags;
	char word_id[NUM_ID_DIGITS];
} word_t;

word_t *read_words();

#endif
