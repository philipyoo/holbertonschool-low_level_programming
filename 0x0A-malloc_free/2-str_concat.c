#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * str_concat - concatenate two strings using malloc
 * @s1: string 1
 * @s2: string 2
 * Return: pointer to concat string
 */

char *str_concat(char *s1, char *s2)
{
	char *a;
	int i, j, c, d;

	if (s1 == NULL && s2 == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;

	a = malloc((i * sizeof(*s1)) + (j * sizeof(*s2)) + 1);
	if (a == NULL)
		return (NULL);

	for (c = 0, d = 0; c < (i + j + 1) && s2[d] != '\0'; c++)
	{
		if (c < i)
			a[c] = s1[c];
		else
			a[c] = s2[d++];
	}
	a[c] = '\0';

/*	for (i = 0; a[i] != '\0'; i++)
	{
		printf("%d: %c\n", i, a[i]);
	}
	printf("%d, %lu ", i, ((i * sizeof(*s1)) + (j * sizeof(*s2)) + 1));
*/

	return (a);
}
