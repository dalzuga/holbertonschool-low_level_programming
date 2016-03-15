int print_char(char c);

void print_diagonal(int n)
{
  int i, j;

  for (j = 1; j <= n; j++) 	/* at line j */
    {
      for (i = 1; i < j; i++) 	/* print j-1 spaces */
	{
	  print_char(' ');
	}
      print_char('\\');
      print_char('\n');
    }

  if (n <= 0)			/* print \n is 0 or less */
    print_char('\n');
}
