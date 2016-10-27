#include "holberton.h"

/**
 * cap_string - capitalize all words of a string
 * @str: string
 * Return: `str`
 */

char *cap_string(char *str)
{
	int i, c;
	int trigger;
	char nots[] = ",;.!?(){}\n\t\" ";

	for (i = 0, trigger = 0; str[i] != '\0'; i++)
	{
		for (c = 0; nots[c] != '\0'; c++)
		{
			if (nots[c] == str[i])
				trigger = 1;
		}

		if (trigger)
		{
			if (str[i] > 96 && str[i] < 123)
			{
				str[i] -= 32;
				trigger = 0;
			}
			else if (str[i] > 64 && str[i] < 91)
				trigger = 0;
			else if (str[i] > 47 && str[i] < 58)
				trigger = 0;
		}

		if (str[i] == '\t')
			str[i] = ' ';
	}
	return (str);
}
