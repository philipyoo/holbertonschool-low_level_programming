#include "holberton.h"

int halp(int c, int i);

/**
 * _sqrt_recursion - return the natural square root of a number
 * @n: int number
 * Return: If no natural square root, return -1. Else return natural square root
 */

int _sqrt_recursion(int n)
{
	return (halp(n, 1));
}

int halp(int c, int i)
{
	int square;

	square = i * i;
	if (square == c)
		return (i);
	else if (square < c)
		return (halp(c, i + 1));
	else
		return (-1);
}
