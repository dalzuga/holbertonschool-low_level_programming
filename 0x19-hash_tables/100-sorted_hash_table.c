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
	sht_ptr->shead = sht_ptr->stail = NULL;

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
	shash_node_t **ll_head = NULL;

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

		return (1);
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
 * sht_insert_dll - insert a node at the end of the double linked list of a
 * sorted hash table.
 *
 * @sht: the sorted hash table
 * @node: pointer to the node to insert
 *
 * Return: 1 on success; this function always succeeds.
 */
int sht_insert_dll(shash_table_t *sht, shash_node_t *node)
{
	shash_node_t *tmp_node = sht->stail;

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
	shash_node_t *tmp_node = NULL, *node = NULL;
	unsigned long int index = 0;

	/* queries hash function for index and stores it in ~index~ */
	index = key_index((const unsigned char *) key, sht->size);

	tmp_node = *(sht->array + index);

	/* case 2: update or append */
	while (tmp_node->next != NULL)
	{
		if (_strcmp(tmp_node->key, key) == 0)
		{
			/* case 2a: update */
			if (update_sht_node(tmp_node, value) == 0)
			{
				return (0);
			}
			return (sht_push_dllnode(sht, tmp_node));
		}
	}

	/* case 2b: append */
	node = make_sht_node(key, value);
	tmp_node->next = node;
	return (sht_insert_dll(sht, node));
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

/**
 * sht_push_node - move a node to the end of the double linked list of a
 * sorted hash table.
 *
 * @sht: the sorted hash table
 * @node: pointer to the node to push
 *
 * Return: 1 on success; this function always succeeds.
 */
int sht_push_dllnode(shash_table_t *sht, shash_node_t *node)
{
	/* case 1: we're already at the last node */
	if (node->snext == NULL)
	{
		return (1);
	}


	/* case 2a: there is no node behind, we're not at the last node */
	if (node->sprev == NULL)
	{
		sht->shead = node->snext;
		node->snext = NULL;
		node->sprev = sht->stail;
		sht->stail = node;
	}

	/* case 2b: there is a node behind, we're not at the last node */
	(node->sprev)->next = node->snext;
	node->snext = NULL;
	sht->stail = node;

	return (1);
}

/**
 * shash_table_print - prints a sorted hash table. If the hash table is not
 * valid, it will not print anything.
 *
 * @ht: the sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	/* declarations */
	shash_node_t *tmp_node;

	if (invalid_sht(ht))
	{
		return;
	}

	tmp_node = ht->shead;

	printf("{");
	while (tmp_node != NULL)
	{
		printf("\'%s\' : \'%s\'", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->snext;
		if (tmp_node != NULL)
		{
			printf(", ");
		}
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order. If the
 * hash table is not valid, it will not print anything.
 *
 * @ht: the sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	/* declarations */
	shash_node_t *tmp_node;

	if (invalid_sht(ht))
	{
		return;
	}

	tmp_node = ht->stail;

	printf("{");
	while (tmp_node != NULL)
	{
		printf("\'%s\' : \'%s\'", tmp_node->key, tmp_node->value);
		tmp_node = tmp_node->sprev;
		if (tmp_node != NULL)
		{
			printf(", ");
		}
	}

	printf("}\n");
}

/**
 * shash_table_delete - frees all memory allocated to a sorted hash table.
 *
 * @ht: the sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *ptr1 = NULL, *ptr2 = NULL;

	ptr1 = (ht->shead);

	while (ptr1 != NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->snext;
		/* free previous node */
		free(ptr2->key);
		free(ptr2->value);
		free(ptr2);
	}

}
