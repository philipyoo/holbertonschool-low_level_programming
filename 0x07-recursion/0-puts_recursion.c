#include "holberton.h"

/**
 * _puts_recursion - Print a string
 * @s: string
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
		_putchar('\n');
	else
	{
		_putchar(*s);
		_puts_recursion(++s);
	}
}
