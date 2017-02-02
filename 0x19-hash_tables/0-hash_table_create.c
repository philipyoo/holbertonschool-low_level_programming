#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table
 * @size: size of the array
 * Return: new hash table or NULL if error
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hsh;
	hash_node_t **a;
	unsigned long int i;

	hsh = malloc(sizeof(hash_table_t));
	if (hsh == NULL || size == 0)
		return (NULL);
	a = malloc(sizeof(hash_node_t *) * size);
	if (a == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		a[i] = NULL;

	hsh->array = a;
	hsh->size = size;

	return (hsh);
}
