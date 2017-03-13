#include "holberton.h"

/**
 * is_palindrome - checks if a string is a palindrome.
 *
 * @s: string to check
 *
 * Return: 1 if string is a palindrome, 0 if not.
 */
int is_palindrome(char *s)
{
	int s_len;

	/* case is empty string */
	if (*s == 0)
	{
		return (0);
	}

	/* call helper function */
	s_len = _strlen_recursion(s);
	return is_palindrome_helper(s, s_len, 0);
}

/**
 * is_palindrome_helper - recursive palidrome checker.
 *
 * @s: string to check
 * @i: counter used as char index
 *
 * Return: 1 if string is a palindrome, 0 if not.
 */
int is_palindrome_helper(char *s, int s_len, int i)
{
	if ( (i < (s_len/2)) && (*s == *(s + s_len - i - 1)) )
	{
		return is_palindrome_helper(s, i + 1);
	}

	return (1);
}

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
