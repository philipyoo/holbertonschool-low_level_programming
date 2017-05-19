#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

/**
 * heap_extract - Extract the root node in a Min Binary Heap
 * @heap: pointer to heap
 * Return: pointer to data that was stored in the root node of the heap or NULL
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *lastnode;
	void *hold;

	if (heap == NULL || heap->root == NULL)
		return (NULL);

	hold = heap->root->data;
	lastnode = get_last_node(heap, get_power(heap));

	/* determine if lastnode is same as root node */
	if (heap->data_cmp(heap->root->data, lastnode->data) == 0)
	{
		free(heap->root->data);
		free(heap->root);
		heap->root = NULL;
		heap->size -= 1;
		return (hold);
	}

	/* Swap root node with last node */
	/* Save reference to data in root node, delete the root node */
	heap->root->data = lastnode->data;
	if (heap->size % 2 == 1)
		lastnode->parent->right = NULL;
	else
		lastnode->parent->left = NULL;
	free(lastnode);
	heap->size -= 1;

	swap_root_down(heap);

	return (hold);
}

/**
 * get_last_node - find the last node of min heap
 * @heap: pointer to heap in which the node has to be inserted
 * @power: power of 2 based on heap size
 * Return: pointer to last node of min heap
 */
binary_tree_node_t *get_last_node(heap_t *heap, size_t power)
{
	binary_tree_node_t *hold;
	size_t position;

	position = heap->size;
	hold = heap->root;
	while (power > 2)
	{
		if (position >= power)
			position -= power;

		if (position < (power / 2))
			hold = hold->left;
		else
			hold = hold->right;

		power /= 2;
	}

	if (hold->right)
		return (hold->right);
	return (hold->left);
}

/**
 * swap_root_down - extract helper method to reorganize min heap to be valid
 * @heap: pointer to heap
 */
void swap_root_down(heap_t *heap)
{
	binary_tree_node_t *current, *tmp;

	/* Swap New root node downwards */
	current = heap->root;
	while (current->left)
	{
		if (current->right &&
		    heap->data_cmp(current->left->data,
				   current->right->data) > 0)
		{
			tmp = current->data;
			current->data = current->right->data;
			current->right->data = tmp;

			current = current->right;
		}
		else if (heap->data_cmp(current->data, current->left->data) > 0)
		{
			tmp = current->data;
			current->data = current->left->data;
			current->left->data = tmp;

			current = current->left;
		}
		else
			break;
	}
}
