#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"
#include "ht_functions.h"

/**
 * hash_table_create - creates a hash table.
 * @size: size of table.
 *
 * Return: pointer to hash table created, NULL on error.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht_ptr;
	unsigned long int i;

	/* check for valid size */
	if (size < 1)
	{
		return (NULL);
	}

	ht_ptr = malloc(sizeof(hash_table_t));
	if (ht_ptr == NULL)
	{
		return (NULL);
	}
	ht_ptr->size = 0;
	ht_ptr->array = NULL;

	ht_ptr->array = malloc(sizeof(hash_node_t *) * size);
	if (ht_ptr->array == NULL)
	{
		free(ht_ptr);
		return (NULL);
	}
	ht_ptr->size = size;

	/* zero out the array */
	for (i = 0; i < size; i++)
	{
		*(ht_ptr->array) = NULL;
		(ht_ptr->array)++;
	}

	/* pointer arithmetic to return ~ht_ptr->array~ to the beginning */
	ht_ptr->array = (ht_ptr->array) - i;

	return (ht_ptr);
}
