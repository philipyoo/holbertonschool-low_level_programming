#include "sort.h"

/**
 * get_head - Get the head of a doubly linked list
 * @tmp: node in linked list
 * Return: head of linked list
 */
listint_t *get_head(listint_t *tmp)
{
	while (tmp->prev)
		tmp = tmp->prev;

	return (tmp);
}
