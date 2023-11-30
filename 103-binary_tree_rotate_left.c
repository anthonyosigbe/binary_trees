#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to be rotated.
 *
 * Return: A pointer to the new root node after the left rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree == NULL || tree->right == NULL)
		return (NULL);

	binary_tree_t *pivot = tree->right;

	tree->right = pivot->left;

	if (pivot->left != NULL)
		pivot->left->parent = tree;

	pivot->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	pivot->left = tree;
	tree->parent = pivot;

	return (pivot);
}
