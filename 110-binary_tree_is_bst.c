#include "binary_trees.h"

/**
 * is_bst_help - Verifies whether a binary tree
 * is a valid binary search tree.
 * @tree: Pointer to the root node of the tree under examination.
 * @lo: The value of the smallest visited node up to this point.
 * @hi: The value of the largest visited node up to this point.
 *
 * Return: Returns 1 if the tree is a valid BST;
 * otherwise, returns 0.
 */
int is_bst_help(const binary_tree_t *tree, int lo, int hi)
{
	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		return (is_bst_help(tree->left, lo, tree->n - 1) &&
			is_bst_help(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Determines whether a binary tree
 * is a valid binary search tree.
 * @tree: Pointer to the root node of the tree under examination.
 *
 * Return: Returns 1 if the tree is a valid BST;
 * otherwise, returns 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_help(tree, INT_MIN, INT_MAX));
}
