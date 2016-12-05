#include "holberton.h"
#include <stdio.h>
/**
 * get_bit - get the value of a bit at a given index
 * @n: number to evaluate
 * @index: index starting from 0, of the bit we want to get
 * Return: Value of bit at index, or -1 if error
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int hold;

	if (n < 0 || index < 0)
		return (-1);

	hold = n >> index;
	if (hold

	return (hold & 1);
}
