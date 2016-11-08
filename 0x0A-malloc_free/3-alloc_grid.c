#include "holberton.h"
#include <stdlib.h>

/**
 * alloc_grid - create a 2d integer grid using malloc.
 * Description: Each element of the grid should be initialized to 0.
 * @width: int size width
 * @height: int size height
 * Return: Pointer to new grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i;

	grid = (int **) malloc(width * sizeof(*grid));

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < width; i++)
		grid[i] = malloc(height * sizeof(**grid));

	return (grid);
}
