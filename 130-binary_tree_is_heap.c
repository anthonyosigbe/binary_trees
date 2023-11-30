#include "binary_trees.h"

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    if (!is_complete(tree, 0, count_nodes(tree), 0) ||
        !is_max_heap(tree))
        return 0;

    return 1;
}

/**
 * count_nodes - Count the number of nodes in the binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Number of nodes in the tree
 */
size_t count_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

/**
 * is_complete - Check if the binary tree is complete
 * @tree: Pointer to the root node of the tree
 * @index: Index of the current node
 * @nodes: Total number of nodes in the tree
 * @count: Number of nodes visited so far
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes, size_t count)
{
    if (tree == NULL)
        return 1;

    if (index >= nodes || count >= nodes)
        return 0;

    return is_complete(tree->left, 2 * index + 1, nodes, count + 1) &&
           is_complete(tree->right, 2 * index + 2, nodes, count + 1);
}

/**
 * is_max_heap - Check if the binary tree is a Max Binary Heap
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is a Max Binary Heap, 0 otherwise
 */
int is_max_heap(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 1;

    if ((tree->left != NULL && tree->n < tree->left->n) ||
        (tree->right != NULL && tree->n < tree->right->n))
        return 0;

    return is_max_heap(tree->left) && is_max_heap(tree->right);
}
