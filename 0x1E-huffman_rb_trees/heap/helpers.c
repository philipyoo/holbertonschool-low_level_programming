#include "heap.h"

/**
 * get_power - helper method to find power of 2 based on heap size
 * @heap: pointer to heap in which the node has to be inserted
 * Return: power of 2 based on heap size
 */
size_t get_power(heap_t *heap)
{
	size_t power, position;

	power = 1;
	position = heap->size + 1;
	while ((power * 2) <= position)
		power *= 2;

	return (power);
}
