char *concat_strings(char *dest, const char *src)
{
  while (*dest != 0)	/* while dest is not null-terminating char */
    dest++;		/* get to the end */

  while (*src != 0) 	/* while src is not the null-terminating char */
    {
      src++;
      *dest = *src;
    }

  return dest;
}
