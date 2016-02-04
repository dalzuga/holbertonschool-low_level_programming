#include "my_functions.h"

void positive_or_not(int n)
{
  if (n>0)
    print_char('P');
  else if (n==0)
    print_char('Z');
  else
    print_char('N');
}
