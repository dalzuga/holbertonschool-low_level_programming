#include <stdio.h>
#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - frees all memory allocated to a hash table.
 *
 * @ht: address of the hash table to free
 *
 * Return: Nothing.
 */
void hash_table_delete(hash_table_t *ht)
{
	/* declarations */
	hash_node_t *ptr;
	unsigned long int i;

	/* inits */
	ptr = NULL;
	i = 0;

	if (invalid_ht(ht))
	{
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		ptr = ht->array[i];
		if (ptr != NULL)
		{
			if (DEBUG)
			{
				printf("ll found at index %lu.\n", i);
			}
			delete_ht_ll(ht->array[i]);
			/* ht->array[i] = NULL; */
		}
	}

	free(ht->array);
	free(ht);
}

/**
 * delete_ht_ll - frees all memory allocated to a hash table linked list.
 *
 * @head: pointer to first node in the linked list
 *
 * Return: Nothing.
 */
void delete_ht_ll(hash_node_t *head)
{
	/* declarations */
	hash_node_t *trl_ptr;

	/* inits */
	trl_ptr = head;

	while (trl_ptr != NULL)
	{
		/* advance head */
		head = head->next;

		/* delete node pointed by previous head */
		delete_node(trl_ptr);

		/* point trl_ptr to new head */
		trl_ptr = head;
	}
}

/**
 * delete_node - frees a node inside a linked list
 *
 * @node_ptr: pointer to node to be freed.
 *
 * Return: Nothing.
 */
void delete_node(hash_node_t *node_ptr)
{
	/* delete node */
	free(node_ptr->value);
	free(node_ptr->key);
	free(node_ptr);
}
