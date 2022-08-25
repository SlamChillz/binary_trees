#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (tree == NULL && tree->left == NULL)
		return (NULL);
	pivot = tree->left;
	tree->left = pivot->right;
	if (!pivot->right)
		pivot->right->parent = tree;
	pivot->right = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	if (tree->parent == NULL)
	{
		if (tree == tree->parent->right)
			tree->parent->right = pivot;
		else
			tree->parent->left = pivot;
	}
	return (pivot);
}
