#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
void print_tree_all_nodes(BTree **tree);
void print_tree_node(BTree **tree);
void print_preorder(BTree *tree);
int test_insert();

int main()
{
        BTree *tree;

        tree = NULL;

	printf("insert:\tb\n");
        if (btree_insert(&tree, "b")) /* error check */
                return 1;
	printf("------------------\n");

	printf("insert:\tc\n");
	if (btree_insert(&tree, "c")) /* error check */
		return 1;
	printf("------------------\n");

	/* printf("insert:\tb\n"); */
	/* if (btree_insert(&tree, "b")) /\* error check *\/ */
	/* 	return 1; */
	/* printf("-------PRINTING STARTS NOW-----------\n"); */

	print_preorder(tree);

        return 0;
}
void print_preorder(BTree *tree)
{
	if (tree == NULL)
		return;

	printf("%s\n", tree->str);
	print_preorder(tree->left);
	print_preorder(tree->right);
}
