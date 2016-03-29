#include <stdio.h>

int main(int argc, char **argv)
{
  int i, j;
  char flag = 1;
  char csflag = 0;		/* flag2 handles char vs string options */

  for (i = 1; i < argc; i++) 	/* loop argc times minus the one file name */
  {
    j = 0;

    if (argv[i][0] == '-')
    {      
      j++; 			/* move j forward */
      csflag = 1;		/* case: char */

      if (argv[i][1] == '-')
      {
	j++; 			/* move j forward */
	csflag = 2;		/* case: string */

	if (argv[i][2] == '\0') /* handle ignore '--' case */
	  flag = 0;
      }

      while (argv[i][j] != '\0' && flag)	/* print chars */
      {
	printf("%c", argv[i][j]);
	j++;

	if (csflag == 1)
	  printf(", ");
      }
      
      if (flag)
	printf("\n"); 		/* add new line if before '--' case */
    }
  }

  return 0;
}
