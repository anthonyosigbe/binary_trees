#include "binary_trees.h"

/**
 * binary_tree_depth - Calculate the depth of a node in a binary tree.
 * @tree: A pointer to the node for which to measure the depth.
 *
 * Return: If tree is NULL, the function returns 0.
 * Otherwise, it returns the depth.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return (tree ? (tree->parent ? 1 + binary_tree_depth(tree->parent) : 0) : 0);
}

