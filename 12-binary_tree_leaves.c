#include "binary_trees.h"

/**
 * binary_tree_leaves - Enumerate the leaves within a binary tree.
 * @tree: A reference to the root node of the tree
 * for the purpose of counting its leaves.
 *
 * Return: If the tree is NULL, the function should return 0,
 * as a NULL pointer is not considered a leaf.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += (!tree->left && !tree->right) ? 1 : 0;
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
