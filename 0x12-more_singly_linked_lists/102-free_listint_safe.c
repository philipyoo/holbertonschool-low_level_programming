#include "lists.h"

/**
 * free_listint_safe - free a `listint_t` list and set the head to null
 * @h: double pointer to head of linked list
 * Description: This function should work for circular lists
 * Only loop through the list once
 * Return: size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *hold;
	size_t count;

	count = 0;
	current = *h;
	while (current != NULL)
	{
		count++;
		hold = current;
		current = current->next;
		free(hold);

		if (hold < current)
			break;
	}
	*h = NULL;

	return (count);
}
