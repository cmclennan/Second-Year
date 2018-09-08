/* COSC242 Assignment
 * Group 15
 * 2017
 *container.c
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_
#include <stdio.h>
/* The container structure
 * will hold a void pointer to either a Flexarray or a Red Black Tree as 
 * specified by the data field 'type'. each of the functions in this structure
 * correlates to functions in both the Flexarray and Red Black Tree structures,
 * whether this container calls the functions of the Flexarray or Red Black 
 * Tree is determined by the 'type' of the container structure.
 */
typedef enum container_e {FLEX_ARRAY, RED_BLACK_TREE} container_t;
typedef struct containerrec *container;
extern container container_new(container_t);
extern void container_add(container, char *);/*string to be added*/
extern void container_free(container);
extern int container_search(container, char *);
extern void container_print(container, FILE *);
#endif
