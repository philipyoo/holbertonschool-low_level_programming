#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - main block
 * Description: something
 * Return: 0
 */
int main(void)
{
	int n;
	int m;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	m = abs(n % 10);

	if (m > 0 && m < 6)
		printf("Last digit of %i is %i and is less than 6 and not 0\n",
		       n, m);
	else if (m > 5)
		printf("Last digit of %i is %i and is greater than 5\n", n, m);
	else
		printf("Last digit of %i is %i and is 0\n", n, m);

	return (0);
}
