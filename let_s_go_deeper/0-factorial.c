int factorial(int n)
{
  if (n < 0)
    return -1;
  else if (n < 2)			/* if 0 or 1 */
    return 1; 			/* return 1 */
  return n * factorial(n - 1); /* recursively call function */
}
