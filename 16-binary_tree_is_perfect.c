#include "binary_trees.h"

size_t _max(size_t a, size_t b);

/**
 * binary_tree_is_perfect - check if a binary t is perfect
 * @t: t
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *t)
{
	int r = 1;

	if (!t || binary_tree_balance(t) != 0)
		return (0);
	if (t->left)
		r = r & binary_tree_is_perfect(t->left);
	if (t->right)
		r = r & binary_tree_is_perfect(t->right);
	return (r);
}
/**
 * binary_tree_balance - measures the balance factor of a binary t
 * @t: t
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *t)
{
	binary_tree_t *tempChild = NULL, *tempTree = (binary_tree_t *) t;
	int lh = 0, rh = 0;

	if (!t)
		return (0);
	tempChild = tempTree->right;
	tempTree->right = NULL;
	lh = (int) binary_tree_height(tempTree);
	tempTree->right = tempChild;
	tempChild = tempTree->left;
	tempTree->left = NULL;
	rh = (int) binary_tree_height(tempTree);
	tempTree->left = tempChild;
	return (lh - rh);
}
/**
 * binary_tree_height - height of a t
 * @t: t
 *
 * Return: height of the t
 */
size_t binary_tree_height(const binary_tree_t *t)
{
	if (t && (t->left || t->right))
		return (1 + _max(binary_tree_height(t->left),
					binary_tree_height(t->right)));
	return (0);
}
/**
 * _max - find max of two number
 * @a: number
 * @b: number
 *
 * Return: max of two number
 */
size_t _max(size_t a, size_t b)
{
	return (a > b ? a : b);
}
