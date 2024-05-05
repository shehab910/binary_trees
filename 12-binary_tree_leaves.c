#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary t
 * @t: pointer to the root node
 * A NULL pointer is not a leaf
 * Return: 0 if t is NULL
 */

size_t binary_tree_leaves(const binary_tree_t *t)
{
	size_t leftleaves, rightleaves;

	if (t == NULL)
		return (0);

	/* nodes that have no children are called leaves */
	if (t->left == NULL && t->right == NULL)
		return (1);

	/* recursively count the leaves */
	leftleaves = binary_tree_leaves(t->left);
	rightleaves = binary_tree_leaves(t->right);

	return (leftleaves + rightleaves);
}
