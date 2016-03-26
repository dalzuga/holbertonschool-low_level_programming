int shell_comp(char *s1, char *s2)
{
  if (*s1 == '\0' && *s2 == '\0') /* if both strings are empty */
    return 1;			  /* strings match */

  if (*s2 == '*' && *(s2 + 1) == '\0') /* if string 2 is only an asterisk */
    return 1;			       /* strings match */

  if (*s2 != '*' && *s1 != *s2)
    return 0;

  if (*s2 == '*' && *(s2 + 1) == '*') /* if string of '**' encountered */
    return shell_comp(s1, s2 + 1);    /* skip to the last one */

  /* s1 = "ab", s2 = "a*", remove first character of each */
  if (*s1 == *s2)		/* if the first characters of each string are equal */
    return shell_comp(s1 + 1, s2 + 1); /* move forward 1 character */

  /* "xyza" and "*a"; keep going until s2[1] matches s1[3] */
  if (*s2 == '*' && *(s2 + 1) != *(s1) )
    return shell_comp(s1 + 1, s2);
  return shell_comp(s1 + 2, s2 + 2);
}
