#include "binary_trees.h"

/**
  * binary_tree_uncle - this function finds the uncle of a n
  *
  * @n: this is a pointer to the n to find the uncle
  * Return: a pointer to the sibling on success, NULL on failure
  */

binary_tree_t *binary_tree_uncle(binary_tree_t *n)
{
	int left, right;

	if (n == NULL)
	{
		return (NULL);
	}
	if (n->parent == NULL)
	{
		return (NULL);
	}
	if (n->parent->parent == NULL)
	{
		return (NULL);
	}
	if (n->parent->parent->left == NULL || n->parent->parent->right == NULL)
	{
		return (NULL);
	}

	left = n->parent->parent->left->n;
	right = n->parent->parent->right->n;

	if (left == right)
	{
		return (n->parent->left);
	}
	else if (left == n->parent->n)
	{
		return (n->parent->parent->right);
	}
	else if (right == n->parent->n)
	{
		return (n->parent->parent->left);
	}
	else
	{
		return (NULL);
	}
}
