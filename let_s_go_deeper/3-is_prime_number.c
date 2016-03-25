int helper(int n, int a)
{
  if (n % a == 0)		/* if success */
    return 0;			/* return value of a */
  if (a == 1)			/* if a is 1, then non-natural sqrt */
    return 1;			/* return -1 */
  return helper(n, a - 1);	/* do recursive call */
}

int is_prime_number(int n)
{
  if (n < 2)
    return 0;			/* if 1, return 1 */
  
  return helper(n, n - 1); 	/* try a value less than n */
}
