#include "holberton.h"

/**
 * is_prime_number - determine if a number is a prime number
 * @n: int number
 * Return: 1 if prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n < 2)
		return (0);
	if (n < 4)
		return (1);
	return (hai(n, 2));
}

/**
 * _sqrt - return square root of number
 * @x: number
 * @i: number incrementer acting as divisor
 * Return: square root of `x`
 */

int _sqrt(int x, int i)
{
	int square;

	square = i * i;
	if (square >= x)
		return (i);
	else
		return (_sqrt(x, i + 1));
}

/**
 * hai - helper function, recursive steps taken
 * @n: number given to original function is_prime_number
 * @d: incrementer divisor
 * Return: 0 if not prime, 1 if prime
 */

int hai(int n, int d)
{
	if (n % d == 0)
		return (0);
	else if (_sqrt(n, 1) < d)
		return (1);
	else
		return (hai(n, d + 1));
}
