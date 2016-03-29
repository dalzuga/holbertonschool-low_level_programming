#include <stdio.h>

int main(int argc, char **argv)
{
  argv[0] = "";			/* compiler flag complains */
  printf("%d\n", argc - 1);	/* print arguments minus the filename */
  return 0;
}
