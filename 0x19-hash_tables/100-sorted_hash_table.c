#include "hash_tables.h"
#include "sht_functions.h"
#include <stdlib.h>

/**
 * shash_table_create - creates a sorted hash table.
 * @size: size of table.
 *
 * Return: pointer to sorted hash table created, NULL on error.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht_ptr;
	unsigned long int i;

	/* check for valid size */
	if (size < 1)
	{
		return (NULL);
	}

	/* allocate shash table */
	sht_ptr = malloc(sizeof(shash_table_t));
	if (sht_ptr == NULL)
	{
		return (NULL);
	}

	/* inits */
	sht_ptr->size = 0;
	sht_ptr->array = NULL;
	sht_ptr->shead = NULL;
	sht_ptr->stail = NULL;

	/* allocate nodes */
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

/**
 * shash_table_set - set a key-value pair in a sorted hash table
 *
 * @sht: the sorted hash table
 * @key: the key string
 * @value: the value string
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *sht, const char *key, const char *value)
{
	/* declarations */

	if (invalid_sht(sht) || key == NULL)
	{
		return (0);
	}

	if (_strcmp(key, "") == 0)
	{
		return (0);
	}

	return (sht_set_1a(sht, key, value));
}

/**
 * sht_set_1a - set a key-value pair in a sorted hash table
 *
 * @sht: the sorted hash table
 * @key: the key string
 * @value: the value string
 *
 * Return: 1 on success, 0 on failure.
 */
int sht_set_1a(shash_table_t *sht, const char *key, const char *value)
{
	/* declarations */
	unsigned long int index = 0;
	shash_node_t *node = NULL, **ll_head = NULL;

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, sht->size);

	ll_head = sht->array + index;

	/* case 1a: there are no nodes */
	if ((sht->shead == NULL) && (sht->stail == NULL))
	{
		*ll_head = make_sht_node(key, value);
		if (*ll_head == NULL)
		{
			return (0);
		}

		/* create sorted double linked list */
		sht->shead = *ll_head;
		sht->stail = *ll_head;
	}

	return (sht_set_1b(sht, key, value));
}

/**
 * sht_set_1b - set a key-value pair in a sorted hash table
 *
 * @sht: the sorted hash table
 * @key: the key string
 * @value: the value string
 *
 * Return: 1 on success, 0 on failure.
 */
int sht_set_1b(shash_table_t *sht, const char *key, const char *value)
{
	/* declarations */
	unsigned long int index = 0;
	shash_node_t *node = NULL, **ll_head = NULL;

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, sht->size);

	ll_head = sht->array + index;

	/*
	 * case 1b: there are nodes in the hash table, but there is no node at
	 * this index
	 */
	if (*ll_head == NULL)
	{
		node = make_sht_node(key, value);
		if (node == NULL)
		{
			return (0);
		}

		*ll_head = node;

		return (sht_insert_dll(sht, node));
	}

	return (sht_set_2(sht, key, value));
}

/**
 * sht_insert_dll - insert a node at the end of the ordered linked list of a
 * sorted hash table.
 *
 * @sht: the sorted hash table
 * @node: pointer to the node to insert
 *
 * Return: 1 on success; this function always succeeds.
 */
int sht_insert_dll(shash_table_t *sht, shash_node_t *node)
{
	shash_node_t tmp_node = sht->stail;

	/* tail->next points to node */
	tmp_node->snext = node;
	/* node->sprev points to tail */
	node->sprev = tmp_node;
	/* move tail forward */
	sht->stail = node;

	return (1);
}

/**
 * sht_set_2 - set a key-value pair in a sorted hash table
 *
 * @sht: the sorted hash table
 * @key: the key string
 * @value: the value string
 *
 * Return: 1 on success, 0 on failure.
 */
int sht_set_2(shash_table_t *sht, const char *key, const char *value)
{
	/* declarations */
	

	/* case 2: we have a collision; key update or new key */
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
