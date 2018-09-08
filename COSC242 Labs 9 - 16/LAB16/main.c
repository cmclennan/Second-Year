#include <stdio.h>
#include "mylib.h"
#include "rbt.h"
#include <stdlib.h>

void print_key(char *s){
	printf("%s\n", s);
}

int main(void){
	char word[256];
	char op
	FILE  *infile;

	while (1) {
		rbt b = rbt_new();

		if (NULL == (infile = fopen("/Users/Cameron/Desktop/UNIVERSITY/Second Year/Second Semester/COSC242/LABS/LAB16/search-test.txt", "r"))){
			fprintf(stderr, "file cannot be found\n");
			return EXIT_FAILURE;
		}
		while (2 == fscanf(infile, "%c %255s", &op, word)){
			if ('+' == op){
				printf("insert %s: \n", word);
				b = rbt_insert(b, word);

			} else if ('?' == op) {
				printf("%d %s\n", rbt_search(b, word), word);
			} else if ('-' == op){
				b = rbt_delete(b, word);
				printf("After delete %s, the bst is: \n", word);
				rbt_preorder(b, print_key);
			}
		}
		rbt_free(b);
		fclose(infile);

	}
	return EXIT_SUCCESS;
}