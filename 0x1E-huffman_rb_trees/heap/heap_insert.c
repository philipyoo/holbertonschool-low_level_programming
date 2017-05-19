#include <stdlib.h>
#include "heap.h"

/**
 * heap_insert - Insert a value in a Min Binary Heap
 * @heap: pointer to heap in which the node has to be inserted
 * @data: pointer containing data to store in new node
 * Return: Pointer to created node containing data, or NULL if failed
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *hold, *new_node;

	if (data == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_node_t));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = data;

	if (heap->root == NULL)
	{
		new_node->parent = NULL;
		heap->root = new_node;
		heap->size += 1;
		return (new_node);
	}

	hold = get_parent_node(heap, get_power(heap));

	/* Set node */
	new_node->parent = hold;
	if (hold->left == NULL)
		hold->left = new_node;
	else
		hold->right = new_node;

	/* Shift tree based on values after inserting new node. */
	min_swap_nodes(heap, new_node);

	heap->size += 1;
	return (new_node);
}

/**
 * min_swap_nodes - Swap nodes given a node that was recently placed in tree
 * @heap: pointer to heap in which the node has to be inserted
 * @node: node to swap up the MIN Heap Tree
 */
void min_swap_nodes(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *hold;

	while (1)
	{
		hold = node->parent;
		if (hold == NULL)
		{
			heap->root = node;
			break;
		}
		if (heap->data_cmp(node->data, hold->data) > 0)
			break;
		if (hold->left == node)
		{
			node->left = hold;
			node->right = hold->right;
			if (hold->right)
				hold->right->parent = node;
		}
		else
		{
			node->right = hold;
			node->left = hold->left;
			if (hold->left)
				hold->left->parent = node;
		}

		node->parent = hold->parent;
		if (hold->parent)
		{
			if (hold->parent->left == hold)
				hold->parent->left = node;
			else
				hold->parent->right = node;
		}
		hold->parent = node;
		hold->left = NULL;
		hold->right = NULL;
	}
}

/**
 * get_parent_node - find the parent node of the new created node of min heap
 * @heap: pointer to heap in which the node has to be inserted
 * @power: power of 2 based on heap size
 * Return: pointer to parent node for new created node
 */
binary_tree_node_t *get_parent_node(heap_t *heap, size_t power)
{
	binary_tree_node_t *hold;
	size_t position;

	position = heap->size + 1;
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

	return (hold);
}
