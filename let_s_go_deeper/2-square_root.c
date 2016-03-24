int square_root(int n)
{
  int i;

  for (i = 0; i <= n; i++)	/* try all numbers <= n */
  {
    if (i * i == n)		/* if the square root */
      return i;			/* return the value */
  }

  return -1;			/* all values tried, no natural sqrt's */
}
