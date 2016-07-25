#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

void print_preorder(BTree *tree);
BTree *array_to_btree(char **array);
void btree_free(BTree *tree);

int main()
{
	BTree *tree;
	char *array[] = {"c", "g", "a", "f", "s", "b", NULL};

	printf("-------array_to_btree-----------\n");

	tree = array_to_btree(array);
	if (tree == NULL)	/* if no tree is created */
		return 1;	/* main() returns 1 */

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
