#include "sort.h"

/**
 * shell_sort - sort an array of integers in ascending order
 * @array: array of integers
 * @size: size of array of integers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;

	if (size == 0 || array == NULL)
		return;

	gap = 1;
	while ((gap * 3 + 1) < size)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		insertion_sort(array, (int)size, (int)gap);
		print_array(array, size);
	}
}

/**
 * insertion_sort - sort an array of integers based on a gap for shell sort
 * @array: array of integers
 * @size: size of array of integers
 * @diff: gap given by shell sort
 */
void insertion_sort(int *array, int size, int diff)
{
	int i, j, hold;

	for (i = diff; i < size; i++)
	{
		for (j = i; j - diff >= 0; j -= diff)
		{
			if (array[j] < array[j - diff])
			{
				hold = array[j];
				array[j] = array[j - diff];
				array[j - diff] = hold;
			}
			else
				break;
		}
	}
}
