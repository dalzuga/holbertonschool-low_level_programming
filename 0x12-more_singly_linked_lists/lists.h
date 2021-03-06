#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* print_listint - prints a simple linked list. */
size_t print_listint(const listint_t *h);

/* listint_len - returns number of items in a simple linked list. */
size_t listint_len(const listint_t *h);

/* add_nodeint - adds a node to the beginning of a simple linked list. */
listint_t *add_nodeint(listint_t **head, const int n);

/* add_nodeint_end - adds a node to the end of a simple linked list. */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* free_listint - frees a simple linked list. */
void free_listint(listint_t *head);

/* free_listint2 - frees a simple linked list and zeroes its head. */
void free_listint2(listint_t **head);
