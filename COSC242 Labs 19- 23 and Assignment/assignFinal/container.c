/* COSC242 Assignment
 * Group 15
 * 2017
 *container.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "container.h"
#include "flexarray.h"
#include "rbt.h"

/*
 * Function: print_key(char *s)
 * ----------------------------
 * Prints the key out, while talking a pointer to a character.
 *
 * @param *s: pointer to point to a character, or in this case the key.
 * 
 * Returns: nothing.
 */

void print_key(char *s, FILE *stream){
    fprintf(stream,"%s, ", s);
}

/*
 * Struct: containerrec
 * --------------------
 * Defines the data fields of the container struct.
 *
 * Does not take any input parameters.
 *
 * Returns: Nothing.
 */
struct containerrec {
    container_t type;
    void *contents;
};
/*
 * Function: container_new(container_t type)
 * -----------------------------------------
 * This function creates a new container pointing to either a Flexarray or a
 * Red Black Tree by calling that structures new function.  Whether a Flexarray
 * or a Red Black Tree is created depends on the 'type' passed as an argument.
 *
 * @param type: Whether the container is holding a FLEX_ARRAY or RED_BLACK_TREE.
 *
 * Returns: The container holding the Flexarray or Red Black Tree.
 */
container container_new(container_t type){
    container c = emalloc(sizeof *c);
    if(type == RED_BLACK_TREE){
        c->type = RED_BLACK_TREE;
        c->contents = rbt_new();
        return c;
    }else{
        c->type = FLEX_ARRAY;
        c->contents = flexarray_new();
        return c;
    }    
}
/*
 * Function: container_add(container c, char *word)
 * ------------------------------------------------
 * This function calls the insert (append) functions of either a Flexarray or
 * Red Black Tree depending on the containers 'type'.
 *
 * @param c: The container structure that we are inserting into.
 * @param *word: a string to be inserted.
 *
 * Returns: Nothing.
 */
void container_add(container c, char *word){
    if(c->type == RED_BLACK_TREE){
        c->contents = rbt_insert(c->contents, word);
    }else{
        flexarray_append(c->contents, word);
    }
}
/*
 * Function: container_free(container c)
 * ------------------------------------
 * This function calls the free functions of either a Flexarray or Red Black
 * Tree depending on the containers 'type' and then frees the container itself.
 *
 * @param c: The container structure that we are freeing from memory.
 *
 * Returns: Nothing.
 */
void container_free(container c){
    if(c->type == RED_BLACK_TREE){
        rbt_free(c->contents);
    }else{
        flexarray_free(c->contents);
    }
	free(c);
}
/*
 * Function: container_search(container c, char *str)
 * --------------------------------------------------
 * This function calls the search functions of either a Flexarray or Red Black
 * Tree depending on the containers 'type'. 
 *
 * @param c: The container structure that we are searching.
 * @param *str: a string to be searched for.
 *
 * Returns: 1 if the item is found otherwise returns 0.
 */
int container_search(container c, char *str){
    if(c->type == RED_BLACK_TREE){
        return rbt_search(c->contents, str);
    }else{
        return is_present(c->contents, str);
    }
}

void container_print(container c, FILE *stream){
    if(c->type == RED_BLACK_TREE){
        rbt_print(c->contents, stream);
    }else{
        visit(c->contents, stream, print_key);
    }
}

