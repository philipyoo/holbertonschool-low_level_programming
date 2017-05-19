#include "huffman.h"
#include <stdio.h>

/**
 * huffman_priority_queue - build a priority queue, first step of huffman codes
 * @data: array of characters of size `size`
 * @freq: array of associated frequencies (also size `size`)
 * @size: size of other argument arrays
 * Return: pointer to created min heap (aka priority queue)
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	size_t i;
	heap_t *new_heap;
	binary_tree_node_t *new_node, *parent;
	symbol_t *sym;

	new_heap = malloc(sizeof(heap_t));
	if (new_heap == NULL)
		return (NULL);
	new_heap->size = 0;
	new_heap->data_cmp = NULL;

	printf("Passed stage 1\n");

	for (i = 0; i < size; i++)
	{
		printf("Looping %lu\n", i);
		sym = malloc(sizeof(symbol_t));
		if (sym == NULL)
			return (NULL);
		sym->data = data[i];
		sym->freq = freq[i];

		printf("sym->data: %c\n", sym->data);

		new_node = malloc(sizeof(binary_tree_node_t));
		if (new_node == NULL)
			return (NULL);
		new_node->data = sym;
		new_node->left = NULL;
		new_node->right = NULL;

		printf("new_node->sym->data :  %c\n", ((symbol_t *)new_node->data)->data);
		printf("new_node->sym->freq :  %lu\n", ((symbol_t *)new_node->data)->freq);

		printf("Stage 2\n");

		if (new_heap->root == NULL)
		{
			printf("Setting root..\n");
			new_heap->root = new_node;
			new_node->parent = NULL;
			printf("new_heap->root: %p\n", (void *)new_heap->root);
		}
		else
		{
			printf("Stage 3\n");
			parent = get_parent_node(new_heap, get_power(new_heap));
			printf("Stage 4\n");

			if (parent->left == NULL)
				parent->left = new_node;
			else
				parent->right = new_node;
			new_node->parent = parent;
		}

		new_heap->size++;
		printf("new_heap->size: %lu\n", new_heap->size);
	}
	return (new_heap);
}

/**
 * symbol_cmp - Compares two symbols
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two symbol frequencies
 */
int symbol_cmp(void *p1, void *p2)
{
	int *n1, *n2;

	n1 = (int *)(((symbol_t *)p1)->freq);
	n2 = (int *)(((symbol_t *)p2)->freq);
	return (*n1 - *n2);
}
