#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

/* pushes an item into a stack */
int push_stack(Stack **root, char *str)
{
	Stack *node_ptr;
	node_ptr = NULL;

	if (*root == NULL)	/* no nodes */
	{
		node_ptr = malloc(sizeof(Stack));
		node_ptr->str = strdup(str);
		node_ptr->next = NULL;
		*root = node_ptr;
		return 0;
	}

	node_ptr = *root;
	while (node_ptr->next != NULL)
	{
		node_ptr = node_ptr->next;
	}

	node_ptr->next = malloc(sizeof(Stack));
	node_ptr = node_ptr->next;
	node_ptr->str = strdup(str);
	node_ptr->next = NULL;

	return 0;
	
}
