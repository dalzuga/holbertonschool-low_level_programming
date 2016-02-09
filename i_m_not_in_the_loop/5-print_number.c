#include "my_functions.h"

void print_number(int n)
{
  int aux1;
  if (n<0)
    print_char('-');
  if (n<0)
    n=-n;
  int i,count=count_digits(n),x=1;
  for (i=1;i<count;i++)
    x=x*10;
  print_char((n/x)+48);
  
  if (x>1)
    {
      aux1= n - ((int) n/x) * x;
      for (i=1;i<count_digits(n)-count_digits(aux1);i++)
	print_char(48);
      print_number(n - ((int) n/x) * x);
    }
}
