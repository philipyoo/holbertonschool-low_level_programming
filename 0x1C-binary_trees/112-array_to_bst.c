#include "binary_trees.h"

/**
 * array_to_bst - build a Binary Search Tree from an array
 * @array: array to convert to BST
 * @size: size of array
 * Return: pointer to root node, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0, root = NULL; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
