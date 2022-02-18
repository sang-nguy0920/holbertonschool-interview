#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_down(int *arr, size_t size, size_t i, size_t cpysize);

#endif
