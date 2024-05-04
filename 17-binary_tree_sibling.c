#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: return a pointer to the sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *temp = NULL;

	if (node == NULL)
		return (NULL);

	if (node->p == NULL)
		return (NULL);

	if (node->p->left)
	{
		return (node->p->right);
	}

	if (node->p->right)
	{
		return (node->p->left);
	}

	temp = binary_tree_sibling(node->p->left);
	if (temp != NULL)
		return (temp);

	temp = binary_tree_sibling(node->p->right);

	return (temp);
}
