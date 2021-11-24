#include "sort.h"

/**
 * sift_down - sift down
 *
 * @array: array
 * @start: start
 * @end: end
 * @size: size
 *
 * Return: void
 */

void sift_down(int *array, size_t start, size_t end, size_t size)
{
size_t root = start, child, swap;
int temp;

while (root * 2 + 1 <= end)
{
child = root * 2 + 1;
swap = root;
if (array[swap] < array[child])
swap = child;
if (child + 1 <= end && array[swap] < array[child + 1])
swap = child + 1;
if (swap == root)
return;
temp = array[root];
array[root] = array[swap];
array[swap] = temp;
print_array(array, size);
root = swap;
}
}

/**
 * heap_sort - heaps
 *
 * @array: array
 * @size: size
 *
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
size_t start;

if ((size - 1) % 2 == 0)
start = (size - 3) / 2;
else
start = (size - 2) / 2;
while (start + 1 >= 1)
{
sift_down(array, start, size - 1, size);
start -= 1;
}
}

/**
 * sorts - sorts an array
 *
 * @array: array
 * @size: size
 *
 * Return: void
 */

void sorts(int *array, size_t size)
{
size_t last;
int store;

if (size <= 1)
return;
heap_sort(array, size);
last = size - 1;
while (last > 0)
{
store = array[0];
array[0] = array[last];
array[last] = store;
print_array(array, size);
last -= 1;
sift_down(array, 0, last, size);
}
}
