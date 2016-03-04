#include <stdio.h>
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
