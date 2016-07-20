#include "tree.h"
#include <strings.h>
#include <stdlib.h>

int empty_tree_check(BTree *tree);
int empty_tree(BTree *tree, char *data);
int nonempty_insert(BTree *tree, char *data);

/* insert a tree node */
int btree_insert(BTree **tree, char *data)
{
        if (empty_tree_check(*tree))
                return empty_tree(*tree, data);
        return nonempty_insert(*tree, data);
}

/* return 1 if empty, 0 if not empty */
int empty_tree_check(BTree *tree)
{
        if (tree->data == NULL)
                return 1;
        return 0;
}

/*
 * copy the data over
 * return 0 on success, 1 on fail
 */
int empty_tree(BTree *tree, char *data)
{
        if ((*tree->data = strdup(data)) == 1)
                return 0;
        return 1
}

/* definition of subtree: tree that is not empty */
int nonempty_insert(BTree *tree, char *data)
{
        if (strcmp(tree->data, data) < 0) {
                if (empty_tree_check(tree.left)) {
                        
                }
        }
}
        else {
                if ((tree->right = malloc(BTree)) == NULL)
                        return 1;
        }
        return 0;
}
