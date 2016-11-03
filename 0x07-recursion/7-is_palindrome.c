#include "holberton.h"

/**
 * is_palindrome - check if a string is a palindrome
 * @s: char array string
 * Return: 1 if palindrome, 0 if not
 */

int is_palindrome(char *s)
{
	int length;

	length = get_length(s) - 1;
	if (length == 0)
		return (0);

	return (my_pal(s, --length));
}

/**
 * get_length - gets length of string
 * @s: string
 * Return: return length of string
 */

int get_length(char *s)
{
	if (*s == '\0')
		return (1);
	else
		return (1 + get_length(++s));
}

/**
 * my_pal - recursive check of palindrome
 * @s: string
 * @l: length of string
 * Return: 1 if palindrome, 0 if not
 */

int my_pal(char *s, int l)
{
	if (*s == *(s + l))
	{
		my_pal(s++, l - 1);
		return (1);
	}
	else
		return (0);
}
