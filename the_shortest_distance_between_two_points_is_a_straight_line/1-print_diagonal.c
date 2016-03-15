int print_char(char c);

void print_diagonal(int n)
{
  int i, j;

  for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
	print_char(' ');
      print_char('\\');
      print_char('\n');
    }

  print_char('\n');
}
