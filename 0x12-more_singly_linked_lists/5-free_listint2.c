#include "lists.h"

/**
 * free_listint2 - free a `listint_t` list
 * @head: double pointer to head
 */
void free_listint2(listint_t **head)
{
	listint_t *hold;

	hold = *head;
	while (hold->next != NULL)
	{
		*head = hold->next;
		free(hold);
		hold = *head;
	}
	free(*head);
	*head = NULL;
}
