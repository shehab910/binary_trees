#include "binary_trees.h"

/**
  * binary_tree_delete - this function deletes an entire binary tree
  *
  * @tree: is the pointer to the root/parent node of the node to
  * be deleted
  */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return;
	}

	if (tree->left != NULL)
	{
		binary_tree_delete(tree->left);
	}
	if (tree->right != NULL)
	{
		binary_tree_delete(tree->right);
	}
	free(tree);
}
