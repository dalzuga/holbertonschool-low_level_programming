#include <stdio.h>
int str_len(char *str);

void reverse_string(char *s)
{
  int i, length; 			/* length and counter variables  */
  char c;				/* char holder */

  length = str_len(s); 		/* obtain string length */

  printf("%d\n", length);
  printf("length/2: %d\n", length/2);

  for (i = 0; i < length; i++)
    {
      printf("s[%d] = %c\n", i, *(s + i));
    }

  for (i = 0; i < length/2; i++) /* split the string in 2 */
    {
      c = *(s + i);		    /* c holds char in left half */
      *(s + i) = *(s + length - i - 1); /* left half becomes right half  */
      *(s + length - i - 1) = c;	/* right half becomes old left half */
      printf("*(s+i) = %c ||| ", *(s+i));
      printf("*(s+length-i) = %c\n", *(s+length-i));
    }

  for (i = 0; i < length; i++)
    {
      printf("s[%d] = %c\n", i, *(s + i));
    }
}

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
