#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

List *create_child(char *data);
NTree *find_parent_node(NTree **tree, char **parents);
int string_array_size(char **parents);
int ntree_insert_parent(NTree **tree, char *data);

int ntree_insert(NTree **tree, char **parents, char *data)
{
	NTree *parent_node_ptr;
	List *list_ptr;
	int depth, i;
	parent_node_ptr = NULL;
	list_ptr = NULL;

	depth = string_array_size(parents);

	printf("path is \"");

	for (i = 0; i < depth; i++)
	{
		printf("%s ", parents[i]);
	}

	printf("\". data is: %s. depth is: %d\n", data, depth);

	if (depth == 0)      /* if there are no nodes, create root */
	{
		list_ptr = create_child(data); /* make root node */
		parent_node_ptr = list_ptr->node;
		free(list_ptr);
		if (parent_node_ptr == NULL)	      /* error check */
			return 1;
		*tree = parent_node_ptr; /* connect the tree */

		return 0;
	}

	parent_node_ptr = find_parent_node(tree, parents);
	if (parent_node_ptr == NULL) /* error check */
		return 1;

	printf("parent dir is:\t%s\n", parent_node_ptr->str);

	if (ntree_insert_parent(&parent_node_ptr, data) == 1)
		return 1;

	return 0;
}

/* inserts a node to the parent node specified by the NTree double pointer */
int ntree_insert_parent(NTree **parent_node_dp, char *data)
{
	NTree *parent_node_ptr;
	List *list_ptr;
	list_ptr = NULL;
	parent_node_ptr = NULL;

	if (parent_node_dp == NULL) /* make sure there is double ptr */
		return 1;
	if (*parent_node_dp == NULL) /* make sure there is single ptr */
		return 1;

	parent_node_ptr = *parent_node_dp; /* make new pointer to parent */

	if (parent_node_ptr->children == NULL) /* check if there is a child */
	{
		parent_node_ptr->children = create_child(data); /* make node */
		if (parent_node_ptr->children == NULL) /* error check */
			return 1;
		return 0;
	}

	list_ptr = parent_node_ptr->children; /* set pointer to child */
	while (list_ptr->next != NULL)	      /* traverse children */
		list_ptr = list_ptr->next;

	list_ptr->next = create_child(data);   /* make node */
	if (parent_node_ptr->children == NULL) /* error check */
		return 1;

	return 0;
}

/* find the correct parent to insert node; returns NULL if not found */
NTree *find_parent_node(NTree **tree, char **parents)
{
	int i;

	NTree *node_ptr;
	__attribute__((unused)) int depth;

	node_ptr = *tree;
	depth = string_array_size(parents);

	if (depth == 0)
		return node_ptr;

	for (i = 0; i < depth; i++)
	{
		printf("Repetitive\n");
		if (strcmp(node_ptr->str, parents[i]) == 0)
			printf("%s:Hello there!\n", parents[i]);
	}

	return node_ptr;
}

int string_array_size(char **parents)
{
	int i;
	char *str_ptr;

	if (parents == NULL)
		return 0;

	str_ptr = parents[0];

	if (parents[0] == NULL)
	{
		return 0;
	}

	for (i = 0; str_ptr != NULL; i++)
		str_ptr = parents[i+1];

	return i;
}

List *create_child(char *data)
{
	NTree *node;
	List *list;

	list = malloc(sizeof(List)); /* create list */
	if (list == NULL)	/* malloc check */
		return NULL;

	list->next = NULL;	/* initialize list members */
	list->node = NULL;

	node = malloc(sizeof(NTree)); /* create NTree node */
	if (node == NULL)	/* malloc check */
		return NULL;

	node->str = strdup(data); /* set 'str' member */
	if (node->str == NULL) 	/* strdup alloc check */
		return NULL;
	
	node->children = NULL;	/* initiliaze 'children' member */

	list->node = node;	/* link list to node */

	return list;
}
