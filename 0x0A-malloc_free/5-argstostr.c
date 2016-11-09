#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * argstostr - concatenate all arguments of your program with newline
 * @ac: argument count
 * @av: double pointer to array of strings passed to main
 * Return: Null if fail, else return pointer to new string
 */

char *argstostr(int ac, char **av)
{
	char *a;
	int i, j, total, d;

	total = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; *(*(av + i) + j) != '\0'; j++, total++)
			;
	}

	a = malloc(total + ac + 30);
	if (a == NULL)
		return (NULL);

	d = j = 0;
	for (i = 0; i < ac; i++)
	{
		d += j;
		for (j = 0; *(*(av + i) + j) != '\0'; j++)
			a[j + d] = *(*(av + i) + j);
		a[j + d++] = '\n';
	}

	return (a);
}
