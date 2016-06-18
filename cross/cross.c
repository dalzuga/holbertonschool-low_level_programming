#include <unistd.h>

void print_char(char c);

int main()
{
        print_char('c');
        return 0;
}

void print_char(char c)
{
        write(1, &c, 1);
}
