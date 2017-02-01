#include "hash_tables.h"

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *tmp;
	unsigned long int idx;

	idx = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[idx];

	if (tmp == NULL)
		return (NULL);
	else
		return (tmp->value);
}
