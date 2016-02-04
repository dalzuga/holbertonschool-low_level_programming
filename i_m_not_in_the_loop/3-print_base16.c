#include "my_functions.h"

void print_base16(void)
{
  int i;

  for (i=0;i<16;i++)
    {
      if (i<10)
	print_char(((char) i)+48);
      else
	print_char(((char) i)+55);
    }
  print_char('\n');
}
