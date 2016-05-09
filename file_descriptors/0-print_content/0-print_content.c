#include <stdio.h>

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  if (argv[0] != 0)		/* get around compiler flag */
    printf("test");
  
  return 0;
}
