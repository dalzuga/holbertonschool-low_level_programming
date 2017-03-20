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
	/* Variable declarations */
	listint_t *tmp_ptr, *trl_ptr;

	/* Initializations */
	tmp_ptr = *head;
	trl_ptr = NULL;

	/* ll is empty */
	if (*head == NULL)
	{
		head = NULL;
		return;
	}

	/* ll has one item */
	if ((*head)->next == NULL)
	{
		free(*head);
		*head = NULL;
		head = NULL;
		return;
	}

	/* Traverse ll */
	while (tmp_ptr->next != NULL)
	{
		trl_ptr = tmp_ptr;
		tmp_ptr = tmp_ptr->next;
	}

	/* Delete reference to next in trailing node */
	trl_ptr->next = NULL;
	free(tmp_ptr);
	tmp_ptr = NULL;

	free_listint2(head);
}
