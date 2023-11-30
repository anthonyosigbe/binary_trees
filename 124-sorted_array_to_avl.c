#include "binary_trees.h"

/**
 * sorted_array_to_avl_recursive - Helper function,
 * to build AVL tree recursively
 * @array: Pointer to the first element of the array
 * @start: Index of the first element in the current subtree
 * @end: Index of the last element in the current subtree
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the current subtree
 */
avl_t *sorted_array_to_avl_recursive(int *array, size_t start,
                size_t end, avl_t *parent);

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return ((sorted_array_to_avl_recursive(array, 0, size - 1, NULL)));
}

/**
 * sorted_array_to_avl_recursive - Helper function,
 * to build AVL tree recursively
 * @array: Pointer to the first element of the array
 * @start: Index of the first element in the current subtree
 * @end: Index of the last element in the current subtree
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the current subtree
 */
avl_t *sorted_array_to_avl_recursive(int *array, size_t start,
                size_t end, avl_t *parent)
{
	size_t mid;
	avl_t *new_node;
	
	if (start > end)
		return (NULL);
	mid = (start + end) / 2;

	new_node = binary_tree_node(parent, array[mid]);

	if (new_node == NULL)
		return (NULL);
	new_node->left = sorted_array_to_avl_recursive(array,
			start, mid - 1, new_node);
	new_node->right = sorted_array_to_avl_recursive(array, mid + 1,
			end, new_node);

	return (new_node);
}
