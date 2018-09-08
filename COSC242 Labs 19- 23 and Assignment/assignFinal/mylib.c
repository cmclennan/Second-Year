/* COSC242 Assignment
 * Group 15
 * 2017
 *mylib.c
 */

#include <stdio.h> /* for fprintf */
#include <stdlib.h> /* for size_t, malloc, realloc, exit */
#include <assert.h>
#include <ctype.h>
#include "mylib.h"

/*
 * Function: *emalloc(size_t s)
 * -----------------------------
 * Allocates memory for items, with error checking.
 *
 * @param s: Takes a size which will be how much memory to allocate.
 *
 * Returns: Allocated memory.
 */

void *emalloc(size_t s) {
    void *result = malloc(s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

/*
 * Function:  *erealloc(void *a, size_t s)
 * ---------------------------------------
 * Reallocates memory for items, with error checking.
 *
 * @param *a: The item that needs to be reallocated.
 * @param s: Takes a size which will be how much memory to allocate.
 *
 * Returns: Reallocated memory.
 */
void *erealloc(void *a, size_t s) {
    void *result = realloc(a,s);
    if (NULL == result) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}


/*
 * Function: getword(char *s, int limit, FILE *stream)
 * ---------------------------------------------------
 * Takes a char to look for, a limit and an input stream to look through
 *
 * @param *s: Character to look for.
 * @param limit: The maximum word size that we can read in.
 * @param *stream: Input stream which will be searched through.
 *
 * Returns: -1 if the end of the file is reached.
 */

int getword(char *s, int limit, FILE *stream) {
    int c;
    char *w = s;
    assert(limit > 0 && s != NULL && stream != NULL);
    /* skip to the start of the word */
    while (!isalnum(c = getc(stream)) && EOF != c)
        ;
    if (EOF == c) {
        return EOF;
    } else if (--limit > 0) { /* reduce limit by 1 to allow for the \0 */
        *w++ = tolower(c);
    }
    while (--limit > 0) {
        if (isalnum(c = getc(stream))) {
            *w++ = tolower(c);
        } else if ('\'' == c) {
            limit++;
        } else {
            break;
        }
    }
    *w = '\0';
    return w - s;
}
