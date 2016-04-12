#include <stdlib.h>

int **alloc_grid(int a, int b)
{
  int **outgrid;		/* grid to return */
  int i, j;

  outgrid = malloc(sizeof(*outgrid) * a); /* set up the row indices (first column) */
  if (outgrid == NULL)			 /* check for memory allocation failure */
    return NULL;

  for (i = 0; i < a; i++)
  {
    *outgrid = malloc(sizeof(**outgrid) * b); /* allocate memory for each row */

    if (*outgrid == NULL)	/* check for memory allocation failure */
      return NULL;
    
    for (j = 0; j < b; j++)
    {
      **outgrid = 0; 		/* initialize value to 0 */
      *outgrid = *outgrid + 1;		/* traverse the row horizontally */
    }

    *outgrid -= b; 		/* reset row pointer to beginning of row */

    outgrid++;			/* advance row pointer down one row */
  }

  return outgrid - a;		/* reset row pointer to (0,0) */
}
