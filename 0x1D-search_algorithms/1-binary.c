#include "search_algos.h"

/**
 * binary_search - binary search a ascending sorted array to find a value.
 * No duplicates in array. Must print subarray each split.
 * @array: pointer to first element in array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: index of matched value in array or -1 if error or not found
 */
int binary_search(int *array, size_t size, int value)
{
	int tmp;
	size_t b = 0;

	if (array == NULL || size == 0)
		return (-1);
	size--;
	while (b <= size)
	{
		print_array(array, b, size);

		tmp = (size - b) / 2 + b;
		if (array[tmp] == value)
			return (tmp);
		else if (array[tmp] < value)
		{
			if (size % 2 == 1)
				b = tmp + 1;
			else
				b = tmp;
		}
		else
		{
			if (size % 2 == 1)
				size = tmp;
			else
				size = tmp - 1;
		}
	}
	return (-1);
}

/**
 * print_array - print the current array given rules on format
 * @array: array to print
 * @inc: starting incrementer index
 * @size: increment up to this size
 */
void print_array(int *array, size_t inc, size_t size)
{
	printf("Searching in array: ");
	for (; inc <= size; inc++)
	{
		printf("%d", array[inc]);
		if (inc < size)
			printf(", ");
	}
	printf("\n");
}
