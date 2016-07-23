#include "tree.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int insert_node_data(BTree **tree, char *data);
int find_create_node_and_insert(BTree **tree, char *data);
void print_tree(BTree *tree);

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

/* store data string, allocate memory for node members left and right */
int insert_node_data(BTree **tree, char *data)
{
	(*tree)->str = strdup(data);
	if ((*tree)->str == NULL) /* error check */
		return 1;

	(*tree)->left = malloc(sizeof(BTree));
	if ((*tree)->left == NULL) /* error check */
		return 1;

	(*tree)->right = malloc(sizeof(BTree));
	if ((*tree)->right == NULL) /* error check */
		return 1;

	return 0;
}

/* data is full at this point, need to create new node */
int find_create_node_and_insert(BTree **tree, char *data)
{
	BTree **ptr;

	if (strcmp(data, (*tree)->str) <= 0)
	{
		ptr = &((*tree)->left);
		printf("left\n");
		if (btree_insert(ptr, data))
			return 1;
	}
	else if (strcmp(data, (*tree)->str) > 0)
	{
		ptr = &((*tree)->right);
		printf("right\n");
		if (btree_insert(ptr, data))
			return 1;
	}
	return 0;
}
