#include "holberton.h"

/**
 * _sqrt_recursion - recursive square root function
 *
 * @n: number to calculate the square root of
 *
 * Return: Natural square root of a number
 */
int _sqrt_recursion(int n)
{
	int i;
	i = 0;

	if (i * i == n)
	{
		return (i);
	}

	return (sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - recursive square root function
 *
 * @n: number to calculate the square root of
 * @i: increment counter
 *
 * Return: Natural square root of n
 */
int sqrt_helper(int n, int i)
{
	/* case sqrt found */
	if (i * i == n)
	{
		return (i);
	}

	/* case sqrt not yet found */
	if (i * i < n)
	{
		return (sqrt_helper(n, i + 1));
	}

	/* natural sqrt does not exist */
	return (-1);
}
