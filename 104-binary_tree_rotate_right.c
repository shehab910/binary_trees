#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @t: The root of the binary tree to rotate.
 *
 * Description:
 * This function performs a right-rotation on a binary tree. The root of the
 * binary tree is passed as an argument to the function. The function returns
 * a pointer to the new root of the binary tree after the rotation.
 *
 * Return:
 * A pointer to the new root of the binary tree after the rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *t)
{
	binary_tree_t *pivot, *tmp;

	if (t == NULL || t->left == NULL)
		return (NULL);

	pivot = t->left;
	tmp = pivot->right;
	pivot->right = t;
	t->left = tmp;
	if (tmp != NULL)
		tmp->parent = t;
	tmp = t->parent;
	t->parent = pivot;
	pivot->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == t)
			tmp->left = pivot;
		else
			tmp->right = pivot;
	}

	return (pivot);
}
