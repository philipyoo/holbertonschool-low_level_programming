#include "holberton.h"

/**
 * _strspn - search a string for a set of bytes
 * @s: char string array
 * @accept: char array to check bytes with
 * Return: Number of bytes in the intial segment of `s`
 */

unsigned int _strspn(char *s, char *accept)
{
	int i;
	int j;
	int max;

	i = 0;
	max = 0;

	while (accept[i] != '\0')
	{
		j = 0;
		while (s[j] != '\0')
		{
			if (accept[i] == s[j])
			{
				if (j > max)
				{
					max = j;
				}
				break;
			}
			j++;
		}
		i++;
	}

	return (max + 1);
}
