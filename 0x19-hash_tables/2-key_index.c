#include "hash_tables.h"

/**
 * key_index - Gives the index of a key
 * @key: key of key/value pair
 * @size: size of array of the hash table
 * Return: index at which key/value pair should be stored in array of hash table
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (size == 0)
		return (0);
	return (hash_djb2(key)% size);
}
