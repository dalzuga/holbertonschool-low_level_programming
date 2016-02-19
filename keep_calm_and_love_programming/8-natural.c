#include <stdio.h>
#define NUMBER 1024 		/* define constant NUMBER */

int main()
{
  int i, sum;
  sum=0;

  for (i=0;i<NUMBER;i++) /* go through all numbers */
    {
      if (i % 3 == 0) /* if divisible by 3 */
	{
	  sum+=i; /* add to sum */
	}
      else if (i % 5 == 0) 	/* if divisible by 5 */
	{
	  sum+=i;		/* add to sum */
	}
    }

  printf("%d\n", sum);
  return 0;
}
