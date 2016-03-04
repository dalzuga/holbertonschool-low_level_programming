int print_char(char);
void print_string(char *str)
{
  while (*str != '\0') 		/* while string isn't over */
    {
      print_char(*str); 	/* print value pointed to by str */
      str++;			/* pointer arithmetic for next char */
    }
}
