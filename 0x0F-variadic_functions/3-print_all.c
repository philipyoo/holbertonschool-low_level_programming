#include "variadic_functions.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _findlast - find the last valid type in `format`
 * @format: string of formats passed from main function
 * Result: return index of last valid type
 */
int _findlast(const char * const format)
{
	unsigned int i, last;

	i = 0, last = 0;
	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
		case 'i':
		case 'f':
		case 's':
			last = i;
			break;
		}
		i++;
	}
	return (last);
}

/**
 * print_all - print anything passed if char, int, float, or string.
 * @format: string of formats to use and print
 */
void print_all(const char * const format, ...)
{
	unsigned int i, on, last;
	va_list args;
	char *str;

	last = _findlast(format);
	i = 0, on = 0;
	va_start(args, format);
	while (format[i] != '\0' || i < last)
	{
		if (on && i <= last)
			printf(", ");
		on = 0;
		switch (format[i])
		{
		case 'c':
			printf("%c", va_arg(args, int));
			on = 1;
			break;
		case 'i':
			printf("%d", va_arg(args, int));
			on = 1;
			break;
		case 'f':
			printf("%f", va_arg(args, double));
			on = 1;
			break;
		case 's':
			str = va_arg(args, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s", str);
			on = 1;
			break;
		}
		i++;
	}
	printf("\n");
	va_end(args);
}
