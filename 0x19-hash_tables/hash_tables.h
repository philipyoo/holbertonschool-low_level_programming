#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct hash_node_s - nodes representing each key value pair within hash table
 * @key : The string key is unique in the HashTable
 * @value : The value corresponding to a key
 * @next : A pointer to the next node of the list
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

hash_table_t *hash_table_create(unsigned long int size);
#endif
