#include <stdio.h>
#include <string.h>
int strings_compare(char *s1, const char *s2);

int main(void)
{
  char s1[] = "Hello";
  char s2[] = "Horld!";

  printf("%d\n", strings_compare(s1, s2));
  printf("strcmp: %d\n", strcmp(s1, s2));
  printf("%d\n", strings_compare(s2, s1));
  printf("strcmp: %d\n", strcmp(s2, s1));
  printf("%d\n", strings_compare(s1, s1));
  printf("strcmp: %d\n", strcmp(s1, s1));
  return (0);
}
