#include "holberton.h"
#include <stdio.h>
/**
 * print_number - Print an integer using only _putchar
 * @n: integer to print
 */

void print_number(int n)
{
	int power;
	int neg;
	int hold;

	neg = 0;
	power = 1;
	hold = n;
	if (n < 0)
	{
		_putchar('-');
		neg = 1;
	}

	while (hold > 9 || hold < -9)
	{
		power *= 10;
		hold /= 10;
	}

	while (power > 0)
	{
		if (power > 9)
		{
			if (!neg)
				_putchar((n / power % 10) + '0');
			else
				_putchar((n / power % 10) * -1 + '0');

			power /= 10;
		}
		if (power == 1)
		{
			if (neg)
				_putchar((n % 10) * -1 + '0');
			else
				_putchar(n % 10 + '0');
			power = 0;
		}
	}
}
