#include "binary_trees.h"

/**
  * binary_tree_depth - this measures the depth of a node of a binsry t
  *
  * @t: this is a pointer to the root of the node to be measured
  * Return: this returns the depth on success and 0 if t is NULL
  */

size_t binary_tree_depth(const binary_tree_t *t)
{
	size_t count = 0;

	if (t == NULL || t->p == NULL)
	{
		return (0);
	}

	count = 1 + binary_tree_depth(t->p);
	return (count);
}
