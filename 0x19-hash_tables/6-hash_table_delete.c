#include <stdio.h>
#include "hash_tables.h"

#ifndef DEBUG
#define DEBUG 1
#endif

/**
 *
 *
 */
void hash_table_delete(hash_table_t *ht)
{
	/* declarations */
	/* hash_node_t *ptr; */

	/* inits */
	/* ptr = NULL; */

	if (invalid_ht(ht))
	{
		if (DEBUG)
		{
			printf("HASH TABLE INVALID\n");
		}
		printf("ht address: %p\n", (void *) ht);
		return;
	}

	if (DEBUG)
	{
		printf("VALID HASHTABLE\n");
	}
}

/**
 *
 *
 */
int invalid_ht(hash_table_t *ht)
{
	if (ht == NULL)
	{
		printf("---1---\n");
		return (1);
	}

	if (ht->size == 0)
	{
		printf("---2---\n");
		return (1);
	}

	if (ht->array == NULL)
	{
		printf("---3---\n");
		return (1);
	}

	if (*(ht->array) == NULL)
	{
		printf("---4---\n");
		return (1);
	}


	return (0);
}
