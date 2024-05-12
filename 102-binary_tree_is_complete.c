#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop(levelorder_queue_t **head);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new node for the level order
 * queue.
 *
 * @node: The binary tree node to be stored in the new node.
 *
 * Description:
 * This function creates a new node for the level order
 * queue. The node will store
 * a binary tree node and will be used in level order
 * traversal of the binary tree.
 *
 * Return:
 * A pointer to the newly created node, or NULL if
 * memory allocation fails.
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
 * free_queue - frees a levelorder_queue_t list
 * @head: pointer to the head of the list
 *
 * Description: This function iterates through a
 * levelorder_queue_t list
 * and frees each element. It uses a temporary
 * pointer to not lose
 * reference to the next node in the list.
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
 * push - Pushes a binary tree node into a level
 * order queue.
 * @node: The binary tree node to push into the queue.
 * @head: The head of the level order queue.
 * @tail: A double pointer to the tail of the
 * level orderqueue.
 *
 * Description: This function creates a new node
 * for the level order queue
 * and pushes it to the end of the queue.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail)
{
	levelorder_queue_t *new;

	new = create_node(node);
	if (new == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new;
	*tail = new;
}

/**
 * pop - Pops a binary tree node from the front of a level
 * order queue.
 * @head: A double pointer to the head of the level order
 * queue.
 *
 * Description: This function frees the front node of the
 * level order queue
 * and updates the head pointer to point to the next node
 * in the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp;

	tmp = (*head)->next;
	free(*head);
	*head = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is
 * complete.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Description: This function checks if a binary tree is
 * complete. A binary tree
 * is considered complete if all levels are completely
 * filled except possibly
 * for the last level, which is filled from left to right.
 *
 * Return: If the tree is complete, 1. Otherwise, 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->left, head, &tail);
		}
		else
			flag = 1;
		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(head);
				return (0);
			}
			push(head->node->right, head, &tail);
		}
		else
			flag = 1;
		pop(&head);
	}
	return (1);
}
