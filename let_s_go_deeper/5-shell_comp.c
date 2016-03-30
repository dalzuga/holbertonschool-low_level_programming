int shell_comp(char *s1, char *s2)
{
  if (*s1 == '\0' && *s2 == '\0') /* if both strings are empty */
    return 1;			  /* strings match */
  if (*s2 == '*' && *(s2 + 1) == '\0') /* if string 2 is only an asterisk */
    return 1;			       /* strings match */
  if (*s2 != '*' && *s1 != *s2)	/* if string 2 is a character, and s1 doesn't match */
    return 0;			/* strings don't match */
  if (*s2 == '*' && *(s2 + 1) == '*') /* if string of '**' encountered */
    return shell_comp(s1, s2 + 1);    /* skip to the last one */
  if (*s1 == '\0' && *s2 != '\0')
    return 0;
  /* s1 = "ab", s2 = "a*", remove first character of each */
  if (*s1 == *s2)
    return ( shell_comp(s1 + 1, s2 + 1) );
  /* "xyza" and "*a"; keep going until s1 becomes "a" */
  if (*s2 == '*' && *(s2 + 1) != *(s1) ) 
    return shell_comp(s1 + 1, s2);
  /* we are at "a", "*a" */  
  if (*s2 == '*' && *(s2 + 1) == *s1 )
    return ( shell_comp(s1, s2 + 1) || shell_comp(s1 + 1, s2) );
  return 12345;
}
