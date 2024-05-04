#include "binary_trees.h"

/**
  * binary_tree_insert_left - Insert new node as the left child of another node
  *
  * @p: Pointer to the node to insert the left child in
  * @v: Value to be stored in the new node
  * Return: Pointer to the created node on success,
  * NULL on failure or if p is NULL
  */

binary_tree_t *binary_tree_insert_left(binary_tree_t *p, int v)
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
	if (p->left != NULL)
	{
		nn->left = p->left;
		nn->left->p = nn;
		nn->p = p;
		p->left = nn;
	}
	else
	{
		p->left = nn;
		nn->p = p;
		nn->left = NULL;
	}
	nn->n = v;
	nn->right = NULL;
	return (nn);
}
