#include <stdlib.h>
#include <stdio.h>

int **alloc_grid(int, int);
void print_grid(int **, int, int);

int main()
{
  int **grid;
  int i, a, b;

  printf("First example:\n");

  a = 5;
  b = 20;

  grid = alloc_grid(a, b);
  print_grid(grid, a, b);
  
  for (i = 0; i < a; i++)
    free(grid[i]);
  free(grid);

  printf("Second example:\n");

  grid = alloc_grid(5, 5);
  print_grid(grid, 5, 5);
  printf("\n");
  grid[2][3] = 98;
  grid[4][4] = 402;
  print_grid(grid, 5, 5);
  return (0);
}

void print_grid(int **inputgrid, int a, int b)
{
  int i, j;

  for (i = 0; i < a; i++)
  {
    for (j = 0; j < b; j++)
    {
      printf("%d,", inputgrid[i][j]);
    }
    printf("\n");
  }

  printf("\n");
}
