#include "hash_tables.h"

/**
 * hash_table_delete - delete given hash table
 * @ht: hash table given
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *tmp, *prev;
	unsigned long int sz, i;

	if (ht == NULL)
		return;
	if (ht->array == NULL)
	{
		free(ht);
		return;
	}

	for (i = 0, sz = ht->size; i < sz; i++)
	{
		tmp = ht->array[i];
		while (tmp)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev->key);
			free(prev->value);
			free(prev);
		}
	}

	free(ht->array);
	free(ht);
}
