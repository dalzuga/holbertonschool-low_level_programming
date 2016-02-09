#include <stdio.h>

int main(void)
{
  int x, i;

  for (i=0; i<10; i++)
    {
      scanf("%d", &x);
      print_number(x);
      print_char('\n');
    }
  
  return 0;
}
