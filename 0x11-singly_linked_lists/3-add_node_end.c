#include "lists.h"
#include <string.h>
#include <stdio.h>
/**
 * add_node_end - add a new node at the end of `list_t` list
 * @head: double pointer to head
 * @str: string to duplicate into new node
 * Return: Address of the new element or NULL if failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *current;
	list_t *new_node;
	char *dup_str;
	int c;

	current = *head;
	while (current && current->next != NULL)
		current = current->next;

	dup_str = strdup(str);
	for (c = 0; dup_str[c] != '\0'; c++)
		;

	new_node = malloc(sizeof(list_t));
	new_node->str = dup_str;
	new_node->len = c;
	new_node->next = NULL;
	if (new_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	if (current)
		current->next = new_node;
	else
		*head = new_node;
	return (new_node);
}
