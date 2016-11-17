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
	int a, b;
	int (*operate)(int, int);

	if (argc != 4 && argv[2][0] != '*')
	{
		printf("Error\n");
		exit(98);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);

	operate = get_op_func(argv[2]);
	if (operate == NULL)
	{
		printf("Error\n");
		exit(99);
	}
	else
		printf("%d\n", operate(a, b));
	return (0);
}
