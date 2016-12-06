#include "holberton.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int temp;
	int shifts;

	if (n == 0)
	{
		printf("0");
		return;
	}

	/* shift over and count until == 0 */

	temp = n;
	shifts = 0;
	while ((temp >>= 1) > 0)
		shifts++;

	/* using >> shifts with decrementing powers, use & 1 */

	for (; shifts > 0; shifts--)
	{
		if ((n >> shifts) & 1)
		{
			printf("1");
		}
		else
			printf("0");
	}

	if (n & 1)
		printf("1");
	else
		printf("0");

}
