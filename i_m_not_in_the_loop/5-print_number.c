#include "my_functions.h" /* let's try something crazy */

void print_number(int n)
{
  if (n<0)
    print_char('-');
  if (n<0)
    n=-n;
  int i,count=count_digits(n),x=1;
  for (i=1;i<count;i++)
    x=x*10;
  print_char((n/x)+48);
  
  if (x>1)
    print_number(n - ((int) n/x) * x);
}
