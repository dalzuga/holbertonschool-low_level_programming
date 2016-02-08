#include "my_functions.h"

void print_number(int n)
{
  int i=1;
  int j=0;
  int x=10;

  char a='0',b='0'; /* not applicable for this task */
  
  print_char(b);
  print_char(j+49);


  while (x<n && i<10)
    {
      x=x*10;
      i++;
    }

  if (x<n) /* handles special case where number is 10 digits long */
    {
      x=2147483647;
      i++;
    }

  if (i<10)
    {
      b = (char) (i+48);
      j=0;
    }
  else /* not applicable for this task, but allows for integers that are longer than 32-bit */
    {
      a=49;
      b=i;
      print_char(a);
      print_char((char) (i+38));
      j=1;
    }

  print_char('\n');

  for (;i>1;i--)
    {
      print_char((char) b);
    }
}
