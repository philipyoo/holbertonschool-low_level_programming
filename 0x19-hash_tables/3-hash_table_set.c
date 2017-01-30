#include "hash_tables.h"

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: hash table to add to
 * @key: key to add
 * @value: value to store for key
 * Return: 1 if success, 0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *newpair, *tmp;
	unsigned long int idx;

	newpair = malloc(sizeof(hash_node_t));
	if (newpair == NULL)
		return (0);

	newpair->key = strdup(key);
	newpair->value = strdup(value);
	newpair->next = NULL;

	idx = key_index((const unsigned char *)key, ht->size);
	if (ht->array[idx] == NULL)
		ht->array[idx] = newpair;
	else
	{
		tmp = ht->array[idx];
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newpair;
	}

	return (1);
}
