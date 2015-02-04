#ifndef WORD_H
#define WORD_H

#include "node.h"

#define FILE_ERROR 1
#define LINE_OUT_OF_BOUNDS_ERROR 2

#define MAX_LINE_LEN 200
#define NUM_ID_DIGITS 3

#define WORDS_FILE "words.data"

typedef struct {
	struct field_node *fields;
	char *tags;
	char word_id[NUM_ID_DIGITS + 1];
} word_t;

word_t *read_words();

#endif
