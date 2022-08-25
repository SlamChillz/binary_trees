#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t x, y;
	bst_t *bstree = NULL;

	if (array == NULL)
		return (NULL);
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < x)
		{
			if (array[x] == array[y++])
				break;
		}
		if (x == y)
		{
			if (bst_insert(&bstree, array[x++]) == NULL)
				return (NULL);
		}
	}
	return (bstree);
}
