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

	print_preorder(tree);

	return 0;
}

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
