#include <stdio.h>

void print_to_98(int n)
{
  int i; 			/* declare i */
  for (i=n; i<98; i++)		/* print all the numbers approaching from the left */
    printf("%d, ", i);
  
  for (i=n; i>98; i--)		/* print all the numbers approaching from the right */
    printf("%d, ", i);

  printf("98\n");		/* print number 98, which is the last */
}
