#include "my_functions.h"

void print_number(int n)
{
  int i=1;
  int x=10;
  char a=48,b=48; /* char a not applicable for this task. 48 = '1' */
  
  print_char(a);
  print_char(b);

  while (x<n && i<10)
    {
      x=x*10;
      i++;
    }

  if (x<n) /* handles special case where n is 10 digits long */
    {
      x=2147483647;
      i++;
    }

  if (i<10)
      b=(char)(i+48);
  else /* not applicable for this task, but allows for integers that are longer than 32-bit */
    {
      a=49; /* aka '1' */
      print_char(a); /* prints '1' */
      print_char((char) (i+38)); /* prints second digit */
    }

  print_char('\n');

  for (;i>1;i--)
    {
      print_char((char) b);
    }
}
