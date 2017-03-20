#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_listint2 - frees a simple linked list and zeroes its head.
 * @head: pointer to pointer to first simple linked list node.
 *
 * Return: void.
 */
void free_listint2(listint_t **head)
{
	/* vars */
	listint_t *tmp_ptr, **arr;
	size_t list_len, i;

	/* inits */
	arr = NULL;
	tmp_ptr = *head;

	/* special case */
	if (head == NULL)
	{
		return;
	}

	/* special case */
	if (*head == NULL)
	{
		head = NULL;
		return;
	}
	
	list_len = listint_len(tmp_ptr);
	arr = malloc(sizeof(listint_t *) * list_len);
	
	/* store node addresses in arr */
	for (i = 0; i < list_len; i++)
	{
		*(arr + i) = tmp_ptr;
		tmp_ptr = tmp_ptr->next;
	}

	/* free all nodes */
	for (i = 0; i < list_len; i++)
	{
		free(*(arr + i));
	}

	/* free arr */
	free(arr);
	*head = NULL;
}

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
