#include "holberton.h"

/**
 * _pow_recursion - return the value of `x` raised to power of `y`
 * @x: number value
 * @y: number power
 * Return: x to power of y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else if (y == 1)
		return (x);

	return (x * _pow_recursion(x, y - 1));
}
