#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htable.h"
#include "mylib.h"
#include "container.h"

/*
 * Function: htable_word_to_int(char *word)
 * ----------------------------------------
 * This is our hashing algorithm, takes a string (character pointer) as a 
 * parameter and turns it into an integer which is then returned at the 
 * end of the function.
 *
 * @param *word: a string to be hashed.
 *
 * Returns: a integer representing the string after the hashing algorithm has
 * been applied.
 */
static unsigned int htable_word_to_int(char *word) {
    unsigned int result = 0;
    while (*word != '\0') {
        result = (*word++ + 31 * result);
    }
    return result;
}
/*
 * Struct: htablerec
 * -----------------
 * Defines the data fields of the htable struct.  The containers 
 * will store the strings in either a Flexarray or a Red Black Tree as 
 * specified by the data field 'type'.
 *
 *  Does not take any input parameters.
 * 
 * Returns: Nothing.
 */
struct htablerec {	
	/*pointers to the containers that will be making up the Hash Table.*/
    container *keys;
	/*the maximum number of containers we can hold in the Hash Table.*/
    int capacity;
	/*This determines how the objects in the containers will be stored, 
	 *either in a Flexarray or a Red Black Tree.*/
    container_t type;
};
/*
 * Function: htable_new(int capacity, int type)
 * --------------------------------------------
 * This function creates a new Hash Table, sets the type of storage the 
 * container will use, and allocates memory for the Table itself and for  the
 * ponters to containers within the Hash Table. 
 *
 * @param capacity: the size of the Hash Table.
 * @param type: whether the Hash Table will store aFLEX_ARRAY or RED_BLACK_TREE
 * type.
 *
 * Returns: The new Hash Table.
 */
htable htable_new(int capacity,int type){
    int i;
    htable result = emalloc(sizeof *result);
    /*result->type = emalloc(sizeof(result->type));*/
    if(type == 0){
        result->type = FLEX_ARRAY;
    }else{
        result->type = RED_BLACK_TREE;
    }
    result->capacity = capacity;
    result->keys = emalloc(result->capacity * sizeof (result->keys[0]));
    for(i=0;i<result->capacity;i++){
        result->keys[i] = NULL;
        /*we decided to create a Hash Table filed with NULL values rather than
          empty containers because this means that we do not have to allocate
          memory for the empty Flexarray(defult size 2) or the empty Red Black
          Tree(null root and children).
        */
    }
    return result;
}
/*
 * Function: htable_free(htable h)
 * -------------------------------
 * This function calls the free function of each container within the Hash 
 * Table that has been passed in the parameter before freeing the Hash Table
 * itself.
 *
 * @param h: the Hash Table to be free'd.
 *
 * Returns: Nothing.
 */
void htable_free(htable h){
    int i;
    for(i=0;i<h->capacity;i++){
        if(h->keys[i] != NULL){
            container_free(h->keys[i]);
        }
    }
    free(h->keys);
    free(h);
}
/*
 * Function: htable_insert(htable h,char *str)
 * -------------------------------------------
 * This function takes a Hash Table and a string to be inserted as a parameter. 
 * It then hashes the string and inserts it into the container at the index 
 * calculated by the hashing algorithm. If the index does not contain an item, 
 * a new container is created and the item is inserted.
 *
 * @param h: The Hash Table to be inserted into.
 * @param *str: the string to be inserted into the Hash Table.
 *
 * Returns: 1 on a successful insert.
 */
int htable_insert(htable h, char *str){
    unsigned int n = htable_word_to_int(str);
    int index = n%h->capacity;
    if(h->keys[index] == NULL){/*no key there*/
        h->keys[index] = container_new(h->type);
        container_add(h->keys[index], str);
        return 1;
        /*}else if(container_search(h->keys[index], str) == 1){
        return 1;*/
    }else{
        container_add(h->keys[index], str);
        return 1;
    }
}
/*
 * 
 */
void htable_print(htable h,FILE *stream){
    int i;
    for(i=0;i<h->capacity;i++){
        if(h->keys[i] != NULL){
            fprintf(stream, "Line: %d contents: ",i);
            container_print(h->keys[i], stream);
        }
        fprintf(stream,"\n");
    }
}
/*
 * Function: htable_search(htable h, char *str)
 * -------------------------------------------
 * This function takes a Hash Table and a string to be searched for as a 
 * parameter. it then hashes the string to an index in the Hash Table and
 * calls the search function of the container at that index.
 *
 * @param h: The Hash Table to be searched.
 * @param *str: the string to be searched for.
 *
 * Returns: a 1 if the string is found and a 0 if not. 
 */
int htable_search(htable h, char *str){
    unsigned int n = htable_word_to_int(str);
    int index = n%h->capacity;
    if(h->keys[index] != NULL && container_search(h->keys[index], str) == 1){
        return 1;
    }else{
        return 0;
    }
}

