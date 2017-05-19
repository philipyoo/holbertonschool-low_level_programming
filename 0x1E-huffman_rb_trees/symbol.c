#include "huffman.h"

/**
 * symbol_create - creates a `symbol_t` data structure
 * @data: data to be stored in struct
 * @freq: associated frequency
 * Return: pointer to the created struct, or NULL
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *cr;

	cr = malloc(sizeof(symbol_t));
	if (cr == NULL)
		return (NULL);
	cr->data = data;
	cr->freq = freq;

	return cr;
}
