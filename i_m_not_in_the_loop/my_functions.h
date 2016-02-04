#include <unistd.h>

int print_char(char c)
{
  return (write(1, &c, 1));
}

void print_z(void)
{
  print_char('z');
  print_char('\n');
}

void print_alphabet(void)
{
  int i;

  for (i=0;i<26;i++)
    {
      print_char(((char) i)+97);
    }
  print_char('\n');
}
