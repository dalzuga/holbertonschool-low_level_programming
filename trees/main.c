#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
void print_tree_all_nodes(BTree **tree);
void print_tree_node(BTree **tree);

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
	if (btree_insert(&tree, "f")) /* error check */
		return 1;
	if (btree_insert(&tree, "f")) /* error check */
		return 1;

	print_tree_all_nodes(&tree);

        return 0;
}

/* prints a tree */
void print_tree_all_nodes(BTree **tree)
{
	BTree **ptr;

        if (tree == NULL)
                return;
	if ((*tree)->str == NULL)
		return;

	print_tree_node(tree);

	ptr = &((*tree)->left);
	if (ptr != NULL)
		print_tree_all_nodes(ptr);

	ptr = &((*tree)->right);
	if (ptr != NULL)
		print_tree_all_nodes(ptr);
}

/* prints a node */
void print_tree_node(BTree **tree)
{
        if (tree == NULL || *tree == NULL || (*tree)->str == NULL)
                return;

	printf("%s\n", (*tree)->str);
}
