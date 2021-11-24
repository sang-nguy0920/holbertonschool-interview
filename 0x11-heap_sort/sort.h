#ifndef SORT
#define SORT

#include <stdio.h>
#include <stdlib.h>

void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heaps(int *array, size_t size);

#endif
