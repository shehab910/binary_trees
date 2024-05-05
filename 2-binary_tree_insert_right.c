#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new right-child node.
 * @parent: Pointer to the node for right-child insertion.
 * @value: Value for the new node.
 * Return: Pointer to created node on success NULL on failure or if parent NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *nn;

	if (parent == NULL)
	{
		return (NULL);
	}

	nn = malloc(sizeof(binary_tree_t));
	if (nn == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		nn->right = parent->right;
		nn->right->parent = nn;
		nn->parent = parent;
		parent->right = nn;
	}
	else
	{
		parent->right = nn;
		nn->parent = parent;
		nn->right = NULL;
	}
	nn->n = value;
	nn->left = NULL;
	return (nn);
}
