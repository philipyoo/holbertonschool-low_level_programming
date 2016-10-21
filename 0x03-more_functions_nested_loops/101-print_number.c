#include "holberton.h"

/**
 * print_number - Function that prints an integer.
 * @n: int type number
 * Description: Can only use _putchar to print.
 */
void print_number(int n)
{
	int m; /* power of 10 */
	int c; /* boolean check */

	/* negatives */
	if (n < 0)
	{
		n *= -1;
		_putchar('-');
	}

	/* count up */
	m = 1;
	c = 1;
	while (c)
	{
		if (n / (m * 10) > 0)
			m *= 10;
		else
			c = 0;
	}

	/* count down */
	while (n >= 0)
	{
		if (m == 1)
		{
			_putchar(n % 10 + '0');
			n = -1;
		}
		else
		{
			_putchar((n / m % 10) + '0');
			m /= 10;
		}
	}
}
