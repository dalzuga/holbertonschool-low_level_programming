#include "hashtable.h"
#include <stdlib.h>

/* creates a hash table */
HashTable *ht_create(unsigned int size)
{
        HashTable *t;

        if (size < 1)
                return NULL;

        /* create HashTable and check for allocation errors */
        if ((t = malloc (sizeof (HashTable))) == NULL)
                return NULL;

        /* create List and check for allocation errors */        
        if ((t->array = malloc(size * sizeof(List)) == NULL)
                return NULL;

        return t;
}
