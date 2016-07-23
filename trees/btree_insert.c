#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* insert a tree node */
int btree_insert(BTree **tree, char *data)
{
	BTree *node;
	node = malloc(sizeof(BTree));
	if (node == NULL)	/* malloc check */
		return 1;

	node->str = strdup(data);
	if (node->str == NULL) 	/* strdup alloc check */
		return 1;

	node->left = NULL; 	/* initialize */
	node->right = NULL;	/* initialize */

	if (*tree == NULL)	/* very first node in the tree - 0th level */
		*tree = node;
	else			/* first level of tree */
	{
		if (strcmp(node->str,(*tree)->str) < 0)
		{
			if ((*tree)->left == NULL)
				(*tree)->left = node;
			else
				btree_insert(&((*tree)->left), data);				
		}
		else if (strcmp(node->str,(*tree)->str) >= 0)
		{
			if ((*tree)->right == NULL)
				(*tree)->right = node;
			else
				btree_insert(&((*tree)->right), data);

		}
	}

	return 0;
}
