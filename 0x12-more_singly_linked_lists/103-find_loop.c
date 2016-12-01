#include "lists.h"

/**
 * find_listint_loop - find the loop in a linked list
 * @head: head of linked list
 * Description: Not allowed to use malloc, free or arrays.
 * Can only declare a max of 2 variables.
 * Return: Address of node where loop starts, or NULL if no loop found.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hold;
	listint_t *current;

	current = head;
	while (current != NULL)
	{
		hold = current;
		current = current->next;

		if (hold < current)
			return (current);
	}

	return (NULL);
}
