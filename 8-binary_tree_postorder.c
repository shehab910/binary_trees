#include "binary_trees.h"

/**
  * binary_tree_postorder - this function goes through a binary
  * t using post-order traversal
  *
  * @t: this is the pointer to the root node
  * @func: this is a pointer to the function to call for each node
  */

void binary_tree_postorder(const binary_tree_t *t, void (*func)(int))
{
	if (t != NULL && func != NULL)
	{
		binary_tree_postorder(t->left, func);
		binary_tree_postorder(t->right, func);
		func(t->n);
	}
}
