#include <stdio.h>

/**
 * main - main block
 * Description: Print the first 50 fibonacci numbers, starting with 1 and 2.
 * Numbers must be coma and space separated.
 * Return: 0
 */
int main(void)
{
	int count = 2;
	unsigned long long int i = 1, j = 2;
	unsigned long long int k;

	printf("%llu, ", i);
	while (count <= 50)
	{
		if (count == 50)
		{
			printf("%llu\n", j);
		}
		else
		{
			printf("%llu, ", j);
		}

		k = j;
		j += i;
		i = k;
		count++;
	}
}
