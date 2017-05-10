#include "holberton.h"

/**
 * _pow_recursion - recursive factorial calculation
 *
 * @x: number to apply the exponent to
 * @y: exponent
 *
 * Return: the result of x^y
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}

	/* case y = 0 */
	if (y == 0)
	{
		return (1);
	}

	return (x * _pow_recursion(x, y - 1));
}
