#include "search_algos.h"

/**
* advanced_binary - a function that searches for a value array of int
*
* @array: array
* @size: size
* @value: value
* Return: the index
*/

int advanced_binary(int *array, size_t size, int value)
{
	int mid_index = (size - 1) / 2;
	int outcome = 0;
	size_t i = 0;

	if (array == NULL || size < 1)
		return (-1);

	print_out(&array[i], size);

	if (array[mid_index] == value && mid_index == 0)
		return (mid_index);
	if (size == 1)
		return (-1);
	if (array[mid_index] >= value)
		return (advanced_binary(array, mid_index + 1, value));

	mid_index++;
	outcome = advanced_binary(&array[mid_index], size - mid_index, value);

	if (outcome == -1)
		return (-1);
	return (mid_index + outcome);
}

/**
* print_out - print output
* @array: array to search in
* @size: size
* Return: void
*/

void print_out(int *array, size_t size)
{
	size_t i;

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i != size - 1)
			printf(", ");
		else
			printf("\n");
	}
}
