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
	int tmp, trigger = 0;
        size_t b = 0;
	size_t i;

	if (array == NULL || size == 0)
		return (-1);
	size--;
	while (b <= size)
	{
		printf("Searching in array: ");
		for (i = b; i <= size; i++)
		{
			printf("%d", array[i]);
			if (i < size)
				printf(", ");
		}
		printf("\n");

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

		if (trigger)
			break;
		if ((int)(size - b) < 0)
			trigger = 1;
	}
	return (-1);
}
