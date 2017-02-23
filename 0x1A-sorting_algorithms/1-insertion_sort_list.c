#include "sort.h"

/**
 * insertion_sort_list - Sort a doubly linked list of integers
 * in ascending order using insertion sort algorithm.
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *hold, *ptmp;

	if (list == NULL)
		return;
	tmp = get_head(*list);

	for (tmp = tmp->next; tmp;)
	{
		hold = tmp->next;
		while (tmp->prev && tmp->n < tmp->prev->n)
		{
			ptmp = tmp->prev;
			ptmp->next = tmp->next;
			tmp->prev = ptmp->prev;
			ptmp->prev = tmp;
			tmp->next = ptmp;
			if (ptmp->next)
				ptmp->next->prev = ptmp;
			if (tmp->prev)
				tmp->prev->next = tmp;
			print_list(get_head(*list));
		}
		tmp = hold;
	}

}
