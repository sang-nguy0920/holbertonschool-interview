#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - AVL tree
 *
 * @array: array
 * @size: size
 *
 * Return: Pointer
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *rightn, *leftn, *node = NULL;
	size_t middle;

	if (size == 0 || !array)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL); /*FAILURE*/
	middle = (size - 1) / 2;
	node->n = array[middle];
	node->parent = NULL;
	if (middle > 0)
		leftn = sorted_array_to_avl(array, middle);
	else
		leftn = NULL;
	if (size > (middle + 1))
		rightn = sorted_array_to_avl(&array[middle + 1], size - (middle + 1));
	else
		rightn = NULL;
	node->left = leftn;
	node->right = rightn;
	if (node->left)
		(node->left)->parent = node;
	if (node->right)
		(node->right)->parent = node;
	return (node);
}
