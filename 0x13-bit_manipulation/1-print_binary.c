#include "holberton.h"
#include <stdio.h>

/**
 * print_binary - print binary representation of a number
 * @n: decimal number to print as binary
 */
void print_binary(unsigned long int n)
{
	unsigned long int greatest;

	if (n == 0)
	{
		printf("0");
		return;
	}

	greatest = n >> 1;

	printf("1");
	for (; greatest > 0; greatest >>= 1)
	{
		if (greatest > 1)
		{
			if (greatest & 1)
				printf("1");
			else
				printf("0");
		}
	}

	if (n & 1)
		printf("1");
	else
		printf("0");
}
