#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * hash_table_get - gets a value from the key in a hash table
 * @ht: the hash table
 * @key: the key string
 *
 * Return: The value string, NULL if not found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *tmp_node;

	/* initializations */
	tmp_node = (NULL);
	index = 0;

	/* retrieve location */
	index = key_index((const unsigned char *) key, ht->size);

	/* retrieve node at location */
	tmp_node = ht->array[index];

	while (tmp_node != NULL)
	{
		if (tmp_node->key == NULL)
		{
			break;
		}

		if (_strcmp(key, tmp_node->key) == 0)
		{
			return (tmp_node->value);
		}
	}

	/* key not found */
	return (NULL);
}

/**
 * _strcmp - compare two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: < 0 if s1 < s2, > 0 if s2 > s1, 0 if strings match
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;
	for ( ; s1[i] != '\0'; i++)
	{
		if (s1[j] != s2[j]) /* if chars are different, break */
		{
			break;
		}
		j++;
	}
	return(s1[j] - s2[j]); /* return difference in chars */
}
