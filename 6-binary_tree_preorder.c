#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary t using pre-order method.
 * @t: Pointer to the root node for traversal.
 * @func: Pointer to a function to apply to each node.
 *        (Function should take an integer argument.)
 */

void binary_tree_preorder(const binary_tree_t *t, void (*func)(int))
{
	if (t != NULL && func != NULL)
	{
		func(t->n);
		binary_tree_preorder(t->left, func);
		binary_tree_preorder(t->right, func);
	}
}
