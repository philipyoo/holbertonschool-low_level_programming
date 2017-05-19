#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdlib.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

/* general helper methods */
size_t get_power(heap_t *heap);

/* helper methods for insert */
binary_tree_node_t *get_parent_node(heap_t *heap, size_t power);
void min_swap_nodes(heap_t *heap, binary_tree_node_t *node);

/* helper methods for extract */
void swap_root_down(heap_t *heap);
binary_tree_node_t *get_last_node(heap_t *heap, size_t power);

/* helper methods for delete */
void recurse_delete_heap(binary_tree_node_t *node, void (*free_data)(void *));

/* functions */
heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));
#endif
