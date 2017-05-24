#include "hash_tables.h"

#include <stdlib.h>
#include <stdio.h>

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
	int r;

	printf("---\n");

	if (invalid_ht(ht) || key == NULL)
	{
		return (0);
	}

	if (_strcmp(key, "") == 0)
	{
		return (0);
	}

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, ht->size);

	tmp_node = *(ht->array + index);

	/* case 1: there is no node at this index */
	if (tmp_node == NULL)
	{
		printf("--3--\n");

		node = make_node(key, value);
		if (node == NULL)
		{
			return (0);
		}
		*(ht->array + index) = node;
		return (1);
	}

	printf("-----------------------\n\n");
	printf("hash_table_set():\n");

	printf("--4--\n");
	printf("(ht->array[i]): %p\n", (void *) (ht->array[index]));
	printf("tmp_node: %p\n", (void *) (tmp_node));
	printf("&tmp_node: %p\n", (void *) &(tmp_node));

	r = ht_set_helper(&tmp_node, key, value);

	printf("-----------------------\n\n");
	printf("hash_table_set():\n");

	printf("(ht->array[i]): %p\n", (void *) (ht->array[index]));
	printf("tmp_node: %p\n", (void *) (tmp_node));
	printf("&tmp_node: %p\n", (void *) &(tmp_node));

	return (r);
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
int ht_set_helper(hash_node_t **head_node, const char *key, const char *value)
{
	hash_node_t *node, *tmp_node;

	printf("-----------------------\n\n");
	printf("ht_set_helper():\n");

	tmp_node = *head_node;

	printf("tmp_node: %p\n", (void *) tmp_node);

	while (tmp_node != NULL)
	{
		/* case 2: simple update */
		if (_strcmp(key, tmp_node->key) == 0)
		{
			return (ht_node_update(tmp_node, value));
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

	tmp_node = *head_node;	/* move tmp back to head */

	printf("tmp_node: %p\n", (void *) tmp_node);

	printf("head_node: %p\n", (void *) head_node);
	printf("*head_node: %p\n", (void *) *head_node);
	printf("node: %p\n", (void *) tmp_node);

	head_node = &node;		/* set head to new node */
	printf("*head_node: %p\n", (void *) *head_node);

	(*head_node)->next = tmp_node; /* link new node to the old head */
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
 * ht_node_update - updates the value in a node
 *
 * @tmp_node: node to change
 * @value: string to change ~node->value~ to
 *
 * Return: 1 on success, 0 on failure.
 */
int ht_node_update(hash_node_t *tmp_node, const char *value)
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
