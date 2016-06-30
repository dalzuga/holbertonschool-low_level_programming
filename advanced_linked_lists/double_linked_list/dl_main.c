#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int add_end_dl_list(List **list, char *str);

int main()
{
        List *list;

        printf("FIRST EXAMPLE:\n");

        add_end_dl_list(&list, "Holberton");

        printf("%s\n", list->str);

        return 0;
}
