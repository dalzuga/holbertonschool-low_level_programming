#include <stdio.h>

int main()
{
  unsigned long int a, b, c;
  int i;
  a=1, b=2, i=2;		/* first two fibonacci numbers, index initialized at 2 */
  printf("%lu, %lu, ", a, b); 	/* print the first two */

  while (1) 			/* keep running */
    {
      i++; /* keep going until 92nd */
      c=a+b;

      if (i==92) 		/* 92nd fibonacci number (starting with 1, 2) */
	{
	  printf("%lu\n", c); 	/* no space, no comma */
	  return 0;		/* break */
	}

      printf("%lu, ", c); a=b; b=c;
    }
}
