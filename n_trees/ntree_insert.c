#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


NTree *create_node(char *data);
List *create_list(void);

int ntree_insert(NTree **tree, __attribute__((unused)) char **parents, char *data)
{
	if (tree == NULL)
		*tree = create_node(data);

	return 0;
}

NTree *create_node(char *data)
{
	NTree *node;

	node = malloc(sizeof(NTree));
	if (node == NULL)	/* malloc check */
		return NULL;

	node->str = strdup(data); /* set 'str' member */
	if (node->str == NULL) 	/* strdup allock check */
		return NULL;
	
	node->children = NULL;

	return node;
}

List *create_list(void)
{
	List *list;

	list = malloc(sizeof(List));
	if (list == NULL)	/* malloc check */
		return NULL;

	list->next = NULL;
	list->node = NULL;

	return list;
}
