#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int print_char(char c);

int main(int argc, char __attribute__((unused)) *argv[]) /* get around compiler flag */
{
  int fp;
  char c;

  if (argc < 2)			/* check usage */
    return 1;
  
  fp = open("lorem_ipsum", O_RDONLY);

  if (fp == -1)
    return 1;
  
  while(read(fp, &c, 1) > 0)   /* read 1 byte and store it in char c */
  {
    print_char(c);
  }

  close(fp);

  return 0;
}
