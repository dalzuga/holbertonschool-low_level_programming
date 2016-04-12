#include <stdlib.h>
#include <stdio.h>
int count_digits(int);

char *int_to_string(int n)
{
  char *str;
  str = malloc(sizeof(str));

  printf("Digits of %d are: %d\n", n, count_digits(n));

  return str;
}

int count_digits(int n)
{
  int i, x;

  i = 1; 			/* initialize i */
  x = n;			/* copy n onto x */

  if (n > 0)
    x *= -1;

  while (x < -9)		  /* while the number has more than 1 digit */
  {
    x = x / 10;			/* remove a digit */
    i++;			/* count */
  }

  return i;			/* return total digits counted */
}
