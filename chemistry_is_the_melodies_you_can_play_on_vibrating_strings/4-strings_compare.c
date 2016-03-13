int strings_compare(char *s1, const char *s2)
{
  char flag = 0;

  int i;

  for (i = 0; s1[i] != '\0'; i++) /* go through the string */
    {
      if (s1[i] != s2[i])		   /* compare char by char */
	flag = 1;
    }

  if (flag)			/* if different */
    return *s1 - *s2; 		/* return the diff of first pair of char */
  return 0;			/* else the strings are the same */
}
