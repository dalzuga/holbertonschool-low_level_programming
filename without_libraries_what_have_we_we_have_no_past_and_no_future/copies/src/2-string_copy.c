char *string_copy(char *dest, const char *src)
{
  int i;

  for (i = 0; src[i] != '\0'; i++) /* go through the string */
    dest[i] = src[i];		   /* copy char by char */

  i++;				/* add one to counter */
  dest[i] = '\0';		/* add null-terminating char */

  return dest;
}
