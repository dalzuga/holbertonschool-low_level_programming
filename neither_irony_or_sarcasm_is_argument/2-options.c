#include <stdio.h>

int main(int argc, char **argv)
{
  int i, j;
  char flag = 1;

  for (i = 1; i < argc; i++) 	/* loop argc times minus the one file name */
  {
    j = 0;

    if (argv[i][0] == '-')
    {      
      j++; 			/* move j forward */

      if (argv[i][1] == '-')
      {
	j++; 			/* move j forward */

	if (argv[i][2] == '\0') /* handle ignore '--' case */
	  flag = 0;
      }

      while (argv[i][j] != '\0' && flag)	/* print chars */
      {
	printf("%c", argv[i][j]);
	j++;
      }
      
      if (flag)
	printf("\n"); 		/* add new line if before '--' case */
    }
  }

  return 0;
}
