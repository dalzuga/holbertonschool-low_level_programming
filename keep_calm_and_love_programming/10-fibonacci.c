#include <stdio.h>

int main()
{
  long int a, b, c, sum;
  
  a=1, b=2;		/* first two fibonacci numbers */
  sum=2;		/* sum of even ones so far */

  while (a+b < 4000000)	/* while the next Fibonacci is less than 4x10^6 */
    {
      c=a+b; 			/* go to next Fibonacci number */
      if (c%2==0)		/* if even, add to sum */
	sum+=c;
      a=b; b=c;
    }

  printf("%ld\n", sum); 	/* print sum */

  return 0;
}
