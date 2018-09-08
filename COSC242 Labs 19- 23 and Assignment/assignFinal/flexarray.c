/* COSC242 Assignment
 * Group 15
 * 2017
 *flexarray.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "flexarray.h"


/*
 * struct: flexarrayrec 
 * --------------------
 * Global definition of variables to be used throughout the flexarray 
 * implementation.
 *
 * Takes no parameters but holds global variable declarations.
 * 
 * returns Nothing.
*/

struct flexarrayrec {
    int capacity;
    int itemcount;
    char **items;
    int *work_space;
};

/*
 * Function: flexarray_new()
 * -------------------------
 * Function to create a new flexarray with a default capacity of 2.
 *
 * This does not take any parameters as it merely creates a new flexarray.
 * 
 * Returns: result, which is the new flexarray.
*/

flexarray flexarray_new() {
    flexarray result = emalloc(sizeof *result);
    result->capacity = 2;
    result->itemcount = 0;
    result->items = emalloc(result->capacity *sizeof result->items[0]);
    result->work_space = emalloc(result->capacity * sizeof result->items[0]);
    return result;
}

/*
 * Function: visit(flexarray f, void func(char* str))
 * --------------------------------------------------
 * Takes the flexarray and a pointer to a char which gets visited in the
 * flexarray, and this is used to print each item in the flexarray.
 *
 * @param flexarray f: Actual flexarray to use to visit.
 * @param *stream: A stream to print to.
 * @param void func(char *str,FILE *stream): A function taking a string and an
 * output stream as a parameter to be used on the flexarray.
 * 
 * Returns: Nothing.
*/

void visit(flexarray f, FILE *stream, void func(char* str, FILE *stream)){
    int count;
    for(count = 0; count < f->itemcount; count++){
        func(f->items[count],stream);
        
    }
}

/*
 * Function: flexarray_append(flexarray f, char* str)
 * --------------------------------------------------
 * Takes the flexarray and a pointer to a char which gets appended to the
 * flexarray.
 *
 * @param flexarray f: Actual flexarray to append to.
 * @param char *str: Pointer to point to a char, which is the string to append
 * to the flexarray.
 * 
 * Returns: Nothing.
*/

void flexarray_append(flexarray f, char* str) {
    if (f->itemcount == f->capacity) {
        f->capacity += f->capacity;
        f->items = erealloc(f->items,f->capacity * sizeof f->items[0]);
        f->work_space = erealloc(f->work_space,f->capacity * sizeof 
            f->work_space[0]); 
    }
    f->items[f->itemcount] = emalloc((strlen(str)+1) * sizeof (str));
    strcpy(f->items[f->itemcount], str);
    f->itemcount++;
}

/*
 * Function: is_present(flexarray f, char *str)
 * --------------------------------------------
 * Searches the flexarray looking to see if it contains a defined string.
 *
 * @param flexarray f: Actual flexarray to search through
 * @param char *str: Pointer to point to a char, which is what is looked for
 * in the flexarray.
 * 
 * Returns: 1 or 0 depending on if an item is found in the flexarray or not.
*/

int is_present(flexarray f, char *str){
    int i;
    for(i=0;i<f->itemcount;i++){
        if(strcmp(f->items[i],str) == 0){
            return 1;
        }
    }
    return 0;
}

/*
 * Function: flexarray_free(flexarray f)
 * -------------------------------------
 * This function is designed to free all the flexarray when it is done being
 * used. It iterates through the array freeing items.
 *
 * @param flexarray f: Takes the flexarray f as a parameter. 
 * 
 * Returns: Nothing, as it is freeing memory used in the flexarray.
*/

void flexarray_free(flexarray f) {
    int count;
    for(count = 0; count < f->itemcount; count++){
        free(f->items[count]);
    }
    free(f->items);
    free(f->work_space);
    free(f);
}
