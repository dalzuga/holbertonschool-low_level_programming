#include "hash_tables.h"

/**
 * key_index - returns index depending on table size
 * @key: the key string
 * @size: the hash table size
 *
 * Return: The index key generated.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = 0;

	index = hash_djb2(key) % size; /* set key index according to size */

	return (index);
}
