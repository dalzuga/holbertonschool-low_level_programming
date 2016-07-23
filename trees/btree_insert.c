#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int create_node(BTree **tree, char *data);
int find_and_insert(BTree **tree, char *data);
void print_tree(BTree *tree);

/* insert a tree node */
int btree_insert(BTree **tree, char *data)
{
	if (*tree == NULL) {	/* insert node if doesnt exist */
		if (create_node(tree, data))
			return 1;
	}
	else {
		find_and_insert(tree, data);
	}

	return 0;
}

/* if there is no node allocated in memory, create and allocate */
int create_node(BTree **tree, char *data)
{
	(*tree) = malloc(sizeof(BTree));
	if (*tree == NULL)	 /* error check */
		return 1;
	
	(*tree)->str = strdup(data);
	if ((*tree)->str == NULL)  /* error check */
		return 1;

	(*tree)->left = malloc(sizeof(BTree));
	if ((*tree)->left == NULL) /* error check */
		   return 1;

	(*tree)->right = malloc(sizeof(BTree));
	if ((*tree)->right == NULL) /* error check */
		   return 1;

	return 0;
}

/* find a place to insert a node, then insert */
int find_and_insert(BTree **tree, char *data)
{
	BTree **ptr;

	if (strcmp((*tree)->str, data) <= 0)
	{
		printf("one\n");
		/* if ((*tree)->left == NULL) */
		/* { */
		ptr = &((*tree)->left);
		if (create_node(ptr, data))
			return 1;
		print_tree(*tree);
		/* } */
	}
	else if (strcmp((*tree)->str, data) > 0)
	{
		/* if ((*tree)->right == NULL) */
		/* { */
			ptr = &((*tree)->right);
			if (create_node(ptr, data))
				return 1;
			print_tree(*tree);
		/* } */
	}
	return 0;
}
