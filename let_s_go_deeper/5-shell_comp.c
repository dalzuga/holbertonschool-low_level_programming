int shell_comp(char *s1, char *s2)
{
  if (*s1 == '\0' && *s2 == '\0') /* if we reached the end of both strings */
    return 1;			  /* strings match */

  if (*s2 == '*' && *(s2 + 1) == '\0') /* if string 2 is only an asterisk */
    return 1;			       /* strings match */

  if (*s2 == '*' && *(s2 + 1) == '*') /* if string of '**' encountered */
    return shell_comp(s1, s2 + 1);    /* skip to the last one */




  /* case where there is a character following '*' on s2 */

  if ( *s2 == '*' &&  *(s2 + 1) != '\0' )
    return shell_comp



















  if (*s1 == *s2)		/* if the first characters of each string are equal */
    return shell_comp(s1 + 1, s2 + 1); /* move forward 1 character */


  if (*s2 == '*' && *(s1 + 1) != '\0')		/* if there is an asterisk on s2, traverse s1 */
    return shell_comp(s1 + 1, s2);

  if (*s1 == *s2)
    /* s1 = "ab", s2 = "a*", remove first character of each */
    return shell_comp(s1 + 1, s2 + 1); /* s1 = "b", s2 = "*" */
  if (*s2 == '*')
    return shell_comp(s1 + 1, s2 + 1);
}
