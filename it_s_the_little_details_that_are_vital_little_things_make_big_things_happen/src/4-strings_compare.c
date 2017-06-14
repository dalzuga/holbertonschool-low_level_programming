int strings_compare(char *s1, const char *s2)
{
  int i;

  for (i = 0; s1[i] != '\0'; i++) /* go through the string */
    {
      if (s1[i] != s2[i])		   /* compare char by char */
	return s1[i] - s2[i];		   /* if different, return diff */
    }

  return 0;			/* strings are the same */
}
