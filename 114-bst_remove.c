#include "binary_trees.h"

/**
 * inorder_successor - Retrieves the minimum value of a binary search tree.
 * @root: Pointer to the root node of the BST to be searched.
 *
 * Return: The minimum value within the specified BST.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Removes a node from a binary search tree.
 * @root: Pointer to the root node of the BST.
 * @node: Pointer to the node to be deleted from the BST.
 *
 * Return: Pointer to the new root node after the deletion.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Recursively removes a node from a binary search tree.
 * @root: Pointer to the root node of the BST for node removal.
 * @node: Pointer to the current node in the BST.
 * @value: The value to be removed from the BST.
 *
 * Return: Pointer to the root node after the deletion.
 */
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursive(root, node->left, value));
		return (bst_remove_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Deletes a node from a binary search tree.
 * @root: Pointer to the root node of the BST for node removal.
 * @value: The value to be removed from the BST.
 *
 * Description: If the node to be deleted has two children,
 * it is replaced with its first in-order successor.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, root, value));
}
