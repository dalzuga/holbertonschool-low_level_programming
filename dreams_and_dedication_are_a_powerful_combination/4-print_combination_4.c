#include "my_functions.h"

void print_combination_4(void)
{
  int i, j;

  for (i=0;i<99;i++) /* runs 98 times */
    {
      for (j=i+1;j<100;j++) 	/* runs all the way up to 99 */
	{
	  print_number(i+48); 	/* print corresponding number */
	  print_char(' ');	/* print space */
	  print_number(j+48); 	/* print corresponding number */

	  if (!(i==98 && j==99)) 	/* make sure it's not the last number */
	    {
	      print_char(','); /* print comma */
	      print_char(' '); /* print space */
	    }
	}
    }
}
