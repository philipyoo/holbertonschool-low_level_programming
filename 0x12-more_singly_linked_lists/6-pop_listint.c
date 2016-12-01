#include "lists.h"

/**
 * pop_listint - Delete the head node of a `listint_t` linked list
 * @head: double pointer to head node of linked list
 * Return: head nodes data `n`
 */
int pop_listint(listint_t **head)
{
	int num;
	listint_t *hold;

	if (head == NULL)
		return (0);

	hold = *head;
	if (hold->n)
		num = hold->n;
	else
		num = 0;
	*head = hold->next;
	free(hold);

	return (num);
}
