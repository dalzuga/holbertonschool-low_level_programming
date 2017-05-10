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
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *node, *tmp_node;
	int i, j;
	char c;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		return (EXIT_FAILURE);
	}

	/* Initializations */
	node->key = NULL;
	node->value = NULL;
	node->next = NULL;
	tmp_node = NULL;

	/* get the length */
	c = *key;
	for (i = 1; c != 0; i++)
	{
		key++;
		c = *key;
	}
	/* i is now the string length, including NULL char (tested) */

	/* bring back ~key~ using pointer arithmetic */
	key = key - i + 1;

	/* allocate ~i~ characters (string + NULL char) */
	node->key = malloc(sizeof(char) * i);
	if (node == NULL)
	{
		return (EXIT_FAILURE);
	}

	/* copy the contents of ~key~ */
	for (j = 0; j < i; j++)
	{
		*(node->key) = *key;
		(node->key)++;
		key++;
	}

	/* bring back node->key using pointer arithmetic */
	node->key = node->key - j;
	/* bring back =key= using pointer arithmetic */
	key = key - j;

	/* get the length of ~value~ */
	c = *value;
	for (i = 1; c != 0; i++)
	{
		value++;
		c = *value;
	}
	/* i is now the length, including NULL char */

	/* roll back ~value~ using pointer arithmetic */
	value = value - i + 1;

	/* allocate memory for ~node->value~ */
	node->value = malloc(sizeof(char) * i);
	if (node == NULL)
	{
		return (EXIT_FAILURE);
	}

	/* copy the contents of ~value~ */
	for (j = 0; j < i; j++)
	{
		*(node->value) = *value;
		(node->value)++;
		value++;
	}

	/* roll back ~node->value~ using pointer arithmetic */
	node->value = node->value - j;
	value = value - j;

	/* the node has been made */

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) node->key, ht->size);

	tmp_node = *(ht->array + index);

	/* traverse the list until tmp_node is the last */
	while (tmp_node != NULL)
	{
		/* simple update */
		if (strcmp(key, tmp_node->key) == 0)
		{
			tmp_node->value = strdup(value);
			return (EXIT_SUCCESS);
		}

		if (tmp_node->next == NULL)
		{
			break;
		}

		tmp_node = tmp_node->next;
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

	return (EXIT_SUCCESS);
}
