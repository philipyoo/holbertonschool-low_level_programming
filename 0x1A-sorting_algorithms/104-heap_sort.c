#include "sort.h"

/**
 * swap - swap two vars in array
 * @A: array
 * @a: 1st num
 * @b: 2nd num
 * @size: size of array
 */
void swap(int *A, int a, int b, size_t size)
{
	int tmp;

	tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
	print_array(A, size);
}
/**
 * swim - routine to build heap
 * @A: int* array being sorted
 * @i: index to swim
 * @size: size of the array
 */
void swim(int *A, int i, size_t size)
{
	while (A[i] > A[(i - 1) / 2])
	{
		if (A[i] < A[((i - 1) / 2) * 2 + 1] || A[i] < A[((i - 1) / 2) * 2 + 2])
			break;
		swap(A, i, (i - 1) / 2, size);
		i = (i - 1) / 2;
	}
}
/**
 * sink - routine to place items into place in heap
 * @A: int *array being sorted
 * @i: index to sink
 * @N: size of array
 * @size: size of the full array
 */
void sink(int *A, int i, int N, size_t size)
{
	while (N >= (i * 2) + 1)
	{
		if (i * 2 + 2 <= N && (A[i] < A[i * 2 + 1] || A[i] < A[i * 2 + 2]))
		{
			if (A[i * 2 + 1] > A[i * 2 + 2])
			{
				swap(A, i, i * 2 + 1, size);
				i = i * 2 + 1;
			}
			else
			{
				swap(A, i, i * 2 + 2, size);
				i = i * 2 + 2;
			}
		}
		else if (i * 2 + 1 <= N && A[i] < A[i * 2 + 1])
		{
			swap(A, i, i * 2 + 1, size);
			i = i * 2 + 1;
		}
		else
			break;
	}
}
/**
 * heap_sort - heapsort with sinkdown method
 * @array: int* array to sort
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, N;

	for (i = size - 1; i > 0; i--)
	{
		if (array[i] > array[(i - 1) / 2])
		{
			swim(array, i, size);
			sink(array, i, size, size);
		}
	}
	for (N = size - 1; N > 0;)
	{
		swap(array, 0, N, size);
		N--;
		sink(array, 0, N, size);
	}
}
