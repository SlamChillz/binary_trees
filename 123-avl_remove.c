#include "binary_trees.h"

/**
 * _get_minimum - gets the minimum node from a tree
 * @root: pointer to the root node of the tree
 *
 * Return: pointer to the node with minimum value of n
 */
avl_t *_get_minimum(avl_t *root)
{
	avl_t *node = root;

	while (node->left)
		node = node->left;
	return (node);
}

/**
 * _balance - checks balance factor and balances tree
 * @root: root pointer of the tree
 *
 * Return: root pointer to balanced tree
 */
avl_t *_balance(avl_t *root)
{
	int balance;

	balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree
 * @value: value to remove in the tree
 *
 * Return: pointer to new root node after removing the value and rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *trace;

	if (root == NULL)
		return (root);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			trace = root->left ? root->left : root->right;
			if (!trace)
				root = NULL, trace = root;
			else
				*root = *trace;
			free(trace);
		}
		else
		{
			trace = _get_minimum(root->right);
			root->n = trace->n;
			root->right = avl_remove(root->right, trace->n);
		}
	}
	if (root == NULL)
		return (root);
	return (_balance(root));
}
