#include <stdlib.h>
#include <stdio.h>
int count_digits(int);

char *int_to_string(int n)
{
  char *str;  char digit, flag; int length, i;
  length = count_digits(n);	/* set the int length to the number of digits*/
  if (n > 0) {			/* from now on, we work in negative realm */
    n *= -1;
    flag = 'p'; 		/* save flag to positive */
  } else
    length++;			/* increase length to accomodate '-' sign */
    flag = 'n';			/* save flag to negative */
  }
  str = malloc(sizeof(char) * (length + 1)); /* allocate memory for string + null char */
  if (str == NULL)	   /* check if memory allocated succesfully */
    return NULL;
  for (i = length - 1; i >= 0; i--)	/* traverse through the string */
  {
    digit = -1 * (n % 10); /* get last digit, and make digit positive */
    str[i] = digit + 48; 	/* convert int into char representation */
    n = (n + digit) / 10; 	/* strip last digit */
  }
  if (flag == 'n')		/* if the input number was negative */
    str[0] = '-';		/* put negative sign in front of string */
  str[length+1] = '\0'; 		/* append null char at the end */
  return str;
}

int count_digits(int n)
{
  int i, x;

  i = 1; 			/* initialize i */
  x = n;			/* copy n onto x */

  if (n > 0)
    x *= -1;

  while (x < -9)	  /* while the number has more than 1 digit */
  {
    x = x / 10;			/* remove a digit */
    i++;			/* count */
  }

  return i;			/* return total digits counted */
}
