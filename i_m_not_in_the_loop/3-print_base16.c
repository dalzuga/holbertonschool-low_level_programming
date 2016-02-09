#include "my_functions.h"

void print_base16(void)
{
  int i;

  for (i=0;i<16;i++) // run a total of 16 times, for 0 through F
    {
      if (i<10) // while the numbers still match the decimal system
	print_char(((char) i)+48); // print the integer's value by matching the ASCII code
      else // once the numbers are greater than 9
	print_char(((char) i)+55); // start printing A through F by matching the ASCII code
    }
<<<<<<< HEAD
  print_char('\n'); // new line
=======
>>>>>>> 433ca2c2d5a4b69afa11b50f95f7af66adc35531
}
