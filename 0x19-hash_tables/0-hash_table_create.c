#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table
 * @size: size of the array
 * Return: new hash table or NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hsh;
	unsigned long int i;

	hsh = malloc(sizeof(hash_table_t));
	if (hsh == NULL || size == 0)
		return (NULL);
	hsh->array = malloc(sizeof(hash_node_t *) * size);
	if (hsh->array == NULL)
		return (NULL);

	hsh->size = size;

	for (i = 0; i < size; i++)
		hsh->array[i] = NULL;

	return (hsh);
}
