#include <stdio.h>

int main(void)
{
  int x;

  while (1)
    {
      scanf("%d", &x);
      printf("%d %d\n", x, count_digits(x));
    }
  
  return 0;
}
