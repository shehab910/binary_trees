#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given n is a root
 * @n: pointer to the n to check
 * Return:  1 if n is a root, otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *n)
{
	if (n == NULL)
	{
		return (0);
	}

	if (n->parent == NULL)
	{
		return (1);
		binary_tree_is_root(n->left);
		binary_tree_is_root(n->right);
	}

	return (0);
}
