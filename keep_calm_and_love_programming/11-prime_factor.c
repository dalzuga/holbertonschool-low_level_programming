#include <stdio.h>
#define NUMBER 612852475143

int main()
{
  long int n, i;		/* declare n and i */
  i=2;				/* start factoring at 2 */
  n=NUMBER;

  while (n%i != 0) 		/* find smallest factor */
    i++;

  printf("%ld\n", n/i);		/* print greatest factor */

  return 0;
}
