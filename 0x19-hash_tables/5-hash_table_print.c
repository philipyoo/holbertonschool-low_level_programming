#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *tmp;
	unsigned long int i;
	int toggle;

	printf("{");

	for (i = 0, toggle = 0; i < ht->size; i++)
	{
		tmp = ht->array[i];
		if (tmp != NULL)
		{
			if (toggle == 1)
				printf(", ");
			printf("'%s': '%s'", tmp->key, tmp->value);
			toggle = 1;
		}
	}

	printf("}\n");
}
