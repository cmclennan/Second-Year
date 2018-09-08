#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define array_size 100
#define word_len 80

void *emalloc(size_t s){
	void *result = malloc(s);
	if(NULL == result){
		fprintf(stderr, "malloc error has occurred");
		exit(EXIT_FAILURE);
	}
	return result;
}

void print_array(char **array, double average, unsigned int count){
	if (count > 0){
		if(strlen(array[0]) > average){
			printf("%s\n", array[0]);
		}
		print_array(array+1, average, count-1);
	}
}

int main(void){
	int i = 0;
	int count = 0;
	double total = 0.0;
	char *word_array[array_size];
	char word[word_len];

	while (count < array_size && 1 == scanf("%s", word)){
		word_array[count] = emalloc((strlen(word)+1) *sizeof word_array);		strcpy(word_array[count], word);
		total += strlen(word);
		count++;
	}

	if (count != 0){
		fprintf(stderr, "%.2f\n", total / count);
		print_array(word_array, total / count, count);
	}

	for (i = 0; i < count; i++){
		free(word_array[i]);
	}
	return EXIT_SUCCESS;
}