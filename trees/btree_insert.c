#include "tree.h"
#include <string.h>
#include <stdlib.h>

int empty_tree_check(BTree *tree);
int empty_tree(BTree *tree, char *data);
int nonempty_insert(BTree *tree, char *data);

/* insert a tree node */
int btree_insert(BTree *tree, char *data)
{
        /* allocate the BTree structure in memory with error-check */
        if ((*tree = malloc(sizeof(*BTree))) == NULL)
                return 1;

        /* copy our string to the data in the struct */
        if ((*tree->data = strdup(data)) == NULL) {
                
        }

        if (empty_tree_check(*tree)) {
                return empty_tree(*tree, *tree->data);
        }

        return nonempty_insert(*tree, *tree->data);
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
        if (tree.data == NULL)
                return 0;

        if ((*tree->data = strdup(data)) == 1)
                return 0;
        return 1;
}

/* tree that is not empty */
int nonempty_insert(BTree *tree, char *data)
{
        if (strcmp(tree->data, data) < 0) {
                if (empty_tree_check(tree.left)) {
                        return empty_tree(tree.left, data);
                }
        }
        else {
                if (empty_tree_check(tree.right) == NULL) {
                        return empty_tree(tree.right, data);
                }
        }

        return 0;
}
