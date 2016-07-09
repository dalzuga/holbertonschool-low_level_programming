#include "hashtable.h"

/* creates a hash table */
HashTable *ht_create(unsigned int size)
{
        HashTable *t;

        if (size < 1)
                return NULL;

        if (t = malloc (sizeof(HashTable)) == NULL)
                return NULL;

        if (t->array = malloc(size * sizeof(List) == NULL)
                return NULL;

        return t;
}
