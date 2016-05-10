#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int print_char(char c);

int main(int argc, char __attribute__((unused)) *argv[]) /* get around compiler flag */
{
  char c;

  if (argc != 1)			/* check usage */
  {
    /* printf("usage\n"); */
    return 1;
  }

  while(read(0, &c, 1) != -1)   /* read 1 byte from stdin and store it in char c */
    /* if no error, keep going */
  {
    if (c == 4)			/* if Ctrl-D EOT character (ASCII value 4) */
      break;
    print_char(c);
  }

  return 0;
}
