#include <stdio.h>

void triangles_in_the_term(int h, int n)
{
  int i, j, k;

  for (k = 0; k < n; k++) 	/* draw n triangles */
    {
      for (j = 0; j < h; j++) 	/* j is the line number starting at line 0 */
	{
	  for (i = h-1-j; i >= 1; i--) 	/* start with the spaces */
	    {
	      printf(" ");
	    }
  
	  for (i = 1; i <= 2*j+1; i++)  	/* draw asterisks */
	    {
	      printf("*");
	    }
	  printf("\n");
	}
    }
}
