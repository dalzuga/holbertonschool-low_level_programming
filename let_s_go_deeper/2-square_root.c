int helper(int n, int a)
{
  if (a * a == n)		/* if success */
    return a;			/* return value of a */
  if (a == 1)			/* if a is 1, then non-natural sqrt */
    return -1;			/* return -1 */
  return helper(n, a - 1);	/* do recursive call */
}

int square_root(int n)
{
  if (n == 1)
    return 1;			/* if 1, return 1 */
  else if (n == 0)
    return 0;			/* if 0, return 0 */
  else if (n < 0)
    return -1;			/* if negative */
  
  return helper(n, n - 1); 	/* try a value less than n */
}
