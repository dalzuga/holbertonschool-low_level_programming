#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

BTree *create_node(char *data);

/* insert a tree node */
int btree_insert(BTree **tree, char *data)
{
	if (*tree == NULL)	/* very first node in the tree - 0th level */
	{
		*tree = create_node(data);
		if (*tree == NULL) /* error check */
			return 1;
	}
	else			/* first level of tree */
	{
		if (strcmp(data,(*tree)->str) < 0)
		{
			if ((*tree)->left == NULL)
			{
				(*tree)->left = create_node(data);
				if ((*tree)->left == NULL) /* error check */
					return 1;
			}
			else
				btree_insert(&((*tree)->left), data);
		}
		else if (strcmp(data,(*tree)->str) >= 0)
		{
			if ((*tree)->right == NULL)
			{
				(*tree)->right = create_node(data);
				if ((*tree)->right == NULL) /* error check */
					return 1;
			}
			else
				btree_insert(&((*tree)->right), data);

		}
	}

	return 0;
}

/* create a new node, allocate its members, initialize them, and return it */
BTree *create_node(char *data)
{
	BTree *node;
	node = malloc(sizeof(BTree));
	if (node == NULL)	/* malloc check */
		return NULL;

	node->str = strdup(data);
	if (node->str == NULL) 	/* strdup alloc check */
		return NULL;

	node->left = NULL; 	/* initialize */
	node->right = NULL;	/* initialize */

	return node;
}
