#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint - adds a node to the beginning of a simple linked list.
 * @head: pointer to pointer first simple linked list node.
 *
 * Return: address of new element.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	/* Variable declarations */
	listint_t *node;

	/* Memory allocations */
	node = malloc(sizeof(listint_t));

	/* Initializations */
	node->n = n;
	node->next = *head;

	if (node == NULL)
	{
		return (NULL);
	}

	*head = node;

	return (node);
}
