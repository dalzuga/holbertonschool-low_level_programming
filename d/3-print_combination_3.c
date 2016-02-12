#include "my_functions.h"

void print_combination_3(void)
{
  int i, j, k;

  for (i=0;i<8;i++) /* runs 7 times */
    {
      for (j=i+1;j<9;j++)
	{
	  for (k=j+1;k<10;k++)
	    {
	      print_char(i+48); 	/* print corresponding number */
	      print_char(j+48);
	      print_char(k+48);

	      if (!(i==7 && j==8 && k==9)) 	/* make sure it's not the last number */
		{
		  print_char(','); /* print comma */
		  print_char(' '); /* print space */
		}
	    }
	}
    }
}
