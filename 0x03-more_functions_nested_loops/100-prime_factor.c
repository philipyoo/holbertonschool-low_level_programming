#include <stdio.h>

/**
 * main - main block
 * Description: Find and print the largest prime factor of the number
 * 612852475143
 */
int main(void)
{
}

/**
 * _isprime - determines if a number is prime
 * @c: number to test
 * Return: 1 if true, 0 if false
 */
int _isprime(int c)
{
	int count; /* count all factors */
	int i; /* incrementer to divide with */

	count = 0;
	i = 2;
	while (i < c)
	{
		if (count > 1)
			break;

		if (c % i == 0)
			count++
	}

	if (count == 0)
		return (1);
	else
		return (0);
}
