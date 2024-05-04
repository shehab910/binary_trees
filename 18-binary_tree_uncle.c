#include "binary_trees.h"

/**
  * binary_tree_uncle - this function finds the uncle of a node
  *
  * @node: this is a pointer to the node to find the uncle
  * Return: a pointer to the sibling on success, NULL on failure
  */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	int left, right;

	if (node == NULL)
	{
		return (NULL);
	}
	if (node->p == NULL)
	{
		return (NULL);
	}
	if (node->p->p == NULL)
	{
		return (NULL);
	}
	if (node->p->p->left == NULL || node->p->p->right == NULL)
	{
		return (NULL);
	}

	left = node->p->p->left->n;
	right = node->p->p->right->n;

	if (left == right)
	{
		return (node->p->left);
	}
	else if (left == node->p->n)
	{
		return (node->p->p->right);
	}
	else if (right == node->p->n)
	{
		return (node->p->p->left);
	}
	else
	{
		return (NULL);
	}
}
