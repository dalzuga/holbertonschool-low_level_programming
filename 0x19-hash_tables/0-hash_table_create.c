#include <stdlib.h>
#include "hash_tables.h"
#include <stdio.h>

hash_table_t *hash_table_create(unsigned long int size) {
	hash_table_t *ht_ptr;
	long unsigned int i;

	/* check for valid size */
	if (size < 1)
	{
		return NULL;
	}

	ht_ptr = malloc(sizeof(hash_table_t));
	if (ht_ptr == NULL)
	{
		return NULL;
	}
	ht_ptr->size = 0;
	ht_ptr->array = NULL;

	ht_ptr->array=malloc(sizeof(hash_node_t *) * size);
	if (ht_ptr->array == NULL)
	{
		return NULL;
	}
	ht_ptr->size = size;

	/* zero out the array */
	for (i = 0; i < size; i++)
	{
		*(ht_ptr->array) = (hash_node_t *) NULL;
		(ht_ptr->array)++;
	}

	/* pointer arithmetic to return ~ht_ptr->array~ to the beginning */
	ht_ptr->array = (ht_ptr->array) - i;

	return ht_ptr;
}
