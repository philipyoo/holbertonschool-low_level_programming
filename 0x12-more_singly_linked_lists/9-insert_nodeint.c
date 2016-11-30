#include "lists.h"

/**
 * insert_nodeint_at_index - insert a new node at a given position
 * @head: double pointer to head
 * @index: insert node at this index, starting count at 0
 * @n: value to store in node
 * Return: Address of new node or NULL if failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int index, int n)
{
	listint_t *new;
	listint_t *current;
	unsigned int count;

	current = *head;
	for (count = 1; current && count < index; count++)
		current = current->next;
	if (current == NULL)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;

	if (current->next)
		new->next = current->next;
	else
		new->next = NULL;
	current->next = new;

	return (new);
}
