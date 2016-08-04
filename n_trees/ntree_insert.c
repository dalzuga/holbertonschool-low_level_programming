#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NTree *create_node(char *data);
List *create_list(void);
NTree *find_parent_node(NTree **tree, char **parents);
long unsigned int string_array_size(char **parents);
int ntree_insert_at_parent(NTree **tree, char *data);

int ntree_insert(NTree **tree, char **parents, char *data)
{
	NTree *parent_node_ptr;
	long unsigned int depth;
	long unsigned int i;
	parent_node_ptr = *tree;

	depth = string_array_size(parents);

	printf("path is \"");

	for (i = 0; i < depth; i++)
	{
		printf("%s ", parents[i]);
	}

	printf("\". data is: %s. size is: %lu\n", data, depth);

	if (depth == 0)
	{
		if (ntree_insert_at_parent(&parent_node_ptr, data) == 0)
		{
			*tree = parent_node_ptr;
			return 0;
		}
	}
	else
	{
		parent_node_ptr = find_parent_node(tree, parents);

		if (ntree_insert_at_parent(&parent_node_ptr, data) == 0)
			return 0;
	}	

	return 0;
}

int ntree_insert_at_parent(NTree **parent_node_dp, char *data)
{
	NTree *parent_node_ptr;
	List *list_ptr;
	list_ptr = NULL;
	parent_node_ptr = *parent_node_dp;

	if (parent_node_ptr == NULL)	/* case 1 */
	{
		*parent_node_dp = create_node(data);
		if (*parent_node_dp == NULL) /* error check */
			return 1;
		(*parent_node_dp)->children = create_list(); /* create list */
		if ((*parent_node_dp)->children == NULL)	/* error check */
			return 1;
		parent_node_ptr = *parent_node_dp;
		printf("The root has been added\n");
		return 0;
	}

	list_ptr = parent_node_ptr->children;

	while (list_ptr->next != NULL) /* traverse children list */
		list_ptr = list_ptr->next;
	
	list_ptr->next = create_list(); /* create list */
	if (list_ptr->next == NULL) 	/* error check */
		return 1;
	
	list_ptr->next->node = create_node(data); /* create the node */
	if (list_ptr->next->node == NULL) /* error check */
		return 1;

	

	printf("The node has been added\n");
	return 0;
}

/* find the correct directory folder to insert node; returns NULL if not found */
NTree *find_parent_node(NTree **tree, char **parents)
{
	NTree *node_ptr;
	long unsigned int depth;

	node_ptr = *tree;
	depth = string_array_size(parents);

	return node_ptr;
}

long unsigned int string_array_size(char **parents)
{
	long unsigned int i;
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
