#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int insert_node_data(BTree **tree, char *data);
int find_create_node_and_insert(BTree **tree, char *data);
int allocate_left_right_nodes(BTree **tree);

/* insert a tree node */
int btree_insert(BTree **tree, char *data)
{
	if (*tree == NULL)	/* insert node if doesnt exist */
	{
		(*tree) = malloc(sizeof(BTree));
		if (*tree == NULL)	/* error check */
			return 1;
		if (insert_node_data(tree, data)) /* error check */
			return 1;
	}
	else if ((*tree)->str == NULL)
	{
		if (insert_node_data(tree, data)) /* error check */
			return 1;		
	}
	else
		find_create_node_and_insert(tree, data);

	return 0;
}

/* store data string, allocate memory for its nodes */
int insert_node_data(BTree **tree, char *data)
{
	(*tree)->str = strdup(data);
	if ((*tree)->str == NULL) /* error check */
		return 1;

	if (allocate_left_right_nodes(tree))
		return 1;

	return 0;
}

/* allocate memory for node members left and right, and initialize to NULL */
int allocate_left_right_nodes(BTree **tree)
{
	(*tree)->left = malloc(sizeof(BTree));
	if ((*tree)->left == NULL) /* error check */
		return 1;

	(*tree)->right = malloc(sizeof(BTree));
	if ((*tree)->right == NULL) /* error check */
		return 1;

	((*tree)->left)->str = NULL;
	((*tree)->right)->str = NULL;

	((*tree)->left)->left = NULL;
	((*tree)->left)->right = NULL;
	((*tree)->right)->right = NULL;
	((*tree)->right)->left = NULL;

	return 0;
}

/* data is full at this point, need to create new node */
int find_create_node_and_insert(BTree **tree, char *data)
{
	BTree **ptr;

	if (strcmp(data, (*tree)->str) <= 0)
	{
		ptr = &((*tree)->left);
		(*ptr)->str = NULL;
		printf("left\n");
		if (btree_insert(ptr, data))
			return 1;
	}
	else if (strcmp(data, (*tree)->str) > 0)
	{
		ptr = &((*tree)->right);
		printf("right\n");
		(*ptr)->str = NULL;
		if (btree_insert(ptr, data))
			return 1;
	}
	return 0;
}
