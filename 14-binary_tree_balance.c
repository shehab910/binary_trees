#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary t
 * @t: pointer to the root node
 * Return: 0 if t is NULL
 */

int binary_tree_balance(const binary_tree_t *t)
{
	size_t leftheight, rightheight;

	if (t == NULL)
		return (0);

	leftheight = binary_tree_height(t->left);
	rightheight = binary_tree_height(t->right);

	return (leftheight - rightheight);
}

/**
 * binary_tree_height - calculate height of a binary t
 * @t: pointer to the root node
 * Return: 0 on failure || height of the t
 */

size_t binary_tree_height(const binary_tree_t *t)
{
	size_t leftheight = 0;
	size_t rightheight = 0;

	if (t == NULL)
		return (0);

	leftheight += 1 + binary_tree_height(t->left);
	rightheight += 1 + binary_tree_height(t->right);

	if (leftheight > rightheight)
		return (leftheight);
	else
		return (rightheight);
}
