#include "lists.h"

/**
 * add_nodeint - add a new node at the beginning of a `listint_t` list
 * @head: double pointer to head node
 * @n: int value to store in new node
 * Return: Address of new element or NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *hold;
	listint_t *new;

	hold = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	*head = new;

	if (hold == NULL)
		new->next = NULL;
	else
		new->next = hold;

	return (new);
}
