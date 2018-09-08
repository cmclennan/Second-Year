#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include <htable.h>

static void print_info(int freq, char *word){
	printf("%-4d %s\n", freq, word);
}

int main(void) {
	htable h = htable_new(113);
	char word[256];

	file *infile = NULL;

	char *fileToCheck = "/Users/Cameron/Desktop/UNIVERSITY/
	Second Year/Second Semester/COSC242/LABS/LAB12/dictionary.txt";

	if (NULL == (infile =fopen(fileToCheck, "r"))){
		fprintf(stderr, "cannot file file \n");
		return EXIT_FAILURE;
	}

	while (getword(word, sizeof word, infile) != EOF) {
		htable_insert(h, word);
	}
	htable_print(h, print_info);
	htable_free(h);
	fclose(infile);
	return EXIT_SUCCESS;
}