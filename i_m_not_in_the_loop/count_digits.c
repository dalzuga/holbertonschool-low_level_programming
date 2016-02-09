#include "my_functions.h"

int count_digits(int n)
{
  int i=0, x=1;

  if (n==0)
    return 1;
  else if (n>=1000000000) // modify this to suit other 32-bit environments
    return 10;
  else if (n<0)
    n=-n;
  while (x<=n)
    {
      i++;
      x=x*10;
    }
  return i;
}
