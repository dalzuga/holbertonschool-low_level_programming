#include "my_functions.h"

void print_number(int n)
{
  int x=1;

  while (x<n && i<10)
    {
      x=x*10;
      i++;
    }

  if (x<n) /* handles special case where n is 10 digits long */
    {
      x=2147483647;
      a=49;
      i++;
    }

  if (i<10)
    {
      b=b+i;
      print_char(b);
    }

  else /* not applicable for this task, but allows for integers that are longer than 32-bit */
    {
      a=49; /* aka '1' - redundant line */
      print_char(a); /* prints '1' */
      print_char((char) (i+38)); /* prints second digit */
    }

  print_char('\n');
  print_char('d');

  if (x==2147483647)
    {
      print_char(49);
      x=1000000000;
    }

  for (;i>1;i--)
    {
      /*      print_char(     (n-   (n % x+48)) /    ); */
      /*      x=x/10; */
      /*      print_char((char) b);*/
    }
}
