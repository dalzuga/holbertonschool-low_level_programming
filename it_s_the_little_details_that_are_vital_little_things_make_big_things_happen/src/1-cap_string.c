char *cap_string(char *str)
{
  char *aux;		   /* helper pointer */
  char flag = 1;	   /* trigger flag to capitalize first char */

  aux = str;			/* point to the same */

  while (*str != '\0')		/* while not at end of string */
  {
    if (flag && *str > 96 && *str < 123) /* if flag triggered and lchar */
      *str += ('A' - 'a');	/* convert to uppercase char */

    flag = 0;			/* reset flag */

    if (*str == ' ' || *str == '\t' || *str == '\n') /* if separator */
      flag = 1;					     /* trigger flag */
    str++;			/* go to next char */
  }

  str = aux;		    /* reset pointer to beginning of string */

  return str;	    /* string is now capitalized, and return pointer */
}
