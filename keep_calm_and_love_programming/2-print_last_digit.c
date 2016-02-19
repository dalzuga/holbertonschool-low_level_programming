#include "my_functions.h"

void print_last_digit(int n)
{
  n=n%10; 			/* get n mod 10 -> last digit */

  if (n<0) n=-n;  		/* if negative, make positive */

  print_char((char)(n+48));    /* print char corresponding to digit */
}
