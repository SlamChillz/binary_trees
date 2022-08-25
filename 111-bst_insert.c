#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 * @tree: is a double pointer to the root node of the BST
 * @value: is the value to store in the node to be inserted
 *
 * Return: a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *pivot, *newNode;

	if (tree != NULL)
	{
		pivot = *tree;

		if (pivot == NULL)
		{
			newNode = binary_tree_node(pivot, value);
			if (newNode == NULL)
				return (NULL);
			return (*tree = newNode);
		}

		if (value < pivot->n)
		{
			if (pivot->left != NULL)
				return (bst_insert(&pivot->left, value));

			newNode = binary_tree_node(pivot, value);
			if (newNode == NULL)
				return (NULL);
			return (pivot->left = newNode);
		}
		if (value > pivot->n)
		{
			if (pivot->right != NULL)
				return (bst_insert(&pivot->right, value));

			newNode = binary_tree_node(pivot, value);
			if (newNode == NULL)
				return (NULL);
			return (pivot->right = newNode);
		}
	}
	return (NULL);
}
