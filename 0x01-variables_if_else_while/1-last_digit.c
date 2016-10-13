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

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	if (abs(n % 10) > 0 && abs(n % 10) < 6)
		printf("Last digit of %i is %i and is less than 6 and not 0\n",
		       n, abs(n % 10));
	else if (abs(n % 10) > 5)
		printf("Last digit of %i is %i and is greater than 5\n",
		       n, abs(n % 10));
	else
		printf("Last digit of %i is %i and is 0\n", n, abs(n % 10));

	return (0);
}
