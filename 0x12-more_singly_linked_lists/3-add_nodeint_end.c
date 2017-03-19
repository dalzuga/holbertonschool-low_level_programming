#include "lists.h"
#include <stdlib.h>

/**
 * add_nodeint_end - adds a node to the end of a simple linked list.
 * @head: pointer to pointer to first simple linked list node.
 * @n: value held at new node
 *
 * Return: address of new element.
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	/* Variable declarations */
	listint_t *node, *tmp_ptr;

	/* Memory allocations */
	node = malloc(sizeof(listint_t));

	/* Check for memory error */
	if (node == NULL)
	{
		return (NULL);
	}

	/* Initializations */
	node->n = n;
	node->next = NULL;
	tmp_ptr = NULL;

	/* Check for case where there is no ll */
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}

	tmp_ptr = *head;

	/* Traverse the simple linked list */
	while (tmp_ptr->next != NULL)
	{
		tmp_ptr = tmp_ptr->next;
	}

	/* Append our node at the end */
	tmp_ptr->next = node;

	return (node);
}
