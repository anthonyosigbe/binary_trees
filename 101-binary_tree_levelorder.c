#include "binary_trees.h"

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL. Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new = malloc(sizeof(levelorder_queue_t));

	return ((new ? (new->node = node, new->next = NULL, new) : NULL));
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	while (head)
	{
		levelorder_queue_t *tmp = head->next;

		free(head);
		head = tmp;
	}
}

/**
 * push - Pushes node's children into the levelorder_queue_t queue.
 * @node: The binary tree node to push children from.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 */
void push(binary_tree_t *node, levelorder_queue_t **tail, void (*func)(int))
{
	if (node->left)
		*tail = (*tail)->next = create_node(node->left);
	if (node->right)
		*tail = (*tail)->next = create_node(node->right);
	func(node->n);
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer to the head of the queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tmp = (*head)->next;

	free(*head);
	*head = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 * level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (!tree || !func)
		return;

	head = tail = create_node((binary_tree_t *)tree);
	if (!head)
		return;

	while (head)
	{
		push(head->node, &tail, func);
		pop(&head);
	}
	free_queue(head);
}
