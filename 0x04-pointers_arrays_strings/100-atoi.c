#include "holberton.h"

/**
 * _atoi - Convert a string to integer.
 * @s: char array string
 * Description: Number in the string can be preceded by an infinite
 * number of characters.
 * You need to take into account all -/+ signs before the number.
 * If there are no numbers in the string, return 0.
 * No need to check for overflow.
 * Not allowed to use `long` type.
 * Not allowed to declare new variables of "type" array.
 * Not allowed to hard-code special values.
 * Return: first integer found in string
 */

int _atoi(char *s)
{
	int i;
	int h, p;

	h = 0;
	p = 1;
	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] == '-')
			p *= -1;

		if (s[i] > 47 && s[i] < 58)
		{
			if (h > 0)
				h = (h * 10) + (s[i] - '0');
			else
				h = (s[i] - '0');

			if (s[i + 1] < 48 || s[i + 1] > 57)
				break;
		}
	}
	if (p < 0)
		h *= -1;

	return (h);
}
