int power(int x, int y)
{
  if (y < 0)			/* if y lower than 0 */
    return -1;			/* return -1 */
  else if (y == 0)
    return 1;
  else if (y == 1)
    return x;			/* if no more, return x */
  return x * power(x, y - 1); /* recursively call function */
}
