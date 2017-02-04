#include "hash_tables.h"

/**
 * hash_table_get - Retrieve a value associated with a key
 * @ht: hash table
 * @key: key to use to retrieve value
 * Return: value associated with key or NULL if key not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *tmp;
	unsigned long int idx;

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	if (tmp == NULL)
		return (NULL);

	while (strcmp(tmp->key, key) != 0)
		tmp = tmp->next

	return (tmp->value);
}
