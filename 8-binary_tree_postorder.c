#include "binary_trees.h"

/**
 * binary_tree_postorder - Navigates through a binary tree
 * using post-order traversal.
 * @tree: A pointer to the root node of the tree for traversal.
 * @func: A pointer to a function to be called for each node during traversal.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
