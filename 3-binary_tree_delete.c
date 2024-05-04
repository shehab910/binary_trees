#include "binary_trees.h"

/**
  * binary_tree_delete - this function deletes an entire binary t
  *
  * @t: is the pointer to the root/p node of the node to
  * be deleted
  */

void binary_tree_delete(binary_tree_t *t)
{
	if (t == NULL)
	{
		return;
	}

	if (t->left != NULL)
	{
		binary_tree_delete(t->left);
	}
	if (t->right != NULL)
	{
		binary_tree_delete(t->right);
	}
	free(t);
}
