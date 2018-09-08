#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

void *emalloc(size_t s){
	void *result = malloc(s);
	if (result == NULL){
		fprintf(stderr, "malloc failure");
		exit(EXIT_FAILURE);
	}
	return result;
}

void *remalloc(void *p, size_t s){
	void *result = realloc(p, s);
	if (result == NULL){
		fprintf(stderr, "malloc error");
		exit(EXIT_FAILURE);
	}
	return result;
}

unsigned int word_to_int(char *word){
	unsigned int result = 0;
	while (*word != '\0'){
		result = (*word++ + 31 * result);
	}
	return result;
}