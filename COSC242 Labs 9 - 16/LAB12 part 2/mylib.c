#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

void *emalloc(size_t s){
	void *result = malloc(s);
	if(result == NULL){
	fprintf(stderr, "malloc failed");
	exit(EXIT_FAILURE;
	}
	return result;	
}

void *remalloc(void *p, size_t s) {
	void *result = realloc(p, s);
	if (result == NULL) {
		fprintf(stderr, "malloc failed");
		exit(EXIT_FAILURE);
	}
	return result;
}

unsigned int htable_word_to_int(char *word) {
	unsigned int result = 0;

	while (*word != '\0') {
		result = (*word++ + 31 * result);
	}
	return result;
}

int getword(char *s, int limit, FILE *stream){
	int c;
	char *w = s;
	assert(limit > 0 && s != NULL && stream != NULL);
	while(!isalnum(c = getc(stream)) && EOF != c) {
		if (EOF == c){
			return EOF;
		} else if(--limit > 0){
			*w++ = tolower(c);
		}
		while(--limit > 0){
			if (isalnum(c = getc(stream))){
				*w++ = tolower(c);
			} else if ('\'' == c){
				limit++;
			} else {
				break;
			}
		}
		*w = '\0';
		return w - s;
	}
}
