#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
void print_preorder(BTree *tree);
BTree *btree_find(BTree *tree, char *str);

int main()
{
        BTree *tree;

        tree = NULL;

	printf("-------DANIEL'S TREE STARTS NOW-----------\n");

	printf("insert:\tb\n");
        if (btree_insert(&tree, "b")) /* error check */
                return 1;

	printf("insert:\ta\n");
	if (btree_insert(&tree, "a")) /* error check */
		return 1;

	printf("insert:\tc\n");
	if (btree_insert(&tree, "c")) /* error check */
		return 1;

	printf("insert:\tb\n");
        if (btree_insert(&tree, "b")) /* error check */
                return 1;

	printf("insert:\thello\n");
        if (btree_insert(&tree, "hello")) /* error check */
                return 1;

	print_preorder(tree);

	if (btree_find(tree, "hello") == NULL)
		printf("Not found.");
	else
		printf("Found!");

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
