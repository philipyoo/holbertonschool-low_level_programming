#include "holberton.h"

/**
 * _strpbrk - Search a string for any of a set of bytes.
 * @s: string
 * @accept: string to match
 * Return: Pointer to the byte in `s` that matches one of the bytes in `accept`
 * or NULL if no such byte is found.
 */

char *_strpbrk(char *s, char *accept)
{
	char *p;
	int j;

	p = s;
	while (*p != '\0')
	{
		j = 0;
		while (accept[j] != '\0')
		{
			if (accept[j] == *p)
			{
				return (p);
			}
			j++;
		}
		p++;
	}

	return (p);
}
