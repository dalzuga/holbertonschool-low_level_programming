#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp_node;

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

		if (strcmp(key, tmp_node->key) == 0)
		{
			return tmp_node->value;
		}
	}

	/* key not found */
	return NULL;
}
