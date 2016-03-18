char *leet(char *str)
{
  char *aux;			/* helper pointer */
  aux = str;			/* point to the same */

  while (*str != '\0')		/* while not at end of string */
  {
    if (*str == 'a' || *str == 'A')
      *str = '4';
    else if (*str == 'e' || *str == 'E')
      *str = '3';
    else if (*str == 'o' || *str == 'O')
      *str = '0';
    else if (*str == 't' || *str == 'T')
      *str = '7';
    else if (*str == 'l' || *str == 'L')
      *str = '1';
    str++;			/* go to next char */
  }
  str = aux;		    /* reset pointer to beginning of string */
  return str;	    /* string is now 1337ed, and return pointer */
}
