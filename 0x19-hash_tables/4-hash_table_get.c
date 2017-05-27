#include "hash_tables.h"
#include <stdlib.h>

/**
 * hash_table_get - gets a value from the key in a hash table
 * @ht: the hash table
 * @key: the key string
 *
 * Return: The value string, NULL if not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp_node;

	if (invalid_ht(ht))
	{
		return (NULL);
	}

	/* initializations */
	tmp_node = NULL;
	index = 0;

	/* retrieve location */
	index = key_index((const unsigned char *) key, ht->size);

	/* retrieve node at location */
	tmp_node = ht->array[index];

	while (tmp_node != NULL)
	{
		if (tmp_node->key == NULL)
		{
			break;
		}

		if (_strcmp(key, tmp_node->key) == 0)
		{
			return (tmp_node->value);
		}
	}

	/* key not found */
	return (NULL);
}
