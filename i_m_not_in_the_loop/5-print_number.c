#include "my_functions.h"

void print_number(int n)
{
  int i=1;
  int j=1;
  int x=10;

  char a='0',b;
  
  while (x<n)
    {
      x=x*10;
      i++;
    }

  if (i<10)
    {
    b = (char) (i+48);
    j = 0;
    print_char(b);
    }
  else
    {
      a=(char) 49;
      b=(char) (i+38);
      print_char(a);
      print_char(b);
    }

  print_char('\n');

  for (i=1;i<((int)(b-39));i++)
    {
      print_char(b);
    }
}
