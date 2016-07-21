#include "tree.h"
#include <stdlib.h>

int btree_insert(BTree **tree, char *data);

int main()
{
        BTree **tree;
        char data[] = "Hello";

        /* allocate the BTree in memory with error-check */
        if ((*tree = malloc(sizeof(struct BTree)) == NULL))
                return 1;

        /* copy our string to the data in the struct */
        if ((*tree->data = strdup(data)) == NULL) {
                
        }

        if (btree_insert(&tree, data)) {
                printf("Success!\n");
        }

        return 0;
}
