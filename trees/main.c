#include "tree.h"
#include <stdlib.h>

int btree_insert(BTree **tree, char *data);

int main()
{
        BTree **tree;

        if ((tree = malloc(sizeof(struct *BTree))) == NULL) {
                return 1;
        }

        if ((*tree = malloc(sizeof(struct BTree)) == NULL))
                return 1;

        char *tree->data[] = "hello";

        if (btree_insert(**tree, data)) {
                printf("Success!\n");
        }

        return 0;
}
