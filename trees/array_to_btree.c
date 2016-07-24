#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
BTree *btree_find(BTree *tree, char *str);
void print_preorder(BTree *tree);

/* create btree from array */
int array_to_btree(char **array)
{
	BTree *tree;
	int i;

	tree = NULL;

	i = 0;
	for (i = 0; (*array)[i] != '\0'; i++)
	{
		if (btree_insert(&tree, &((*array)[i])))
			return 1;
	}

	/* print_preorder(tree); */

	return 0;
}
