#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NTree *create_node(char *data);
List *create_list(void);
NTree **find_parent_node(NTree **tree, char **parents);

int ntree_insert(NTree **tree, __attribute__((unused)) char **parents, char *data)
{
	NTree **parent_node;
	List *list_ptr;
	list_ptr = NULL;

	parent_node = tree;

	/* code to find correct parent_node */

	if (*parent_node == NULL)	/* case 1 */
	{
		*parent_node = create_node(data);
		if (*parent_node == NULL) /* error check */
			return 1;
		(*parent_node)->children = create_list(); /* create list */
		if ((*parent_node)->children == NULL)	/* error check */
			return 1;
		printf("The root has been added\n");
		return 0;
	}

	list_ptr = (*parent_node)->children;

	while (list_ptr->next != NULL) /* traverse children list */
		list_ptr = list_ptr->next;
	
	list_ptr->next = create_list(); /* create list and insert */
	if (list_ptr->next == NULL) 	/* error check */
		return 1;
	
	list_ptr->next->node = create_node(data); /* create the node and insert */
	if (list_ptr->next->node == NULL) /* error check */
		return 1;

	printf("The node has been added\n");
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
