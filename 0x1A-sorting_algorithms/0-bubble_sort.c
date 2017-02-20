#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order
 * using bubble sort algorithm.
 * @array: array of integers to sort
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, swapped;
	int tmp;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}
