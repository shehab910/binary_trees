#include "binary_trees.h"

/**
  * binary_tree_insert_left - Insert new node as the left child of another node
  *
  * @parent: Pointer to the node to insert the left child in
  * @value: Value to be stored in the new node
  * Return: Pointer to the created node on success,
  * NULL on failure or if parent is NULL
  */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left != NULL)
	{
		nn->left = parent->left;
		nn->left->parent = nn;
		nn->parent = parent;
		parent->left = nn;
	}
	else
	{
		parent->left = nn;
		nn->parent = parent;
		nn->left = NULL;
	}
	nn->n = value;
	nn->right = NULL;
	return (nn);
}
