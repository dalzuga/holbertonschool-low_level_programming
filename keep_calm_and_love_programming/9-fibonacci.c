#include <stdio.h>

int main()
{
  long int a, b, c;
  int i;
  a=1, b=2, i=2;		/* first two fibonacci numbers, index initialized at 2 */
  printf("%ld, %ld, ", a, b); 	/* print the first two */

  while (1) 			/* keep running */
    {
      i++; /* keep going until 50th */
      c=a+b;

      if (i==50) 		/* 50th fibonacci number (starting with 1, 2) */
	{
	  printf("%ld", c); 	/* no space, no comma */
	  return 0;		/* break */
	}

      printf("%ld, ", c); a=b; b=c;
    }
}
