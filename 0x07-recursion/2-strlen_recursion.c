#include "holberton.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: the string
 *
 * Return: integer containing the string length
 */
int _strlen_recursion(char *s)
{
	/* case empty string */
	if (*s == 0)
	{
		return 0;
	}

	/* general case */
	return 1 + _strlen_recursion(s + 1);
}
