#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size 100
#define word_len 80


void *emalloc(size_t s) {
	void *result = malloc(s);
	if (NULL == result){
		fprintf(stderr, "Malloc failed");
		exit(EXIT_FAILURE);
	}
	return result;
}

void print_array(char **array, double average, unsigned int count) {
	if (count > 0){
		if(strlen(array[0]) > average) {
			printf("%s\n", array[0]);
		}
		print_array(array +1, average, count -1);
	}
}

int main(void){
	int i = 0;
	int count;
	double total = 0.0;
	char *wordArray[array_size];
	char word[word_len];

	count = 0;
	while (count < array_size && 1 == scanf("%s", word)) {
		wordArray[count] = emalloc((strlen(word) +1) *sizeof wordArray);
		strcpy(wordArray[count], word);
		total += strlen(word);
		count++;
	}
	if (count != 0){
		fprintf(stderr, "%.2f\n", total / count);
		print_array(wordArray, total / count, count);
	}

	for (i = 0; i < count; i++){
		free(wordArray[i]);
	}
	return EXIT_SUCCESS;
}