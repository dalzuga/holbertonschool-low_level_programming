#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void print_preorder(BTree *tree);
BTree *array_to_btree(char **array);
int btree_depth(BTree *tree);
void btree_free(BTree *tree);
int btree_insert(BTree **tree, char *data);

int main()
{
	BTree *tree;
	/* char *array[] = {"lera", "danya", "lenya", "leonid", "daniel", "valerie",  NULL}; */

	/* printf("-------array_to_btree-----------\n"); */

	/* tree = array_to_btree(array); */
	/* if (tree == NULL)	/\* if no tree is created *\/ */
	/* 	return 1;	/\* main() returns 1 *\/ */

	/* print_preorder(tree); */

	/* printf("the depth is:\t%d\n", btree_depth(tree)); */

	/* btree_free(tree); */

	tree = NULL;
	printf("---------------------\n");

	btree_insert(&tree, "q - 1");
	btree_insert(&tree, "w - 6");
	btree_insert(&tree, "e - 2");
	btree_insert(&tree, "r - 7");
	btree_insert(&tree, "t - 8");
	btree_insert(&tree, "y - 10");
	btree_insert(&tree, "u - 9");
	btree_insert(&tree, "i - 3");
	btree_insert(&tree, "o - 4");
	btree_insert(&tree, "p - 5");

	printf("the depth is:\t%d\n", btree_depth(tree));

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
