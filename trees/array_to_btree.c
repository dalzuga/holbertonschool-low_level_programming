#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int btree_insert(BTree **tree, char *data);
BTree *btree_find(BTree *tree, char *str);
void print_preorder(BTree *tree);

/* create btree from array */
BTree *array_to_btree(char **array)
{
	BTree *tree;
	int i;

	tree = NULL;

	for (i = 0; array[i] != NULL; i++)
	{
		if (btree_insert(&tree, array[i]))
			return NULL;
	}
	
	printf("node returned:\t%s\n", tree->str);
	return tree;
}
