#ifndef HT_FUNCTIONS
#define HT_FUNCTIONS

#include <stdlib.h>
#include <stdio.h>

/**
 * invalid_ht - checks if the hash table is considered invalid
 *
 * @ht: address of hash table to check.
 *
 * Return: 0 if valid, 1 otherwise.
 */
int invalid_ht(hash_table_t *ht)
{
	if (ht == NULL)
	{
		_printf("hash_table_delete.c: ");
		_printf("---1---\n");
		return (1);
	}

	if (ht->size < 1)
	{
		_printf("hash_table_delete.c: ");
		_printf("---2---\n");
		return (1);
	}

	if (ht->array == NULL)
	{
		_printf("hash_table_delete.c: ");
		_printf("---3---\n");
		return (1);
	}

	return (0);
}

/**
 * _strlen - gets the length of a string.
 *
 * @s: input string.
 *
 * Return: length of input string, not including null char.
 */
int _strlen(const char *s)
{
	/* declarations */
	int i;

	/* inits */
	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strdup - duplicates a string
 *
 * @s1: string to duplicate.
 *
 * Return: duplicated string.
 */
char *_strdup(const char *s1)
{
	/* declarations */
	int i, len;
	char *s2;

	len = _strlen(s1);

	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < (len + 1); i++)
	{
		s2[i] = s1[i];
	}

	return (s2);
}

/**
 *
 *
 */
void _printf(const char *s)
{
	if (DEBUG)
	{
		printf("%s", s);
	}
}

#endif
