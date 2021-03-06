#include <stdio.h>
#include "mylib.h"
#include "bst.h"
#include <stdlib.h>

void print_key(char *s){
	printf("%s\n", s);
}

int main(void){
	char word[256];
	char op
	FILE  *infile;

	while (1) {
		bst b = bst_new();

		if (NULL == (infile = fopen("/Users/Cameron/Desktop/UNIVERSITY/Second Year/Second Semester/COSC242/LABS/LAB14/search-test.txt", "r"))){
			fprintf(stderr, "file cannot be found\n");
			return EXIT_FAILURE;
		}
		while (2 == fscanf(infile, "%c %255s", &op, word)){
			if ("+" == op){
				b = bst_insert(b, word);
			} else if ("?" == op) {
				printf("%d %s\n", bst_search(b, word), word);
			} else if ("-" == op){
				b = bst_delete(b, word);
				printf("After delete %s, the bst is: \n", word);
				bst_preorder(b, print_key);
			}
		}
		bst_free(b);
		fclose(infile);

	}
	return EXIT_SUCCESS;
}