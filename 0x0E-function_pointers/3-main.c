#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - main function
 * @argc: argument count
 * @argv: string of arguments in array
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int a, b, n;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != '*' &&
	    argv[2][0] != '/' && argv[2][0] != '%')
	{
		printf("argv: %c", argv[2][0]);
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	n = get_op_func(argv[2])(a, b);

	printf("%d\n", n);

	return (0);
}
