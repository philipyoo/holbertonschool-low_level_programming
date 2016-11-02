#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int myrand;
	int count;
	int total;

	for (count = 0, total = 2772; total > 122; count++)
	{
		myrand = (rand() % 122) + 1;
		printf("%c", myrand);
		total -= myrand;
	}
	printf("%c", total);

	printf("\n");

	return (0);
}
