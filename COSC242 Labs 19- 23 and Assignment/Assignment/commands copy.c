#include <stdio.h>
#include "mylib.h"
#include "bst.h" // not bst but other stuff
#include <stdlib.h>

void print_key(char *s){
	printf("%s\n", s);
}

int main(int argc, char **argv){
	htable h = htable_new();
	char word[256];
	char op;
	FILE  *infile = fopen(argv[1], "r");
// come back to dis
	while (1 = fscanf(infile, "%s", word)) {
		if (NULL == infile){
			fprintf(stderr, "file cannot be found\n");
			return EXIT_FAILURE;
		} else {
			htable_insert(h, word);
		}
		while (2 == scanf("%c %255s", &op, word)){
			if ("-r" == op){
				
			} else if ("-s table-size" == op) {
				
			} else if ("-p" == op){
				htable_print(h, stdout);
			} else if ("-i" == op){
				fprintf(stderr, "Fill time : %.6f\n Search time : %.6f\n 
					Unknown words : %d\n", 0.1, 0.2, 5);
				//come back to later
			} else if ("-h" == op) {
				fprintf(stderr, "In order to simply run the program, one 
					must type './asgn dictionary.txt < document.txt'. \n 
					The command '-r'allows a red-black tree to be used as the 
					hash tables container type. \n  
					The command '-s table_size sets table size. \n 
					The command '-p'  prints the hash table
					to stdout one line per non-empty container. \n 
					The command'-i' prints information to stderr about hash 
					table fill time, hash table search time and unknown words.
					\n 
					The command '-h' prints this help message to stderr. \n");
				break;
			} else if ("" == op) {
				htable_insert();
			} else {
				fprintf(stderr, "%c\n is an invalid command");
			}
		}
		htable_free();
		fclose(infile);

	}
	return EXIT_SUCCESS;
}