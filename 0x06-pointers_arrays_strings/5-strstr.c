#include "holberton.h"

/**
 * _strstr - locate a substring
 * @haystack: string
 * @needle: string substring
 * Return: Pointer to beginning of substring, or NULL if not found.
 */

char *_strstr(char *haystack, char *needle)
{
	char *p;
	int i;

	p = haystack;
	while (*p != '\0')
	{
		if (*p == *needle)
		{
			for (i = 1; needle[i] != '\0'; i++)
			{
				if (!(*(p + i) == needle[i]))
					break;
			}
			if (needle[i] == '\0')
				return (p);
		}
		p++;
	}

	return (p);
}
