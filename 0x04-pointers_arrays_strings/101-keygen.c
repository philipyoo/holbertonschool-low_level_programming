#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 125
#define MIN 1

int main(void)
{
	int myrand;
	int count;
	int total;

	for (count = 0, total = 2772; total > 122; count++)
	{
		myrand = (rand() % (MAX + 1 - MIN)) + MIN;
		printf("%c", myrand);
		total -= myrand;
	}
	printf("%c", total);

	return (0);
}
