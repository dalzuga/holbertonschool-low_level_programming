#include <stdio.h>

int main(int argc, char **argv)
{
  int i;

  for (i = 0; i < argc; i++) 	/* loop argc times */
  {
    printf("%s\n", argv[i]);	/* print */
  }

  return 0;
}
