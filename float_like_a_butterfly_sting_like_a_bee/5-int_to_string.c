#include <stdlib.h>
int count_digits(int);

char *int_to_string(int n)
{
  char *str;
  char digit;
  int length, i;

  length = count_digits(n);
  str = malloc(sizeof(char) * (length + 1)); /* allocate memory for string + null char */

  if (str == NULL)	   /* check if memory allocated succesfully */
    return NULL;

  for (i = 0; i < length; i++)	/* traverse through the string */
  {
    digit = n - n / 10; 	/* get leading digit */

    str[i] = digit + 48; 	/* convert int into char representation */
  }
  
  str[i+1] = '\0'; 		/* append null char at the end */

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
