#ifndef SHT_FUNCTIONS
#define SHT_FUNCTIONS

#include <stdlib.h>
#include <stdio.h>

/**
 * invalid_sht - checks if the sorted hash table is valid.
 *
 * @sht: address of sorted hash table to check.
 *
 * Return: 0 if valid, 1 otherwise.
 */
int invalid_sht(const shash_table_t *sht)
{
	if (sht == NULL)
	{
		return (1);
	}

	if (sht->size < 1)
	{
		return (1);
	}

	if (sht->array == NULL)
	{
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
	return (s1[j] - s2[j]); /* return difference in chars */
}

#endif
