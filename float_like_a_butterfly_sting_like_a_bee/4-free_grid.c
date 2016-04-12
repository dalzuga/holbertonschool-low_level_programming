#include <stdlib.h>

void free_grid(int **grid, int a)
{
  int i;

  for (i = 0; i < a; i++)
    free(grid[i]);
  free(grid);
}
