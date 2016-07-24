#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

BTree *array_to_btree(char **array)
{
	
}

/* find a node and return it, returns NULL if not found */
BTree *btree_find(BTree *tree, char *str)
{
	if (tree == NULL) 	/* check if empty node */
		return NULL;
	
	if (strcmp(str, tree->str) == 0) /* node found, return it */
		return tree;
	else
	{
		if (btree_find(tree->left, str) != NULL) /* if found on left */
			return tree->left;		 /* return it */
		else if (btree_find(tree->right, str) != NULL) /* if on right */
			return tree->right;		       /* return it */
	}

	return NULL; 		/* not found */
}
