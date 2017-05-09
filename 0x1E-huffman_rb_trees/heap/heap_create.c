#include <stdlib.h>
#include "heap.h"

/**
 * heap_create - Creates a Heap data structure. Set root to NULL and size to 0.
 * @data_cmp: pointer to a comparison function
 * Return: pointer to the created `heap_t` structure, or Null on fail
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap;

	new_heap = malloc(sizeof(heap_t));
	if (new_heap == NULL)
		return (NULL);

	new_heap->size = 0;
	new_heap->root = NULL;
	new_heap->data_cmp = data_cmp;

	return (new_heap);
}
