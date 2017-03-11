#ifndef HOLBERTON
#define HOLBERTON

/* _putchar - prints a single character */
int _putchar(char c);

/* my recursive print function */
void _puts_recursion(char *s);

/* my reverse recursive print function */
void _print_rev_recursion(char *s);

/* my recursive strlen function */
int _strlen_recursion(char *s);

/* my recursive factorial function */
int factorial(int n);

/* my exponentiation function */
int _pow_recursion(int x, int y);

/* my sqrt recursive function */
int _sqrt_recursion(int n);
/* helper for _sqrt_recursion */
int sqrt_helper(int n, int i);

/* recursive prime checking */
int is_prime_number(int n);
/* helper for is_prime_number recursion */
int is_prime_helper(int n, int i);

/* checks if a string is a palindrome */
int is_palindrome(char *s);
/* helper for is_palindrome recursion  */
int is_palindrome_helper(char *s, int s_len);
  
#endif
