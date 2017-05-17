#include "hash_tables.h"

#include <stdlib.h>

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

	if (invalid_ht(ht) || key == NULL || value == NULL)
	{
		return (0);
	}

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, ht->size);

	tmp_node = *(ht->array + index);

	/* case 1: there is no node at this index */
	if (tmp_node == NULL)
	{
		node = make_node(key, value);
		if (node == NULL)
		{
			return (0);
		}
		*(ht->array + index) = node;
		return (1);
	}

	return (ht_set_helper(tmp_node, key, value));
}

/**
 * ht_set_helper - traverses hash table linked list; updates if key is found,
 * appends a node at the end if key is not found.
 *
 * @tmp_node: pointer to first node of the linked list.
 * @key: key string to insert.
 * @value: value string to insert.
 *
 * Return: 1 on success, 0 on failure.
 */
int ht_set_helper(hash_node_t *tmp_node, const char *key, const char *value)
{
	hash_node_t *node;

	while (tmp_node != NULL)
	{
		/* case 2: simple update */
		if (_strcmp(key, tmp_node->key) == 0)
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

	/*
	 * case 3: there were nodes at this index.
	 * We are now at the last node.
	 */

	node = make_node(key, value);
	if (node == NULL)
	{
		return (0);
	}

	tmp_node->next = node;

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
