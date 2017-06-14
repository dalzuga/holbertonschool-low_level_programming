int helper(int n, int a)
{
  if (a == 1)			/* if a is 1, then prime */
    return 1;			/* return 1 */
  if (n % a == 0)		/* if not prime */
    return 0;			/* return 0 */
  return helper(n, a - 1);	/* do recursive call */
}

int is_prime_number(int n)
{
  if (n < 2)
    return 0;			/* if less than 2, not prime */
  
  return helper(n, n - 1); 	/* try a value less than n */
}
