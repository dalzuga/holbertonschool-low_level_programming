#include <stdio.h>

int main(int argc, char **argv)
{
  int i, j;

  for (i = 1; i < argc; i++) 	/* loop argc times minus the one file name */
  {
    j = 0;

    if (argv[i][0] == '-')
    {      
      j++; 			/* move j forward */

      if (argv[i][1] == '-')
      {
	j++; 			/* move j forward */
      }


      while (argv[i][j] != '\0')	/* print chars */
      {
	printf("%c", argv[i][j]);
	j++;
      }
      
      printf("\n");
    }
  }

  return 0;
}
