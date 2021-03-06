#include "my_functions.h"

void print_combination_4(void)
{
  int i, j;

  for (i=0;i<99;i++) /* runs 98 times */
    {
      for (j=i+1;j<100;j++) 	/* runs all the way up to 99 */
	{
	  if (i<10)
	    print_char(48);	/* add leading 0 for i<10 */

	  print_number(i);	/* print first number */
	  print_char(' ');	/* print space */

	  if (j<10)
	    print_char(48);	/* add leading 0 for j<10 */

	  print_number(j);	/* print second number */

	  if (!(i==98 && j==99)) 	/* make sure it's not the last number */
	    {
	      print_char(','); /* print comma */
	      print_char(' '); /* print space */
	    }
	}
    }
}
