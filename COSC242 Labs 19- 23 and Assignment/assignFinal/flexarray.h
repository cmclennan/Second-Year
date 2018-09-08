/* COSC242 Assignment
 * Group 15
 * 2017
 *flexarray.h
 */

#ifndef FLEXARRAY_H_
#define FLEXARRAY_H_

/* The flexarray holds an array of strings, and when full will double in size in
 * order to accomodate for dynamic addition of strings. flexarray_append is for
 * appending strings to the array, flexarray_free is for freeing the array after
 * it has been finished with, flexarray_print ----, is_present is for checking
 * to see if a string is present in the array and visit applies a funtion to
 * each item in the flex array.
 */

typedef struct flexarrayrec *flexarray;

extern void flexarray_append(flexarray f, char *item);
extern void flexarray_free(flexarray f);
extern flexarray flexarray_new();
extern int is_present(flexarray f, char* str);
extern void visit(flexarray f, FILE *stream, void func(char* str,FILE *stream));

#endif
