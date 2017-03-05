#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_table_set(hash_table_t *ht, const char *key, const char* value)
{
	unsigned long int index;
	hash_node_t *node, *tmp_node;
	int i, j;
	char c, flag;
	
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
	flag = 0;

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
		return(EXIT_FAILURE);
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
		return(EXIT_FAILURE);
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

	/* the node has been made */

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) node->key, ht->size);

	/* simple case. no bananas. insert node */
	if ((*(ht->array + index)) == NULL)
	{
		printf("empty! (key: %s, index: %lu)\n", node->key, index);
		*(ht->array + index) = node;
		return (EXIT_SUCCESS);
	}

	/* at this point, there is a collision or an update, or "banana". */

	printf("non-empty! (key: %s, index: %lu)\n", node->key, index);

	/* case 1: our banana is an update */
	tmp_node = ht->array[index];
	printf("Here is our tmp_node->key:%s\n", tmp_node->key);
	printf("Here is our tmp_node->value:%s\n", tmp_node->value);
	printf("Here is our key:%s\n", key);

	/* update with new value */
	if (strcmp(key, (tmp_node->key)) == 0)
	{
		printf("banana update! (key: %s)\n", node->key);
		tmp_node->value = strdup(value);
		return (EXIT_SUCCESS);
	}

	while (tmp_node->next != NULL)
	{
		/* update with new value */
		if (strcmp(key, tmp_node->key) == 0)
		{
			tmp_node->value = strdup(value);
			flag = 1;
			break;
		}

		/* advance tmp_node */
		tmp_node = tmp_node->next;
	}

	/* append node to linked list */
	if (!flag)
	{
		((hash_node_t *) (ht->array + index))->next = node;
	}

	return (EXIT_SUCCESS);
}
