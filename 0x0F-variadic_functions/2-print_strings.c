#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - print a string followed by a newline
 * @separator: string to be printed between strings
 * @n: number of strings passed to function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list list;

	if (separator == NULL)
		return;

	va_start(list, n);
	for (i = 0; i < n; i++)
	{
		printf("%s", va_arg(list, char*));
		if (i != (n - 1))
			printf("%s", separator);
	}
	printf("\n");

	va_end(list);
}
