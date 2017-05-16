#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table. If the hash table is not valid, it
 * will not print anything.
 *
 * @ht: the hash table address.
 *
 * Return: Nothing.
 */

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp_ptr;
	char flag = 0;

	/* Inits */
	i = 0;
	tmp_ptr = (hash_node_t *) NULL;

	/* all cases where ht is NULL */
	if (invalid_ht(ht))
	{
		return;
	}

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		tmp_ptr = *(ht->array + i);

		if (tmp_ptr != NULL)
		{
			if (tmp_ptr->key == NULL)
			{
				return;
			}
			if (flag == 1)
			{
				printf(", ");
			}
			print_linked_list(tmp_ptr);
			flag = 1;
		}
	}

	printf("}\n");
}

/**
 * print_linked_list - prints a linked list starting at first_node_ptr until
 * there are no more values.
 *
 * @first_node_ptr: pointer to the first node of linked list.
 *
 * Return: Nothing.
 */
void print_linked_list(hash_node_t *first_node_ptr)
{
	hash_node_t *tmp_ptr;

	/* Inits */
	tmp_ptr = first_node_ptr;

	while (tmp_ptr != NULL)
	{
		printf("'%s': '%s'", tmp_ptr->key, tmp_ptr->value);
		tmp_ptr = tmp_ptr->next;
	}
}
