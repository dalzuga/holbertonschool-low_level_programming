#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* free a binary tree */
void btree_free(BTree *tree)
{
	if (tree->left != NULL)
		btree_free(tree->left);
	if (tree->right != NULL)
		btree_free(tree->right);

	free(tree->str);
	free(tree);
}
