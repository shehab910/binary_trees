#include "binary_trees.h"

/**
 * binary_tree_inorder - goes through a binary t using in-order traversal
 * @t: pointer to the root node of the t to traverse
 * @func: pointer to a function to call for each node
 */

void binary_tree_inorder(const binary_tree_t *t, void (*func)(int))
{
	if (t != NULL && func != NULL)
	{
		binary_tree_inorder(t->left, func);
		func(t->n);
		binary_tree_inorder(t->right, func);
	}
}
