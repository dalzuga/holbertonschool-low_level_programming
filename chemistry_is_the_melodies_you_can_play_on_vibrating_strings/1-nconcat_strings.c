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

char *nconcat_strings(char *dest, const char *src, int n)
{
  int dest_len = str_len(dest); /* size_t holds any array size */
  int i;

  for (i = 0 ; i < n && src[i] != '\0' ; i++) /* while < n and not '\0' */
    dest[dest_len + i] = src[i];	      /* append char */
  dest[dest_len + i] = '\0';		      /* add '\0' at the end */

  return dest;
}
