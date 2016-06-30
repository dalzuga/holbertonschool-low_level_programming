#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int add_end_dl_list(List **list, char *str);
int add_begin_dl_list(List **list, char *str);
List *array_to_dl_list(char **array);

int main()
{
        List *list;

        add_end_dl_list(&list, "Holberton");
        add_end_dl_list(&list, "Engineer");
        add_begin_dl_list(&list, "Daniel");

        printf("FIRST EXAMPLE:\n");
        printf("%s\n", list->str);

        printf("SECOND EXAMPLE:\n");
        list = list->next;
        printf("%s\n", list->str);

        return 0;
}
