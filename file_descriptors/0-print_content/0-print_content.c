#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char __attribute__((unused)) *argv[]) /* get around compiler flag */
{
  int fp;

  if (argc < 2)			/* check usage */
    return 1;
  
  fp = open("lorem_ipsum", O_RDONLY, S_IREAD);

  if (fp == -1)
    return 1;
  
  close(fp);

  return 0;
}
