#include <stdlib.h>
#include "hash_tables.h"

hash_table_t *hash_table_create(unsigned long int size) {
	hash_table_t *ht_ptr;

	if (size < 1)
	{
		return NULL;
	}

	ht_ptr = malloc(sizeof(hash_table_t));
	ht_ptr->size = 0;
	ht_ptr->array = NULL;

	ht_ptr->array=malloc(sizeof(char *) * size);
	if (ht_ptr->array == NULL)
	{
		return NULL;
	}
	ht_ptr->size = size;

	return ht_ptr;
}
