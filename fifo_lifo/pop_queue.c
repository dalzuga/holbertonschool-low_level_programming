#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

char *pop_queue(Queue **root)
{
	Queue *node_ptr;
	char *str;
	node_ptr = NULL;

	if (*root == NULL)
		return NULL;

	node_ptr = *root;
	str = node_ptr->str;
	*root = (*root)->next;
	free(node_ptr);
	return str;
}
