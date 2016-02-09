#include "my_functions.h"

void print_tebahpla(void)
{
  int i;

  for (i=26;i>0;i--) /* start at z */
    {
      print_char(((char) i)+96); /* add 97 to match ASCII code for the integer */
    }
}
