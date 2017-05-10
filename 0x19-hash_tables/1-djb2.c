#include "hash_tables.h"

/**
 * hash_djb2 - returns a hash based on djb2 algorithm
 * @str: string to hash
 *
 * Return: the hash result.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}

	return (hash);
}
