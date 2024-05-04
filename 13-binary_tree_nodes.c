#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least one child
 * @t: pointer to the root node
 * A NULL pointer is not a node
 * Return: 0 if t is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *t)
{

	if (t == NULL)
		return (0);

	if (t->left != NULL || t->right != NULL)
	{
		return (binary_tree_nodes(t->left) +
				binary_tree_nodes(t->right) + 1);
	}

	return (0);
}
