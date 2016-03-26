int string_length(char * str);
int helper (char *first, char *last);

int is_palindrome(char *s)
{
  int length = string_length(s);     /* stores length of string */
  
  return helper(s, s + length - 1);
}

int string_length(char * str)
{
  if (*str == '\0')
    return 0;

  return 1 + string_length(str + 1);
}

int helper(char *first, char *last)
{
  int n;
  n = 8;
  if (last - first < n)
    return 1;

  if (*first != *last)
    return 0;

  return helper(first + 1, last - 1);
}
