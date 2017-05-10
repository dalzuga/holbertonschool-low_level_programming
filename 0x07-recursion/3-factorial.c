#include "holberton.h"

/**
 * factorial - recursive factorial calculation
 *
 * @n: number to apply the factorial to
 *
 * Return: the factorial of n.
 */
int factorial(int n)
{
	/* factorial of 0 is 1 */
	if (n == 0)
	{
		return (1);
	}

	if (n < 0)
	{
		return (-1);
	}

	return (n * factorial(n - 1));
}
