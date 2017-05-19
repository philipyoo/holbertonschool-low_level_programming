#include "heap.h"

/**
 * heap_delete - Deallocates a heap
 * @heap: pointer to heap
 * @free_data: pointer to function that will be used to free contents of a node
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap == NULL)
	{
		if (heap->root == NULL)
			return;
		free(heap);
	}

	recurse_delete_heap(heap->root, free_data);
	free(heap);
}

/**
 * recurse_delete_heap - delete heap helper function to recurse down heap
 * @node: pointer to currently focused node
 * @free_data: pointer to function that will be used to free contents of a node
 */
void recurse_delete_heap(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (node == NULL)
		return;

	if (node->left != NULL)
		recurse_delete_heap(node->left, free_data);
	if (node->right != NULL)
		recurse_delete_heap(node->right, free_data);
	if (free_data != NULL)
		free_data(node);
	free(node);
}
