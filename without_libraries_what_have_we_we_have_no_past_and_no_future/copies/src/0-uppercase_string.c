int print_char(char c);

char *uppercase_string(char *str)
{
  char *aux; 			/* helper pointer */
  aux = str;			/* point to the same */

  while (*str != '\0')		/* while not at end of string */
  {
    if (*str > 96 && *str < 123)
      *str += ('A' - 'a');	/* convert to uppercase */
    str++;			/* go to next char */
  }

  str = aux; 			/* reset pointer to beginning of string */

  return str;	    /* string is now uppercased, and return pointer */
}
