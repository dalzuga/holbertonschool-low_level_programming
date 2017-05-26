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

	return (sht_set_ordered(sht, key, value));
}

/**
 * sht_set_ordered - set a key-value pair in a sorted hash table
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
	shash_node_t *node = NULL, **ll_head = NULL, **sll_head = NULL;

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, sht->size);

	ll_head = sht->array + index;

	/* case 1a: there are no nodes  */
	if ((sht->shead == NULL) && (sht->stail == NULL))
	{
		sht->shead = make_sht_node(key, value);
		if (sht->shead == NULL)
		{
			return (0);
		}
		sht->stail = sht->shead;
	}

	/* case 1b: there is no node at this index */
	if (*ll_head == NULL)
	{
		return (put_node_index(ll_head, key, value));
	}

	if (sht_set_ordered(sht->shead, sht->stail, key, value) == 0)
	{
		return (0);
	}

	return (sht_set_helper(tmp_node, key, value));
}

/**
 * put_node_index - simply places a new node in an empty linked list
 *
 * @head: the head of the linked list
 * @key: the key string
 * @value: the value string
 *
 */
int put_node_index(shash_node_t **head, const char *key, const char *value)
{
	shash_node_t *node = make_sht_node(key, value);

	if (node == NULL)
	{
		return (0);
	}

	*head = node;

	return (1);
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

	node = make_sht_node(key, value);
	if (node == NULL)
	{
		return (0);
	}

	tmp_node->next = node;
	return (1);
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
