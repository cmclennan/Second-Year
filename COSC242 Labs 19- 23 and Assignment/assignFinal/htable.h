/* COSC242 Assignment
 * Group 15
 * 2017
 *flexarray.h
 */

#ifndef HTABLE_H_
#define HTABLE_H_
#include <stdio.h>

/* This structure will hold a list of pointers to container objects which will
 * hold strings that have been hashed to that containers index within the Hash
 * Table.
 */
typedef struct htablerec *htable;
extern void htable_free(htable h);
extern int htable_insert(htable h, char *str);
extern htable htable_new(int capacity,int type);
extern void htable_print(htable h, FILE *stream);
extern int htable_search(htable h, char *str);
#endif
