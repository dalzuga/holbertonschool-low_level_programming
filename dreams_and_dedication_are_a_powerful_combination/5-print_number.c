#include "my_functions.h"

void print_number(int n)
{
  int aux1, i, count, x;	/* declaring variables */
  if (n<0) print_char('-');	/* if negative, insert negative sign */
  if (n==-2147483648) { print_char(50); n=-147483648; } /* handles special case of extreme negative */
  if (n<0) n=-n;	     /* if negative, go into positive world */
  count=count_digits(n); x=1; 	/* initialize */
  for (i=1;i<count;i++)		/* make x big */
    x=x*10;
  print_char((n/x)+48);
  
  if (x>1)
    {
      aux1= n - ((int) n/x) * x; /* store magic formula */
      for (i=1;i<count_digits(n)-count_digits(aux1);i++)
	print_char(48);		/* if there's any zero's, don't miss them */
      print_number(n - ((int) n/x) * x); /* recursive protocol */
    }
}
