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

	if (size == 0)
		return (NULL);

	hsh = malloc(sizeof(hash_table_t));
	if (hsh == NULL)
		return (NULL);
	a = malloc(sizeof(hash_node_t *) * size);
	if (a == NULL)
		return (NULL);

	hsh->array = a;
	hsh->size = size;

	return (hsh);
}
