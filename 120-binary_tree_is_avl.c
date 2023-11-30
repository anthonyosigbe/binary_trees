#include "binary_trees.h"

/**
 * height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree for height measurement.
 *
 * Return: If tree is NULL, the function returns 0;
 * otherwise, it returns the height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - Verifies whether a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree under examination.
 * @lo: The value of the smallest visited node up to this point.
 * @hi: The value of the largest visited node up to this point.
 *
 * Return: Returns 1 if the tree is a valid AVL tree;
 * otherwise, returns 0.
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t lhgt, rhgt, diff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		lhgt = height(tree->left);
		rhgt = height(tree->right);
		diff = lhgt > rhgt ? lhgt - rhgt : rhgt - lhgt;
		if (diff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}

/**
 * binary_tree_is_avl - Determines whether a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree under examination.
 *
 * Return: Returns 1 if the tree is a valid AVL tree;
 * otherwise, returns 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
