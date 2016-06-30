#include <string.h>
#include <stdlib.h>
#include "list.h"

/* traverse list until next item is NULL */
int add_end_dl_list(List **list, char *str)
{
        /* node a */
        List *a = *list;
        /* node b */
        List *b;

        /* create b and check for errors */
        b = malloc (sizeof (List));
        if (b == NULL)
                return 1;

        /* make b point to the string */
        b->str = strdup(str);
        if (b->str == NULL)
                return 1;
        /*
         * if no node, b is our only node.
         * point first node of **list to b
         * and we are done.
         */
        if (*list == NULL) {
                *list = b;
                return 0;
        }

        /* advance through the list */
        while (a->next != NULL) {
                a = a->next;
        }

        a->next = b;
        b->prev = a;

        return 0;
}
