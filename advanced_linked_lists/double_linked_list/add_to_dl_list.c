#include <string.h>
#include <stdlib.h>
#include "list.h"

/* traverse list until next item is NULL */
int add_end_dl_list(List **list, char *str)
{
        List *a = *list;
        List *b;

        b = malloc (sizeof (List));
        if (b == NULL)
                return 1;

        b->str = strdup(str);
        if (b->str == NULL)
                return 1;

        while (a->next != NULL) {
                a = a->next;
        }

        a->next = b;
        b->prev = a;

        return 0;
}
