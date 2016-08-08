#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

/* print the first node, and remove it from the queue */
char *pop_queue(Queue **root)
{
	Queue *node_ptr;
	char *str;

	if (*root == NULL)
		return NULL;

	str = (*root)->str;
	node_ptr = *root;
	*root = (*root)->next;
	free(node_ptr);
	return str;
}
