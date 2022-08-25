#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a BT using post-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer the function to call on each node
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
