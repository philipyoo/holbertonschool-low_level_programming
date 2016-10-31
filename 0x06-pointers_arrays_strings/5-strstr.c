#include "holberton.h"

/**
 * _strstr - locate a substring
 * @haystack: string
 * @needle: string substring
 * Return: Pointer to beginning of substring, or NULL if not found.
 */

char *_strstr(char *haystack, char *needle)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j + c] != '\0' && haystack[i + c] != '\0')
			{
				if (haystack[i + c] != needle[j + c])
					break;
				c++;
			}
			if (needle[j + c] == '\0')
				return (&haystack[i]);
		}
		j++;
		i++;
	}

	return (0);
}
