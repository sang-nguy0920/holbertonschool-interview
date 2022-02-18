#include "sort.h"

/**
 * merge_sort - function that sorts an array of integers
 * @array: array
 * @size: size
 */

void merge_sort(int *array, size_t size)
{
int *new = NULL, x = 0;

new = malloc(sizeof(int) * size);
for (x = 0; x < (int)size; x++)
new[x] = array[x];

split(array, new, size);
free(new);
}


/**
 * split - splits array
 * @new: array new
 * @array: array
 * @size: size
 */

void split(int *array, int *new, size_t size)
{
int mid = (int)size / 2;

if (size < 2)
return;
split(array, new, mid);
split(array + mid, new, size - mid);
merge(array, new, size);
}


/**
 * merge - merging sorted array and printing out
 * @array:array to merge
 * @new: array to merge
 * @size: array size
 */

void merge(int *array, int *new, size_t size)
{
int mid = (int)size / 2, x = 0, y = 0, z = 0;

z = mid;

printf("Merging...\n[left]: ");
print_array(array, mid);
printf("[right]: ");
print_array(array + mid, size - mid);

for (x = 0; y < (int)size; y++)
{
if (x < mid && (z == (int)size || array[x] <= array[z]))
{
new[y] = array[x];
x++;
}
else
{
new[y] = array[z];
z++;
}
}

for (x = 0; x < (int)size; x++)
array[x] = new[x];

printf("[Done]: ");
print_array(new, size);
}
