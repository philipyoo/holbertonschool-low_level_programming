#include <stdio.h>
/**
 * main - main block
 * Description: Use `putchar` to print lowercase alphabet 10 times.
 * Return: 0
 */
int main(void)
{
	char c;
	int i;

	for (i = 0; i < 10; i++)
	{
		for (c = 'a'; c <= 'z'; c++)
		{
			putchar(c);
		}
		putchar('\n');
	}

	return (0);
}
