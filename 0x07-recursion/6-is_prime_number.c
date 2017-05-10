#include "holberton.h"

/**
 * is_prime_number - recursive prime checker.
 *
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not.
 */
int is_prime_number(int n)
{
	int i;
	/* initialize counter to first prime number */

	/* cases 0, 1, and < 0 */
	if (n < 2)
	{
		return (0);
	}

	i = 2;
	/* call the helper function */
	return (is_prime_helper(n, i));
}

/**
 * is_prime_helper - recursive square prime checker
 *
 * @n: number to check (int)
 * @i: increment counter (int)
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_helper(int n, int i)
{
	/* if we've overshot the sqrt of n */
	if (i * i > n)
	{
		/* then it's prime */
		return (1);
	}

	/* if there is a divisor */
	if (n % i == 0)
	{
		/* then it's not prime */
		return (0);
	}

	/* check for more divisors */
	return (is_prime_helper(n, i + 1));

}
