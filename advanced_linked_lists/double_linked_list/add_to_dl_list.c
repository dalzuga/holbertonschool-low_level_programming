#include <string.h>
#include <stdlib.h>
#include "list.h"

/* add node to the end of a list */
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

        /* initialize prev and next values to NULL */
        b->next = NULL;
        b->prev = NULL;

        /* add to b the string we want */
        b->str = strdup(str);
        /* memory allocation check */
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

/* add node to the beginning of a list */
int add_begin_dl_list(List **list, char *str)
{
        /* node b */
        List *b;

        /* create b and check for errors */
        b = malloc (sizeof (List));
        if (b == NULL)
                return 1;

        /* initialize prev and next values to NULL */
        b->next = NULL;
        b->prev = NULL;

        /* add to b the string we want */
        b->str = strdup(str);
        /* memory allocation check */
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

        b->next = *list;
        *list = b;
        
        /*
         * For the Part 2: Initialize the prev pointer of the element
         * you created to NULL, or just don't touch it. We will not
         * use it in this part.
         */

        return 0;
}

List *array_to_dl_list(char **array)
{
        
}
