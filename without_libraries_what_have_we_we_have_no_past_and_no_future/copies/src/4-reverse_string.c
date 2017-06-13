int str_len(char *str);

void reverse_string(char *s)
{
  int i, length; 			/* length and counter variables  */
  char c;				/* char holder */

  length = str_len(s); 		/* obtain string length */

  for (i = 0; i < length/2; i++) /* split the string in 2 */
    {
      c = *(s + i);		       /* c holds char in left half */
      *(s + i) = *(s + length - 1 - i); /* left half becomes right half  */
      *(s + length - 1 - i) = c;	/* right half becomes old left half */
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
