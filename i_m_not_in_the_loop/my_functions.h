#include <stdio.h>

int print_char(char c);
void print_z(void);
void print_alphabet(void);

void print_z(void)
{
  puts("z");
}

int i;

void print_alphabet(void)
{
  for (i=0;i<26;i++)
    {
      printf("%c", i+97);
    }

  puts("");
}
