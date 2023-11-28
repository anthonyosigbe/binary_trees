#include "binary_trees.h"

/**
 * binary_tree_balance - Calculates the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree
 * whose balance factor is being measured.
 *
 * Return: If tree is NULL, returns 0;
 * otherwise, returns the balance factor.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return ((int)(binary_tree_height(tree->left)
			- binary_tree_height(tree->right)));
}

/**
 * binary_tree_height - Computes the height of a binary tree.
 * @tree: A pointer to the root node of the tree
 * whose height is being measured.
 *
 * Return: If tree is NULL, the function returns 0;
 * otherwise, it returns the height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}
