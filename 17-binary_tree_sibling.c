#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a n
 * @n: pointer to the n to find the sibling
 * Return: return a pointer to the sibling n
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *n)
{
	binary_tree_t *temp = NULL;

	if (n == NULL)
		return (NULL);

	if (n->parent == NULL)
		return (NULL);

	if (n->parent->left)
	{
		return (n->parent->right);
	}

	if (n->parent->right)
	{
		return (n->parent->left);
	}

	temp = binary_tree_sibling(n->parent->left);
	if (temp != NULL)
		return (temp);

	temp = binary_tree_sibling(n->parent->right);

	return (temp);
}
