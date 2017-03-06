#include "sort.h"
#include <stdio.h>

size_t swap(int *array, size_t size, size_t idx1, size_t idx2);
void partition(int *array, size_t size, size_t left, size_t right);

/**
 * quick_sort - Sort an array of integers in ascending order
 * Description: Use Hoare's partition scheme quicksort
 * pivot should always be the last element of the partition being sorted.
 * You're expected to print the array after each time you swap 2 elements.
 */
void quick_sort(int *array, size_t size)
{
	size_t lw, rw;

	lw = 0;
	rw = size - 1;

	partition(array, size, lw, rw);
}

void partition(int *array, size_t size, size_t left, size_t right)
{
	size_t i, j, pivot;

	printf("?");

	if (left >= right)
	{
		printf("Hi");
		return;
	}

	pivot = right;
	while (array[i] < array[pivot] && i < pivot)
		i++;

	if (i < right)
	{
		printf("A");
		pivot = swap(array, size, i, pivot);

		j = right - 1;
		while (i < j)
		{
			if (array[j] < array[pivot])
			{
				swap(array, size, i, j);
				i++;
			}
			j--;
		}
	}
	else
		pivot = i--;

	printf("B");

	swap(array, size, pivot, i - 1);

	partition(array, size, left, i - 2);
	partition(array, size, i, right);
}

size_t swap(int *array, size_t size, size_t idx1, size_t idx2)
{
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;

	print_array(array, size);

	return idx1;
}
