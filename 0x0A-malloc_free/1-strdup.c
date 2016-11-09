#include "holberton.h"
#include <stdlib.h>

/**
 * _strdup - Duplicate a string using malloc
 * @str: string to duplicate
 * Return: Pointer to a the new duped string
 */

char *_strdup(char *str)
{
	char *a;
	int i, c;

	for (i = 0; str[i] != '\0'; i++)
		;
	if (i == 0)
		return (NULL);

	a = malloc(i * sizeof(*a));
	if (a == NULL)
		return (NULL);

	for (c = 0; c < i; c++)
		a[c] = str[c];
	a[c] = '\0';

	return (a);
}
