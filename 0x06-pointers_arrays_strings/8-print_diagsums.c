#include "holberton.h"
#include <stdio.h>
/**
 * print_diagsums - Print the sum of the 2 diagonals of a square matrix of ints
 * @a: 2d array of int types
 * @size: size of array (square)
 */

void print_diagsums(int *a, int size)
{
	int i, sum, sizer;

	if (size == 0)
	{
		printf("0, 0");
		return;
	}
	else if (size == 1)
	{
		printf("%d, %d", a[0], a[0]);
		return;
	}

	i = 0;
	sum = 0;
	sizer = size * size;
	while (i < sizer)
	{
		if (i % (size + 1) == 0)
			sum += a[i];
		i++;
	}
	printf("%d, ", sum);

	sum = 0;
	i = 0;
	while (i < sizer)
	{
		if (i % (size - 1) == 0 && i != (sizer - 1))
			sum += a[i];
		i++;
	}
	printf("%d\n", sum);
}
