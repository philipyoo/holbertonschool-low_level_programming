#include "lists.h"

/**
 * free_dlistint - free a `dlistint_t` doubly linked list
 * @head: head of LL
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *tmp, *hold;

	if (head == NULL)
		return;

	tmp = head;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		hold = tmp;
		tmp = tmp->next;
		free(hold);
	}
}
