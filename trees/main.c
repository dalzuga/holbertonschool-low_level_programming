#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
void print_tree(BTree *tree);

int main()
{
        BTree *tree;

        tree = NULL;

        if (btree_insert(&tree, "e")) /* error check */
                return 1;
        if (btree_insert(&tree, "i")) /* error check */
                return 1;
	if (btree_insert(&tree, "b")) /* error check */
		return 1;

        return 0;
}

/* prints a node */
void print_tree(BTree *tree)
{
        if (tree == NULL) {
                printf("Tree NULL\n");
                return;
        }

        printf("print_tree:\t%s\n", (*tree).str);
}
