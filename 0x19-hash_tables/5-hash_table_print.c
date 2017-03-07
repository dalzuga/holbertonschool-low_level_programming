#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * params:
 * @ht : a hash table pointer
 * This function prints a hash_table and returns nothing.
 * If the hash table is not valid, it will not print anything.
 * return: void
 */

void print_linked_list(hash_node_t *first_node_ptr);

void hash_table_print(const hash_table_t *ht)
{
	long unsigned int i;
	hash_node_t *tmp_ptr;

	/* Inits */
	i = 0;
	tmp_ptr = (hash_node_t *) NULL;

	/* all cases where ht is NULL */
	if (ht == NULL || ht->array == NULL || ht->size < (long unsigned int) 1)
	{
		printf("Error: empty table.");
		return;
	}

	for (i = 0; i < ht->size; i++)
	{
		tmp_ptr = *(ht->array + i);

		if (tmp_ptr != NULL)
		{
			if (tmp_ptr->key == NULL)
			{
				printf("Error: invalid hash table.");
			}
			printf("[%lu]: ", i);
			print_linked_list(tmp_ptr);
		}
	}

	return;
}

/**
 * prints a linked list starting at first_node_ptr until there are no more values. 
 */
void print_linked_list(hash_node_t *first_node_ptr)
{
	hash_node_t *tmp_ptr;

	/* Inits */
	tmp_ptr = first_node_ptr;

	while (tmp_ptr != NULL)
	{
		printf("{ %s : %s } --> ", tmp_ptr->key, tmp_ptr->value);
		tmp_ptr = tmp_ptr->next;
	}

	printf("NULL\n");
}
