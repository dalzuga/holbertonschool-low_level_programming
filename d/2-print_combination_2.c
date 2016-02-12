#include "my_functions.h"

void print_combination_2(void)
{
  int i, j;

  for (i=0;i<9;i++) /* runs 8 times */
    {
      for (j=i+1;j<10;j++)
	{
	  print_char(i+48); 	/* print corresponding number */
	  print_char(j+48); 	/* print corresponding number */

	  if (!(i==8 && j==9)) 	/* make sure it's not the last number */
	    {
	      print_char(','); /* print comma */
	      print_char(' '); /* print space */
	    }
	}
    }
}
