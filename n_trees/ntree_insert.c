#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NTree *create_node(char *data);
List *create_list(void);
int ntree_insert(List **list, __attribute__((unused)) char **parents, char *data);

int ntree_insert(NTree **tree, __attribute__((unused)) char **parents, char *data)
{
	List *list_ptr;
	list_ptr = NULL;

	if (*tree == NULL)	/* case 1 */
	{
		*tree = create_node(data);
		if (*tree == NULL) /* error check */
			return 1;
		return 0;
	}

	list_ptr = (*tree)->children; /* case 2 */
	while (list_ptr->next != NULL) /* traverse children list */
		list_ptr = list_ptr->next;
	
	list_ptr = create_list(); /* case 3: insert */
	if (list_ptr == NULL) 	/* error check */
		return 1;
	
	list_ptr->node = create_node(data); /* create the node to insert */
	if (list_ptr->node == NULL) /* error check */
		return 1;

	
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
