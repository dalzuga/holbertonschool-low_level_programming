#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int print_char(char c);

int main(int argc, char __attribute__((unused)) *argv[]) /* get around compiler flag */
{
  int fpi, fpo;
  char c;

  if (argc < 3)			/* check usage */
  {
    printf("usage\n");
    return 1;
  }

  fpi = open(argv[1], O_RDONLY);
  fpo = open(argv[2], O_RDWR | O_CREAT, 00644); /* read/write permission for owner, read for others */

  if (fpi == -1 || fpo == -1)
  {
    perror("open");
    return 1;
  }
  
  while(read(fpi, &c, 1) > 0)   /* read 1 byte and store it in char c */
  {
    write(fpo, &c, 1);
  }

  close(fpi);
  close(fpo);

  return 0;
}
