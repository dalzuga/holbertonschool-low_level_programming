#include "my_functions.h"

void print_combination_1(void)
{
  int i;

  print_char(48); /* prints 0 */

  for (i=1;i<10;i++) /* runs 9 times */
    {
      print_char(','); /* print comma */
      print_char(' '); /* print space */
      print_char(i+48); 	/* print corresponding number */
    }
}
