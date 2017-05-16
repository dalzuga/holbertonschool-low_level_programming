#include "hash_tables.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_set - set a key-value pair in a hash table
 *
 * @ht: the hash table
 * @key: the key string
 * @value: the value string
 *
 * Return: 1 on success, 0 on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	/* declarations */
	unsigned long int index;
	hash_node_t *node, *tmp_node;

	if (invalid_ht(ht))
	{
		return (0);
	}

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, ht->size);

	tmp_node = *(ht->array + index);

	/* traverse the list until tmp_node is the last */
	while (tmp_node != NULL)
	{
		/* simple update */
		if (strcmp(key, tmp_node->key) == 0)
		{
			free(tmp_node->value);
			tmp_node->value = _strdup(value);
			if (tmp_node->value == NULL)
			{
				return (0);
			}
			return (1);
		}

		if (tmp_node->next == NULL)
		{
			break;
		}

		tmp_node = tmp_node->next;
	}

	node = make_node(key, value);
	if (node == NULL)
	{
		return (0);
	}

	/* simple case: there was no node at this index */
	if (tmp_node == NULL)
	{
		*(ht->array + index) = node;
	}
	/* there were nodes at this index, but we are now at the last node */
	else
	{
		tmp_node->next = node;
	}

	return (1);
}

/**
 * make_node - makes a hash table node
 *
 * @key: key string to put in node
 * @value: value string to put in node
 *
 * Return: the address of the node.
 */
hash_node_t *make_node(const char *key, const char *value)
{
	/* declarations */
	hash_node_t *node;

	/* allocs */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		return (NULL);
	}

	/* inits */
	node->key = _strdup(key);
	node->value = _strdup(value);
	node->next = NULL;

	return (node);
}
