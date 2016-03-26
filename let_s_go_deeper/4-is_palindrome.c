int string_length(char * str);
int helper (char *first, char *last, int i);

int is_palindrome(char *s)
{
  int length = string_length(s);     /* stores length of string */
  int leftofmiddle = length / 2 - 1; /* gets position of left of middle char  */
  
  return helper(s, s + length - 1, leftofmiddle);
}

int string_length(char * str)
{
  if (*str == '\0')
    return 0;

  return 1 + string_length(str + 1);
}

int helper(char *first, char *last, int i)
{
  if (i == 0)
    return 1;

  if (*first != *last)
    return 0;

  return helper(first + 1, last - 1, i - 1);
}
