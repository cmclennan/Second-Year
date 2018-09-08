/* COSC242 Assignment
 * Group 15
 * 2017
 * rbt.h
 */

#ifndef RBT_H_
#define RBT_H_

/* The RBT structure
 * will store a key, a left child, a right child, and a colour,
 * either red or black. Each of the functions in this structure
 * correlates to useful functions of the rbt.c file.
 */

typedef struct rbt_node *rbt;

extern rbt rbt_delete(rbt b, char *str); /*allows deletion of keys. */
extern rbt rbt_free(rbt b); /*frees the memory used by the rbt. */
extern rbt rbt_insert(rbt b, char *str); /*inserts a key into the rbt. */
extern rbt rbt_new(); /*Creates a new rbt. */
extern int rbt_search(rbt b, char *str); /*Searches the rbt for a key. */
extern void rbt_print(rbt b, FILE *stream); /*prints every node in the rbt. */

#endif 
