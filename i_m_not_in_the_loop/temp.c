#include <stdio.h>

int main(void)
{
  int x;

  while (1)
    {
      scanf("%d", &x);
      printf("%d %d\n", x, (int) sizeof(int));
    }
  
  return 0;
}
