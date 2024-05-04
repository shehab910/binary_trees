#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a new right-child node.
 * @p: Pointer to the node for right-child insertion.
 * @v: Value for the new node.
 * Return: Pointer to created node on success NULL on failure or if p NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *p, int v)
{
	binary_tree_t *nn;

	if (p == NULL)
	{
		return (NULL);
	}

	nn = malloc(sizeof(binary_tree_t));
	if (nn == NULL)
	{
		return (NULL);
	}
	if (p->right != NULL)
	{
		nn->right = p->right;
		nn->right->p = nn;
		nn->p = p;
		p->right = nn;
	}
	else
	{
		p->right = nn;
		nn->p = p;
		nn->right = NULL;
	}
	nn->n = v;
	nn->left = NULL;
	return (nn);
}
