int first_digit(int n)
{
  if (n > 0) 			/* if positive */
    n=-n;			/* make negative */

  while (n < -9)		/* while more than one digit */
    n=n/10;			/* truncate one digit */
  return -n;			/* return positive number */
}
