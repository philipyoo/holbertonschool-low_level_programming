#include "holberton.h"

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned int greatest;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	greatest = 1;
	while (n >= (greatest * 2))
		greatest *= 2;

	for (; greatest > 0; greatest = greatest >> 1)
	{
		if (n >= greatest)
		{
			_putchar('1');
			n -= greatest;
		}
		else
			_putchar('0');
	}
}
