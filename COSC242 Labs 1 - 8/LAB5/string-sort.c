#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_WORDS 10


void *emalloc(size_t s) {
	void *result = malloc(s);
	if (NULL == result) {
		fprintf(stderr, "Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	return result;
}


void insertion_sort(char **a, int size) {
	int p, d;
	char *key;
	for (p = 1; p < size; p++){
		key = a[p];
		d = p - 1;
		while (a[d] > key && d >= 0){
			a[d+1] = a[d];
			d = d-1;
		}
		printf("a[d+1]: %s, key is: %s\n", a[d+1], key);
		a[d+1] = key;
	}
}


int main(void) {
	char word[80];
	char *wordlist[NUM_OF_WORDS];

	double average;
	int i, j;
	i = 0;
	while (i < NUM_OF_WORDS && 1 == scanf("%79s", word)) {
		wordlist[i] = emalloc((strlen(word) + 1) * sizeof wordlist[0][0]);
		strcpy(wordlist[i], word);
		i++;
	}
	

	for (i = 0; i < NUM_OF_WORDS; i++) {
		 printf("%s\n", wordlist[i]);
	}

	insertion_sort(wordlist, NUM_OF_WORDS);

	for (j = 0; j < i; j++) {
		free(wordlist[i]);
		printf("%s\n", wordlist[i]);
	}
	return EXIT_SUCCESS;

}