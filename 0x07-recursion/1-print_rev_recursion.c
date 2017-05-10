#include "holberton.h"

/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: Pointer to a string.
 *
 * Return: No return.
 */
void _print_rev_recursion(char *s)
{
	/* if not NULL char */
	if (*s == '\0')
	{
		return;
	}

	_print_rev_recursion(s + 1);

	_putchar(*s);
}
