#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint - prints a simple linked list.
 *
 * @h: pointer to first simple linked list iteml
 *
 * Return: how many items in the simple linked list.
 */
size_t print_listint(const listint_t *h)
{
	/* Variable declarations */
	int ctr;

	/* Initializations */
	ctr = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);

		h = h->next;
		ctr++;
	}

	return (ctr);
}
