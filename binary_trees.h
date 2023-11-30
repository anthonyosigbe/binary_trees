#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include "limits.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;


/**
 * struct levelorder_queue_s - Struct for levelorder queue node.
 * @node: Pointer to the binary tree node.
 * @next: Pointer to the next node in the queue.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;


void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t
		*first, const binary_tree_t *second);
levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int is_bst_help(const binary_tree_t *tree, int lo, int hi);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);
avl_t *sorted_array_to_avl_recursive(int *array, size_t start,
                size_t end, avl_t *parent);
int is_max_heap(const binary_tree_t *tree);
int is_complete(const binary_tree_t *tree, size_t index, size_t nodes, size_t count);
size_t count_nodes(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
size_t binary_tree_size(const binary_tree_t *tree);
heap_t *array_to_heap(int *array, size_t size);
size_t tree_height(const heap_t *tree);
size_t tree_size_h(const binary_tree_t *tree);
void _preorder(heap_t *tree, heap_t **node, size_t height);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);
#endif /* _BINARY_TREES_H_ */
