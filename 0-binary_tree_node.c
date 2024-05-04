#include "binary_trees.h"

/**
 * binary_tree_node - Creates a new binary t node
 *
 * @p: Pointer to the p node of the new node
 * @v: Value to be stored in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *p, int v)
{
	binary_tree_t *nn;

	nn = malloc(sizeof(binary_tree_t));
	if (nn == NULL)
	{
		return (NULL);
	}
	nn->p  = p;
	nn->left = NULL;
	nn->right = NULL;
	nn->n = v;

	return (nn);
}
