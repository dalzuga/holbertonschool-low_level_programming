#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);

int main()
{
        BTree **tree;
        char data[] = "Hello";

        if ((tree = malloc(sizeof(void *))) == NULL) {
                return 1;
        }        

        if (btree_insert(tree, data)) {
                printf("Success!\n");
        }

        printf("No success :(\n");
        return 0;
}
