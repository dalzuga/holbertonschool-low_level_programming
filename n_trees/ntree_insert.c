#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NTree *create_node(char *data);
List *create_list(void);
int ntree_list_insert(List **list, __attribute__((unused)) char **parents, char *data);

int ntree_insert(NTree **tree, __attribute__((unused)) char **parents, char *data)
{
	if (*tree == NULL)
	{
		printf("1\n");
		*tree = create_node(data);
		return 0;
	}

	if ((*tree)->children == NULL)
	{
		printf("2\n");
		(*tree)->children = create_list();
		return 0;
	}

	if ((*tree)->children->node == NULL)
	{
		printf("3\n");
		ntree_insert(&((*tree)->children->node), NULL, data);
		return 0;
	}

	if ((*tree)->children->next == NULL)
	{
		printf("4\n");
		(*tree)->children->next = create_list();
		if ((*tree)->children->next == NULL) /* error check */
			return 1;
		ntree_list_insert(&((*tree)->children->next), NULL, NULL);
		return 0;
	}

	printf("5\n");

	return 0;
}

int ntree_list_insert(List **list, __attribute__((unused)) char **parents, __attribute__((unused)) char *data)
{
	if ((*list)->next == NULL)
	{
		printf("list_insert:\t1\n");
		(*list)->next = create_list();
		/* (*list)->next->node = create_node(data); */
		if ((*list)->next == NULL) /* error check */
			return 1;
		return 0;
	}
	printf("list_insert:\t2\n");

	return 0;
}

NTree *create_node(char *data)
{
	NTree *node;

	node = malloc(sizeof(NTree));
	if (node == NULL)	/* malloc check */
		return NULL;

	node->str = strdup(data); /* set 'str' member */
	if (node->str == NULL) 	/* strdup alloc check */
		return NULL;
	
	node->children = NULL;	/* initiliaze 'children' member */

	return node;
}

List *create_list(void)
{
	List *list;

	list = malloc(sizeof(List));
	if (list == NULL)	/* malloc check */
		return NULL;

	list->next = NULL;	/* initialize list members */
	list->node = NULL;

	return list;
}
