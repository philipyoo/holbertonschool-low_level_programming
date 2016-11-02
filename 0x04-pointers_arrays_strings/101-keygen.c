#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int myrand;
	int count;
	int total;

	for (count = 0, total = 2772; total > 122; count++)
	{
		srand(time(NULL));
		myrand = (rand() % 122) + 1;
		printf("%c", myrand);
		total -= myrand;
	}
	printf("%c", total);

	return (0);
}
