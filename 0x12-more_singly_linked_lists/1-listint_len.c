#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * listint_len - returns number of items in a simple linked list.
 * @h: pointer to first simple linked list item
 *
 * Return: how many items in the simple linked list.
 */
size_t listint_len(const listint_t *h)
{
	/* Variable declarations */
	int ctr;

	/* Initializations */
	ctr = 0;

	while (h != NULL)
	{
		h = h->next;
		ctr++;
	}

	return (ctr);
}
