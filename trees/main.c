#include "tree.h"
#include <stdlib.h>

int btree_insert(BTree **tree, char *data);

int main()
{
        BTree **tree;
        char data[] = "Hello";

        /* allocate the BTree structure in memory with error-check */
        if ((*tree = malloc(sizeof(struct BTree)) == NULL))
                return 1;

        if (btree_insert(&tree, data)) {
                printf("Success!\n");
        }

        return 0;
}
