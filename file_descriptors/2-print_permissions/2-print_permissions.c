#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int print_char(char c);
void print_permissions(struct stat fileStat);

int main(int argc, char __attribute__((unused)) *argv[]) /* get around compiler flag */
{
  struct stat fileStat;

  if (argc != 2) 		/* usage */
    return 1;

  if ( lstat(argv[1], &fileStat) == -1 )
    return 1;

  print_permissions(fileStat);

  print_char('\n');
  return 0;
}

void print_permissions(struct stat fileStat)
{
  print_char( (S_ISDIR(fileStat.st_mode)) ? 'd' : '-');
  print_char( (fileStat.st_mode & S_IRUSR) ? 'r' : '-');
  print_char( (fileStat.st_mode & S_IWUSR) ? 'w' : '-');
  print_char( (fileStat.st_mode & S_IXUSR) ? 'x' : '-');
  print_char( (fileStat.st_mode & S_IRGRP) ? 'r' : '-');
  print_char( (fileStat.st_mode & S_IWGRP) ? 'w' : '-');
  print_char( (fileStat.st_mode & S_IXGRP) ? 'x' : '-');
  print_char( (fileStat.st_mode & S_IROTH) ? 'r' : '-');
  print_char( (fileStat.st_mode & S_IWOTH) ? 'w' : '-');
  print_char( (fileStat.st_mode & S_IXOTH) ? 'x' : '-');  
}
