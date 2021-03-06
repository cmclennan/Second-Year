/* COSC242 Assignment
 * Group 15
 * 2017
 * asgn.c
 */

#include <stdio.h>
#include "mylib.h"
#include <stdlib.h>
#include <getopt.h>
#include "htable.h"
#include <time.h>
#include "container.h"


/*
 * Function: print_help()
 * ----------------------
 * Prints the help menu out, when the command "-h" is called on the command 
 * line.
 *
 * Does not take any input parameters.
 * 
 * Returns: Nothing.
*/

void print_help() {
    fprintf(stderr, "To run the program,\
type './asgn dictionary.txt < document.txt'. \
\nThe command '-r'allows a red-black tree to be used as the \
hash tables container type.\
\nThe command '-s table_size sets table size.\
\nThe command '-p' prints the hash table to\
stdout one line per non-empty container.\
\nThe command'-i' prints information to stderr about hash \
table fill time, hash table search time and unknown words.\n");
}


/*
 * Function: main(int argc, char **argv)
 * -------------------------------------
 * Holds all variable initialisations for variables used in main, deals with
 * the command line arguments with a while loop with switch cases, and then 
 * deals with htable calls for creation of the htable and filling and timing 
 * the fill of htable. Also records the time to search for desired words from
 * standard input.
 *
 *  @param argc: The amount of arguments that passed into the program.
 *  @param **argv: The pointer to a char pointer.
 * 
 * Returns: EXIT_SUCCESS to finish the program so that it doesn't keep running
 * and terminal can be used again. It will also print out an error if an 
 * invalid command is used, or if no arguement is given. 
 */

int main(int argc, char **argv){
    char word[256];
    FILE *file;
    const char *optstring = "s:rpih";
    char option;
    int size = 3877; 
    htable h = NULL;
    int caseI = 0;
    int caseP = 0;
    int unknown_words = 0;
    clock_t start, end;
    double time_fill;
    double time_search = 0;
    container_t type = FLEX_ARRAY;

    while ((option = getopt(argc, argv, optstring)) != EOF){
        switch (option){
            case 's':
                size = atoi(optarg);
                break;
            case 'r':
                type = RED_BLACK_TREE;
                break;
            case 'h':
                print_help();
                return EXIT_FAILURE;
            case 'p':
                caseP = 1;/*this happens later*/
                break;
            case 'i':
                caseI = 1;/*this happens later*/
                break;
            default:
                fprintf(stderr, "%c\n is an invalid command",option);
        }	
    }

    h = htable_new(size,type);
    
    if (NULL == (file = fopen(argv[argc-1], "r"))){ 
        fprintf(stderr, "no arguments given\n");
        return EXIT_FAILURE;
    } else {
        start = clock();
        while(getword(word, sizeof word, file) != EOF){
            htable_insert(h, word);
        }
        end = clock();
        time_fill = (end-start)/(double)CLOCKS_PER_SEC;
        fclose(file);
    }
    
    while(getword(word, sizeof word, stdin) != EOF){
        start = clock();
        if(htable_search(h, word) != 1){
            end = clock();
            time_search += (end-start)/(double)CLOCKS_PER_SEC;
            printf("%s is not in dictionary\n",word);
            unknown_words++;
            
        }
    }
    if(caseP == 1){
        htable_print(h, stdout);
    }
    if(caseI == 1){
        fprintf(stderr, "\tFill time : %.6f\n\tSearch time :%.6f\n\tUnknown words : %d\n", time_fill, time_search, unknown_words);
    }

    htable_free(h);
    return EXIT_SUCCESS;
}
