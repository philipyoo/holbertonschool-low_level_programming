#include "lists.h"

/**
 * insert_dnodeint_at_idx - insert a new node at given position
 * @h: double pointer to head
 * @idx: index to insert into
 * @n: value to store in new node
 * Return: Address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_idx(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int c;
	dlistint_t *tmp, *prev, *new;

	tmp = *h;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	for (c = 1; tmp && c < idx; c++, tmp = tmp->next)
		prev = tmp;
	if (idx == 0)
	{
		*h = new;
		new->prev = NULL;
		new->next = (tmp == NULL) ? NULL : tmp;
		return (new);
	}
	if (idx == c && tmp == NULL)
	{
		if (prev != NULL)
		{
			new->prev = prev;
			new->next = NULL;
			prev->next = new;
			return (new);
		}
		return (NULL);
	}
	else if (idx != c && tmp == NULL)
		return (NULL);
	prev = tmp;
	tmp = tmp->next;
	new->prev = prev;
	new->next = tmp;
	prev->next = new;
	tmp->prev = new;

	return (new);
}
