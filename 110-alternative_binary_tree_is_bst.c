#include "binary_trees.h"
#include "limits.h"
int is_bst_help(const binary_tree_t *tree, int *largest);

#define VERBOSE 0

/**
 * binary_tree_is_bst - Determines whether a binary tree,
 * is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree under examination.
 *
 * Return: Returns 1 if the tree is a valid BST; otherwise, returns 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int tracker = INT_MIN;

	if (tree == NULL)
		return (0);
	return (is_bst_help(tree, &tracker));
}


/**
 * is_left - Verifies if a node is a left child of another node.
 * @node: Pointer to the node to be checked.
 * Return: Returns 1 if it is a left child; otherwise, returns 0.
 */
int is_left(const binary_tree_t *node)
{
	if (node && node->parent)
		return (node->parent->left == node);
	return (0);
}
/**
 * is_right - Verifies if a node is a right child of another node.
 * @node: Pointer to the node to be checked.
 * Return: Returns 1 if it is a right child; otherwise, returns 0.
 */
int is_right(const binary_tree_t *node)
{
	if (node && node->parent)
		return (node->parent->right == node);
	return (0);
}

#if !VERBOSE
/**
 * is_bst_help - Verifies if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree under examination.
 * @largest: Value of the largest node visited so far.
 *
 * Return: Returns 1 if the tree is a valid BST; otherwise, returns 0.
 */
int is_bst_help(const binary_tree_t *tree, int *largest)
{
	int ret = 1;

	if (tree != NULL)
	{
		ret *= is_bst_help(tree->left, largest);
		if (tree->n < *largest)
			return (0);
		*largest = tree->n;
		if (is_left(tree) && !(tree->n < tree->parent->n))
			return (0);
		if (is_right(tree) && !(tree->n > tree->parent->n))
			return (0);
		ret *= is_bst_help(tree->right, largest);
	}
	return (ret);
}
#else
/**
 * is_bst_help - Verifies if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree under examination.
 * @largest: Value of the largest node visited so far.
 *
 * Return: Returns 1 if the tree is a valid BST;
 * otherwise, returns 0.
 */
int is_bst_help(const binary_tree_t *tree, int *largest)
{
	int ret = 1;

	if (tree)
	{
		printf("Moving to %d\n", tree->n);
		ret *= is_bst_help(tree->left, largest);
		printf("done with left tree for %d: %d\n", tree->n, ret);
		printf("largest = %d\n", *largest);
		if (tree->n < *largest)
			return (0);
		*largest = tree->n;
		printf("largest = %d\n", *largest);
		if (is_left(tree))
			printf("%d is %s than %d\n",
				tree->n,
				(tree->n < tree->parent->n) ? "smaller" : "larger",
				tree->parent->n);
		if (is_left(tree) && !(tree->n < tree->parent->n))
		{
			printf("%d is left child\n", tree->n);
			return (0);
		}
		if (is_right(tree))
			printf("%d is %s than %d\n",
				tree->n,
				(tree->n < tree->parent->n) ? "smaller" : "larger",
				tree->parent->n);
		if (is_right(tree) && !(tree->n > tree->parent->n))
		{
			printf("%d is right child\n", tree->n);
			return (0);
		}
		ret *= is_bst_help(tree->right, largest);
		printf("done with right tree for %d: %d\n", tree->n, ret);
		if (tree->parent)
			printf("Moving back to %d\n", tree->parent->n);
	}
	return (ret);
}
#endif /* VERBOSE */
