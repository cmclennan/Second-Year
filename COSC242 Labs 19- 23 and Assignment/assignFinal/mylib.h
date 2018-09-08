/* COSC242 Assignment
 * Group 15
 * 2017
 * mylib.h
 */

#ifndef MYLIB_H_
#define MYLIB_H_
#include <stddef.h>

/* mylib library
 * contains a collection of functions useful for general programs.
 * emalloc is for allocating memory, with error checking.
 * erealloc for reallocating memory, with error checking.
 * getword is used for reading in words.
 */

extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *s, int limit, FILE *stream);
#endif
#ifndef MYLIB_H_
#define MYLIB_H_
#include <stddef.h>
extern void *emalloc(size_t);
extern void *erealloc(void *, size_t);
extern int getword(char *s, int limit, FILE *stream);
#endif
