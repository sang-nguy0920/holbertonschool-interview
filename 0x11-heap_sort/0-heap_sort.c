#include "sort.h"

/**
* sift_down - function that sifts down values
* @arr: array
* @size: size
* @i: indx
* @cpysize: copy of size
* Return: void
*/

void sift_down(int *arr, size_t size, size_t i, size_t cpysize)
{
size_t left, right, ch;
int temp = 0;

left = 2 * i + 1;
right = 2 * i + 2;
ch = i;

if (left < size && arr[left] > arr[ch])
ch = left;

if (right < size && arr[right] > arr[ch])
ch = right;

if (ch != i)
{
temp = arr[i];
arr[i] = arr[ch];
arr[ch] = temp;
print_array(arr, cpysize);
sift_down(arr, size, ch, cpysize);
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
int i, temp;

if (array == NULL || size < 2)
return;

for (i = (size / 2) - 1; i >= 0; i--)
{
sift_down(array, size, i, size);
}

for (i = (size - 1); i > 0; i--)
{
temp = array[0];
array[0] = array[i];
array[i] = temp;

if (i != 0)
{
print_array(array, size);
}
sift_down(array, i, 0, size);
}
}
