#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * using if and else statement
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *driver, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	driver = tree->left;
	tmp = driver->right;
	driver->right = tree;
	tree->left = tmp;
	if (tmp != NULL)
		tmp->parent = tree;
	tmp = tree->parent;
	tree->parent = driver;
	driver->parent = tmp;
	if (tmp != NULL)
	{
		if (tmp->left == tree)
			tmp->left = driver;
		else
			tmp->right = driver;
	}

	return (driver);
}

