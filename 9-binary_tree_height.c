#include "binary_trees.h"

/**
  * binary_tree_height - this measures the height of a t
  *
  * @t: this is a pointer to the root of the node to be measured
  * Return: this returns the height on success and 0 if t is NULL
  */

size_t binary_tree_height(const binary_tree_t *t)
{
	size_t left;
	size_t right;

	if (t == NULL)
		return (0);

	left = binary_tree_height(t->left);
	right = binary_tree_height(t->right);

	if (left > right)
	{
		if (t->left != NULL)
			return (left + 1);
	}
	else
	{
		if (t->right != NULL)
			return (right + 1);
	}
	return (0);
}
