#include <stdio.h>

char *rot13(char *str)
{
  char *aux;			/* helper char pointer */
  aux = str; 			/* point to the same */

  while (*str != '\0')		/* while not at end of string */
  {
    if (*str >= 'a' && *str <= 'z') /* if lowercase letter */
    {
      *str = *str - 13;		/* subtract 13 places due to limits */
      if (*str < 'a')
	*str = *str + 26;	/* rotate as needed */
    }
    else if (*str >= 'A' && *str <= 'Z') /* if uppercase letter */
    {
      *str = *str + 13;		/* add 13 places */
      if (*str > 'Z')
	*str = *str - 26;	/* rotate as needed */
    }
    str++;
  }
  return aux;		      /* return beginning of string pointer */
}
