int print_char(char c);

void print_string_2(char *str)
{
  int i;			/* counter i */
  i = 0;

  while (*str != '\0')
    {
      if (i % 2 == 0) 		/* for every 2nd character */
	print_char(*str);	/* print char */
      i++;
      str++;
    }
}
