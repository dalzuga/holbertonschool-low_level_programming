#include "my_functions.h"

void print_alphabet(void)
{
  int i; // declares i for use

  for (i=0;i<26;i++) // do a loop through all 26 characters
    {
      print_char(((char) i)+97); // add 97 to yield matching ASCII code for integer
    }
  print_char('\n'); // make a new line for printing
}
