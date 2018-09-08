/* COSC242 Assignment
 * Group 15
 * 2017
 */


#include <stdio.h>
#include "mylib.h"
#include "bst.h" 
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

#define RBT 1
#define FLEX 0

/*
 * Function: print_key
 * -------------------
 * prints the key out, while talking a pointer to a character.
 *
 * *s: pointer to point to a character, or in this case the key.
 * 
 * returns nothing.
*/

void print_key(char *s){
	printf("%s\n", s);
}

/*
 * Function: print_help
 * --------------------
 * Prints the help menu out, when the command "-h" is called on the command 
 * line.
 *
 * Does not take any inputs.
 * 
 * returns: EXIT_FAILURE so that the user can continue to try and run the 
 * program.
*/

void print_help() {
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
	return EXIT_FAILURE;

}
/*
 * Function: void_search
 * ---------------------
 *  Starts a clock, runs a while loop that takes a word that is read
 *  in and uses an if loop which calls htable_search to see if that word is 
 *  in the dictionary, and if it is not it increments the unknown_words
 *  count by 1.
 *
 *  @param h: The htable
 *  @param word: Pointer to a word
 * 
 *  @returns nothing.	
*/




void word_search() {
	start = clock();
	while(getword(word, sizeof word, stdin) != EOF){
		if(htable_search(h, word) == 0){
			printf("%s\n", word);
			unknown_words++;
			}
	}
	end = clock();
	time_search = (end-start)/CLOCKS_PER_SEC;
}


/*
 * Function: main
 * --------------
 *  Holds all variable initialisations, deals with the command line arguments
 *  with a while loop with switch cases, and then deals with htable calls for 
 *  creation of the htable and filling and timing the fill of htable.
 *
 *  argc: The amount of arguments that passed into the program.
 *  **argv: The pointer to a char pointer.
 * 
 *  Returns: EXIT_SUCCESS to finish the program so that it doesn't keep running
 *  and terminal can be used again. It will also print out an error if an invalid 
 *  command is used, or if no arguement is given for 
 */

int main(int argc, char **argv){
	char word[256];
	const char *opstring = "-s:-r-p-i-h";
	char option;
	int size = 3877; 
	htable h = NULL;
	clock_t start, end;
	float time_fill;
	float time_search;
	int unknown_words;

	while ((option = getopt(argc, argv, optstring)) != EOF){
		switch (option){
			case '-s':
				size = atoi(optarg);
			case '-r':
				h = htable_new(size,RBT);
			case '-p':
				htable_print(h, stdout);
			case '-i':
				fprintf(stderr, "Fill time : %.6f\n Search time : %.6f\n 
					Unknown words : %d\n", time_fill, time_search, unknown_words);
				//come back to later
			case '-h':
				print_help();
			default:
				fprintf(stderr, "%c\n is an invalid command");
			}	
	}
	if (h == NULL){
		h = htable_new(size,FLEX);
	}
	if (argc > 1) {
		start = clock();
		while(getword(word, sizeof word, stdin) != EOF){
			htable_insert(h, word);
			//or could search go in here too, the if loop?
		}
		end = clock();
		time_fill = (end-start)/CLOCKS_PER_SEC;
		word_search();
	} else {
		fprintf(stderr, "no arguments given\n");
		return EXIT_FAILURE;
	}

	htable_free();
	return EXIT_SUCCESS;
}