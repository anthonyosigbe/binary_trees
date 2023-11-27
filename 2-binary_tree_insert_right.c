#include "binary_trees.h"

/**
 * binary_tree_insert_right - Add a node as the right child,
 * of another node in a binary tree.
 * @parent: A pointer to the node where the right child will be inserted.
 * @value: The value to be stored in the new node.
 *
 * Return: Pointer to the new node, or NULL if there's an error.
 *
 * Description: If parent already has a right-child, the new node
 * takes its place and the old right-child is set,
 * as the right-child of the new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
