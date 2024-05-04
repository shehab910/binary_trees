#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary t is full
 * @t: pointer to the root node of the t to check
 * Return: 1 or 0
 */

int binary_tree_is_full(const binary_tree_t *t)
{
	if (t == NULL)
		return (0);

	if (t->left == NULL && t->right == NULL)
		return (1);

	if (t->left != NULL && t->right != NULL)
	{
		return (binary_tree_is_full(t->left) &&
			binary_tree_is_full(t->right));
	}

	return (0);
}
