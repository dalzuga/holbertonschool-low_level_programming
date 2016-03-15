#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void print_array(int *a, int n)
{
  int i;

  if (n > 0)
    print_char('0');

  for (i = 1; i < n; i++) 	/* start at 2nd one */
    {
      print_char(',');
      print_char(' ');
      print_char(a[i]);
    }
  
  print_char('\n');
}
void reverse_array(int *a, int n)
{
  print_array(a, n);
}
