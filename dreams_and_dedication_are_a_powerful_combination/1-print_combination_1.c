#include "my_functions.h"

void print_combination_1(void)
{
  int i;

  print_char(48);

  for (i=1;i<10;i++)
    {
      print_char(',');
      print_char(' ');
      print_char(i+48);
    }
}
