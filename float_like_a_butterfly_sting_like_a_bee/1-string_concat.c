#include <stdlib.h>

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

char *string_concat(char *s1, char *s2)
{
  int length1, length2, lengthtotal, i;
  char *strout; 			/* pointer to copy into */

  length1 = str_len(s1);
  length2 = str_len(s2);

  lengthtotal = length1 + length2 + 1; /* to accomodate null char */

  strout = malloc(sizeof(char) * lengthtotal); /* allocate memory */

  for (i = 0; i < length1; i++) /* copy string 1 */
  {
    *strout = *s1; 		/* copy char */
    s1++;			/* advance */
    strout++;			/* advance */
  }

  for (i = 0; i <= length1; i++) /* copy string 2 + null char */
  {
    *strout = *s2;		/* copy char */
    s2++;			/* advance */
    strout++;			/* advance */
  }

  return strout - lengthtotal - 4;
}
