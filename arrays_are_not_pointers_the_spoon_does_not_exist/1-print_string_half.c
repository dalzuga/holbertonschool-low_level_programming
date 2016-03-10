int print_char(char c);

int str_len(char *str)
{
  int i;			/* i used as a counter */

  i = 0;			/* initialize at 0 */

  while (*str != '\0') 		/* while string isn't over */
    {
      i++;			/* increase counter */
      str++;			/* pointer arithmetic for next char */
    }

  return i;
}

void print_string_half(char *str)
{
  int length;   /* declare variables */

  length = str_len(str);

  str += (length + 1) / 2; /* get to just right of the middle */

  while (*str != '\0')
    {
      print_char(*str); /* print char */
      str++;
    }
}
