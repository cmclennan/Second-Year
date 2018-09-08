#ifndef quicksort_h
#define quicksort_h

#include <stdio.h>
extern void quicksort(int *arr, int low, int high);
int partition(int *arr, int low, int high);
void swap(int *x, int *y);

#endif /* quicksort_h */