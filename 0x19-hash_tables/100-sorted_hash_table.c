#include "hash_tables.h"
#include <stdlib.h>

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht_ptr;
	unsigned long int i;

	/* check for valid size */
	if (size < 1)
	{
		return (NULL);
	}

	sht_ptr = malloc(sizeof(shash_table_t));
	if (sht_ptr == NULL)
	{
		return (NULL);
	}
	sht_ptr->size = 0;
	sht_ptr->array = NULL;
	sht_ptr->shead = NULL;
	sht_ptr->stail = NULL;

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
