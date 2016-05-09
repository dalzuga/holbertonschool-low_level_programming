#include <stdio.h>

int main(int argc, char __attribute__((unused)) *argv[]) /* get around compiler flag */
{
  if (argc < 2)
    return 1;
  
  printf("test\n");
  return 0;
}
