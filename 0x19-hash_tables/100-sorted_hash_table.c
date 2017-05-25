#include "hash_tables.h"
#include "sht_functions.h"
#include <stdlib.h>

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht_ptr;
	unsigned long int i;

	/* check for valid size */
	if (size < 1)
	{
		return (NULL);
	}

	sht_ptr = malloc(sizeof(shash_table_t));
	if (sht_ptr == NULL)
	{
		return (NULL);
	}
	sht_ptr->size = 0;
	sht_ptr->array = NULL;
	sht_ptr->shead = NULL;
	sht_ptr->stail = NULL;

	sht_ptr->array = malloc(sizeof(shash_node_t *) * size);
	if (sht_ptr->array == NULL)
	{
		free(sht_ptr);
		return (NULL);
	}
	sht_ptr->size = size;

	/* zero out the array */
	for (i = 0; i < size; i++)
	{
		*(sht_ptr->array) = NULL;
		(sht_ptr->array)++;
	}

	/* pointer arithmetic to return ~sht_ptr->array~ to the beginning */
	sht_ptr->array = (sht_ptr->array) - i;

	return (sht_ptr);
}

int shash_table_set(shash_table_t *sht, const char *key, const char *value)
{
	/* declarations */
	unsigned long int index;
	shash_node_t *node, *tmp_node;

	if (invalid_sht(sht) || key == NULL)
	{
		return (0);
	}

	if (_strcmp(key, "") == 0)
	{
		return (0);
	}

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, sht->size);

	tmp_node = *(sht->array + index);

	/* case 1: there is no node at this index */
	if (tmp_node == NULL)
	{
		node = make_node(key, value);
		if (node == NULL)
		{
			return (0);
		}
		*(sht->array + index) = node;
		return (1);
	}

	return (sht_set_helper(tmp_node, key, value));
}

/**
 * sht_set_helper - traverses hash table linked list; updates if key is found,
 * appends a node at the end if key is not found.
 *
 * @tmp_node: pointer to first node of the linked list.
 * @key: key string to insert.
 * @value: value string to insert.
 *
 * Return: 1 on success, 0 on failure.
 */
int sht_set_helper(shash_node_t *tmp_node, const char *key, const char *value)
{
	shash_node_t *node;

	while (tmp_node != NULL)
	{
		/* case 2: simple update */
		if (_strcmp(key, tmp_node->key) == 0)
		{
			return (update_sht_node(tmp_node, value));
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

	node = make_snode(key, value);
	if (node == NULL)
	{
		return (0);
	}

	tmp_node->next = node;
	return (1);
}

/**
 * make_sht_node - makes a sorted hash table node
 *
 * @key: key string to put in node
 * @value: value string to put in node
 *
 * Return: the address of the node.
 */
shash_node_t *make_sht_node(const char *key, const char *value)
{
	/* declarations */
	shash_node_t *node;

	/* allocs */
	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		return (NULL);
	}

	/* inits */
	node->key = _strdup(key);
	if (value == NULL)
	{
		node->value = NULL;
	}
	else
	{
		node->value = _strdup(value);
	}
	node->next = NULL;

	return (node);
}

/**
 * update_sht_node - updates the value in a node
 *
 * @tmp_node: node to change
 * @value: string to change ~node->value~ to
 *
 * Return: 1 on success, 0 on failure.
 */
int update_sht_node(shash_node_t *tmp_node, const char *value)
{
	free(tmp_node->value);

	if (value == NULL)
	{
		tmp_node->value = NULL;
		return (1);
	}

	tmp_node->value = _strdup(value);
	if (tmp_node->value == NULL)
	{
		return (0);
	}
	return (1);
}