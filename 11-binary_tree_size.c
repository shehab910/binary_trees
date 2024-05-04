#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary t
 * @t: pointer to the root node of the t to measure the size
 * Return: the height or 0
 */

size_t binary_tree_size(const binary_tree_t *t)
{
	size_t left;
	size_t right;

	if (t == NULL)
		return (0);

	left = binary_tree_size(t->left);
	right = binary_tree_size(t->right);

	return (left + right + 1);
}
