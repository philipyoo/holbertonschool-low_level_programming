#include "lists.h"

/**
 * insert_dnodeint_at_idx - insert a new node at given position
 * @h: double pointer to head
 * @index: index to insert into
 * @n: value to store in new node
 * Return: Address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_idx(dlistint_t **h, unsigned int index, int n)
{
	unsigned int c;
	dlistint_t *tmp, *hold, *new;

	tmp = *h;
	for (c = 0; tmp && c < idx - 1; c++)
		tmp = tmp->next;
	if (tmp == NULL || c < idx - 1)
		return (NULL);

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	hold = tmp->next;
	new->n = n;
	new->prev = tmp;
	tmp->next = new;
	if (hold == NULL)
		new->next = NULL;
	else
	{
		new->next = hold;
		hold->prev = new;
	}

	return (new);
}
