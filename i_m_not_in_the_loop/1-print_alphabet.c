#include "my_functions.h"

void print_alphabet(void)
{
  int i;

  for (i=0;i<26;i++)
    {
      print_char(((char) i)+97);
    }
  print_char('\n');
}
