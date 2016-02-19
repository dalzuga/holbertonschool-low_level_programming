#include <stdio.h>

int main(void)
{
  int i;

  for (i=1;i<=100;i++)
    {
      if (i % 3 == 0) 		/* if divisile by 3 */
	printf("Fizz");
      if (i % 5 == 0)		/* if divisible by 5 */
	printf("Buzz");
      if (!(i%3==0 || i%5==0)) 	/* if neither div by 3 or by 5 */
	printf("%d", i);

      if (!(i==100))  		/* handles last number space */
	printf(" ");
    }

  return 0;
}
