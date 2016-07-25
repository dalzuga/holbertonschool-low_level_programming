#include "tree.h"
#include <stdlib.h>

int recursive(BTree *tree, int level);

/* returns the tree depth, given the root node */
int btree_depth(BTree *tree)
{
	return recursive(tree, 0);
}

int recursive(BTree *tree, int level)
{
	int right, left;
	right = left = level;

	if (tree->left != NULL)
		left = recursive(tree->left, level + 1);
	if (tree->right != NULL)
		right = recursive(tree->right, level + 1);
	if (right > left)
		return right;
	return left;
}
