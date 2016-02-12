#include "my_functions.h"

void print_combination_2(void)
{
  int i, j;

  print_char(48);
  print_char(49); 		/* these two lines print the first number */

  for (j=2;j<10;j++)
    {
      print_char(','); /* print comma */
      print_char(' '); /* print space */
      print_char(48);
      print_char(j+48); 	/* these two lines print the rest of the first line */
    }


  for (i=1;i<9;i++) /* runs 9 times */
    {
      for (j=i+1;j<10;j++)
	{
	  print_char(','); /* print comma */
	  print_char(' '); /* print space */
	  print_char(i+48); 	/* print corresponding number */
	  print_char(j+48); 	/* print corresponding number */
	}

    }
}
