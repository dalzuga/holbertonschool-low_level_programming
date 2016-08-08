#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

/* pushes an item into a queue */
int push_queue(Queue **root, char *str)
{
	Queue *node_ptr;
	node_ptr = NULL;

	if (*root == NULL)	/* no nodes */
	{
		node_ptr = malloc(sizeof(Queue));
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

	node_ptr->next = malloc(sizeof(Queue));
	node_ptr = node_ptr->next;
	node_ptr->str = strdup(str);
	node_ptr->next = NULL;

	return 0;
}
