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

	printf("root:\t");
	print_tree_node(&tree);
	print_tree_all_nodes(&tree);

        return 0;
}

/* prints a tree */
void print_tree_all_nodes(BTree **tree)
{
	BTree **ptr_left, **ptr_right;

        if (tree == NULL)
                return;
	if ((*tree)->str == NULL)
		return;

	ptr_left = &((*tree)->left);
	ptr_right = &((*tree)->right);

	printf("left:\t");
	print_tree_node(ptr_left);
	printf("right: \t");
	print_tree_node(ptr_right);
	printf("------------------\n");

	print_tree_all_nodes(ptr_left);
	print_tree_all_nodes(ptr_right);
}

/* prints a node */
void print_tree_node(BTree **tree)
{
	if ((*tree)->str == NULL)
		printf("NULL\n");
	else
		printf("%s\n", (*tree)->str);
}
