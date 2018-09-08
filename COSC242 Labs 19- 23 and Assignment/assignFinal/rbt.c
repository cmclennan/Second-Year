/*COSC242 assignment
 *Group 15
 *2017
 *rbt.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "rbt.h"

/*IS_BLACK method
 *---------------
 *defines a node as being Black
 *if it meets defined conditions.
 */

#define IS_BLACK(x) ((NULL ==(x)) || (BLACK == (x)->colour))
/*IS_RED method
 *-------------
 *defines a node as being RED if
 *it meets defined conditions.
 */

#define IS_RED(x) ((NULL !=(x)) && (RED == (x)->colour))

typedef enum { RED, BLACK } rbt_colour;

/*rbt_node struct
 *---------------
 *contains: key, a string value
 *rbt_colour, either red or black,
 *allows for tree to be an RBT.
 *left, the left child of the rbt and
 *right, the right child
 */

struct rbt_node {
    char *key;
    rbt_colour colour;
    rbt left;
    rbt right;
};

/*right_rotate function
 *---------------------
 *does a right rotation of an rbt.
 *@param b, the node to be rotated around.
 *@return the rotated rbt.
 */

static rbt right_rotate(rbt b){
    rbt temp = b;
    b = b->left;
    temp->left = b->right;
    b->right = temp;
    return b;
}

/*left_rotate function
 *---------------------
 *Does a left rotation of an rbt.
 *@param b, the node to be rotated around.
 *@return the rotated rbt.
 */

static rbt left_rotate(rbt b){
    rbt temp = b;
    b = b->right;
    temp->right = b->left;
    b->left = temp;
    return b;
}

/*rbt_fix function
 *----------------
 *Recursively checks the tree to check that there
 *are no red nodes with red node children. Is called by rbt_insert.
 *
 *@param b a rbt node to have it's children and
 *grandchildren checked for double red nodes.
 *
 *@return The fixed rbt.
 */

static rbt rbt_fix(rbt b){
    if(b == NULL){
        return NULL;
    }

    if(IS_RED(b->left) && IS_RED(b->left->left)){
        if(IS_RED(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else{
            b = right_rotate(b);
            b->colour = BLACK;
            b->right->colour = RED;
        }
        b->left = rbt_fix(b->left);
    }

    if(IS_RED(b->left) && IS_RED(b->left->right)){
        if(IS_RED(b->right)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else{
            b->left = left_rotate(b->left);
            b = right_rotate(b);
            b->colour = BLACK;
            b->right->colour = RED;
        }
        b->left = rbt_fix(b->left);
    }


    if(IS_RED(b->right) && IS_RED(b->right->left)){
        if(IS_RED(b->left)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else{
            b->right = right_rotate(b->right);
            b = left_rotate(b);
            b->colour = BLACK;
            b->left->colour = RED;
        }
        b->right = rbt_fix(b->right);
    }
    if(IS_RED(b->right) && IS_RED(b->right->right)){
        if(IS_RED(b->left)){
            b->colour = RED;
            b->left->colour = BLACK;
            b->right->colour = BLACK;
        }else{
            b = left_rotate(b);
            b->colour = BLACK;
            b->left->colour = RED;
        }
        b->right = rbt_fix(b->right);
    } 
    return b;


}   

/*rbt_new function
 *----------------
 *Initialises the root of the RBT,
 *assigning its colour as black.
 *
 *@return the root of the new rbt.
 */

rbt rbt_new(){
    rbt b = emalloc(sizeof *b);
    b->colour = BLACK;
    b->key = NULL;
    b->left = NULL;
    b->right = NULL;
    return b;
}

/*rbt_print function
 *------------------
 *Prints each key in the tree in preorder,
 *given in the form "[colour] [key]".
 *
 *@param b, the tree to be printed
 *@param stream, the stream to print the tree to
 */

void rbt_print(rbt b, FILE *stream){
    if(b == NULL){
        return;
    }
    if(IS_BLACK(b)){        
        fprintf(stream,"black:%s, ", b->key);
    }else if(IS_RED(b)){
        fprintf(stream,"red:%s, ", b->key);
    }
    rbt_print(b->left, stream);
    rbt_print(b->right, stream);

}

/*rbt_search function
 *-------------------
 *Recursively searches the rbt for a given string.
 *
 *@param b, the rbt to be searched.
 *@param find, the string to search for.
 *
 *@return 1 if the string exists in the rbt or 0 if it does not.
 */

int rbt_search(rbt b, char *find){
    int comparison;
    if (b == NULL){
        return 0;        
    }
    comparison = strcmp(b->key, find);
    if(comparison == 0){
        return 1;
    }else if(comparison > 0){
        return rbt_search(b->left, find);
    }else if(comparison < 0){
        return rbt_search(b->right, find);
    }
    return 0;
}

/*rbt_insert function
 *-------------------
 *Recursively adds a provided string to the bst,
 *calling bst_fix to fix any broken rbt properties.
 *
 *@param b, the rbt to add the string to.
 *@param str, the string you want to add to the bst.
 *
 *@return the rbt with the added string.
 */

rbt rbt_insert(rbt b, char *str){
    int comparison;
    /*If no key, we can place str here, the only rbt with a
      NULL key which isn't NULL itself is the root of the RBT. */
    if(b == NULL){
        rbt b = emalloc(sizeof *b);              
        b->key = emalloc((strlen(str) + 1) * sizeof (*str));
        strcpy(b->key,str);
        b->left = NULL;
        b->right = NULL;
        b->colour = RED;
        return b;
    }
    /*special insertion for the root */
    if(b->key == NULL){
        b->key = emalloc((strlen(str) + 1) *sizeof (*str));
        strcpy(b->key, str);
        return b;
    }
    
        
    
    comparison = strcmp(b->key, str);
    /*key is already here */   
    if(comparison > 0){ /*key to add is less than current */ 
        b->left = rbt_insert(b->left, str);
    }else if(comparison <= 0){ /*key to add is greater */
        b->right = rbt_insert(b->right, str);
    }
    b = rbt_fix(b);
    return b;
}
      
/*rbt_free function
 *-----------------
 *Recursively frees the memory used by the rbt.
 *
 *@param b the rbt to have its memory freed.
 *
 *@return a freed rbt node (essentially changes pointer to NULL).
 */

rbt rbt_free(rbt b){
    if(b == NULL){
        return NULL;
    }
    b->left = rbt_free(b->left);
    b->right = rbt_free(b->right);
    free(b->key);
    free(b);
    return NULL;
}
