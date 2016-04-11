#include <stdlib.h>
char *string_dup(char *str)
{
  int i, length;
  char *str2; 			/* hold the second string */

  for (i = 0; *str != '\0'; i++) /* get the length */
  {
    str++;
  }

  length = i;

  str = str - length; 		/* pointer arithmetic to first element */

  str2 = malloc( sizeof(char) * (length + 1) ); /* assign the memory */

  for (i = 0; i <= length; i++)	/* copy null char as well */
  {
    *str2 = *str; 		/* copy char */
    str++;			/* increase */
    str2++;			/* char */
  }

  return str2 - length - 1; 	/* return the pointer */
}
