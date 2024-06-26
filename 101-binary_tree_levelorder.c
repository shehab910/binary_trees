#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @n: The binary tree node to print and push.
 * @h: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @f: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *n, levelorder_queue_t *h,
		levelorder_queue_t **tail, void (*f)(int))
{
	levelorder_queue_t *new;

	f(n->n);
	if (n->left != NULL)
	{
		new = create_node(n->left);
		if (new == NULL)
		{
			free_queue(h);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
	if (n->right != NULL)
	{
		new = create_node(n->right);
		if (new == NULL)
		{
			free_queue(h);
			exit(1);
		}
		(*tail)->next = new;
		*tail = new;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @h: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **h)
{
	levelorder_queue_t *tmp;

	tmp = (*h)->next;
	free(*h);
	*h = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree
 * using level-order traversal.
 * @t: A pointer to the root node of the tree to traverse.
 * @f: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *t, void (*f)(int))
{
	levelorder_queue_t *head, *tail;

	if (t == NULL || f == NULL)
		return;

	head = tail = create_node((binary_tree_t *)t);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		pint_push(head->node, head, &tail, f);
		pop(&head);
	}
}
