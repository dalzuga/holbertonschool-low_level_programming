#include "my_functions.h"

void digits_number(int n)
{
  int i=1;
  int x=10;
  
  while (x<n)
    {
      x=x*10;
      i++;
    }

  if (i<10)
    print_char((char) (i+48));
  else
    {
      print_char(49);
      print_char((char) (i+38));
    }
}
