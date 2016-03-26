#include <stdio.h>

int shell_comp(char *s1, char *s2);

int main(void)
{
  int r;
  r = shell_comp("abc", "*");
  printf("abc, *\n");
  printf("Result: %d\n", r);
  printf("Expected: 1\n");
  r = shell_comp("abc", "****");
  printf("abc, ****\n");
  printf("Result: %d\n", r);
  printf("Expected: 1\n");
  r = shell_comp("ab", "a*");
  printf("ab, a*\n");
  printf("Result: %d\n", r);
  printf("Expected: 1\n");
  r = shell_comp("ab", "*b");
  printf("ab, *b\n");
  printf("Result: %d\n", r);
  printf("Expected: 1\n");
  printf("ab, *a\n");
  r = shell_comp("ab", "*a");
  printf("Result: %d\n", r);
  printf("Expected: 0\n");
  r = shell_comp("ab", "*c");
  printf("ab, *c\n");
  printf("Result: %d\n", r);
  printf("Expected: 0\n");
  r = shell_comp("xyza", "*a");
  printf("xyza, *a\n");
  printf("Result: %d\n", r);
  printf("Expected: 1\n");
  printf("---------------------------\n");
  r = shell_comp("main.c", "*.c");
  printf("%d\n", r);
  r = shell_comp("main.c", "m*a*i*n*.*c*");
  printf("%d\n", r);
  r = shell_comp("main.c", "main.c");
  printf("%d\n", r);
  r = shell_comp("main.c", "m*c");
  printf("%d\n", r);
  r = shell_comp("main.c", "ma********************************c");
  printf("%d\n", r);
  r = shell_comp("main.c", "*");
  printf("%d\n", r);
  r = shell_comp("main.c", "***");
  printf("%d\n", r);
  r = shell_comp("main.c", "m.*c");
  printf("%d\n", r);
  r = shell_comp("main.c", "**.*c");
  printf("%d\n", r);
  r = shell_comp("main-main.c", "ma*in.c");
  printf("%d\n", r);
  return (0);
}
