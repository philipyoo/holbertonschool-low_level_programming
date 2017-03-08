#include "binary_trees.h"

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * @tree: pointer to root node of tree to check
 * Return: 1 if binary tree is perfect, else return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left, right, size, pow;

	if (tree == NULL)
		return (0);

	left = custom_binary_tree_height(tree->left);
	right = custom_binary_tree_height(tree->right);
	size = binary_tree_size(tree);

	if (size == 1)
		return (1);
	if (left >= 0 && right >= 0 && left == right)
	{
		pow = get_power(left + 1);

		if (pow - 1 == size)
			return (1);
	}

	return (0);
}

/**
 * custom_binary_tree_height - Measure height of a binary tree from given node
 * @tree: pointer to node of tree to measure
 * Description: Edited to work with balance factor function
 * Return: height of tree or 0 if NULL
 */
int custom_binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (-1);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left = custom_binary_tree_height(tree->left) + 1;
	right = custom_binary_tree_height(tree->right) + 1;

	if (left > right)
		return (left);
	else
		return (right);
}

/**
 * binary_tree_size - measure the size of a binary tree from a given node
 * @tree: root node of tree to measure from
 * Return: size of tree from a given node
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count;

	if (tree == NULL)
		return (0);

	count = binary_tree_size(tree->left) + 1;
	count += binary_tree_size(tree->right);

	return (count);
}

/**
 * get_power - get the power of 2 for a given number
 * @exp: exponent
 * Return: power of 2 for given exponent
 */
int get_power(int exp)
{
	int pow, i;

	for (i = 0, pow = 1; i <= exp; i++)
		pow *= 2;

	return (pow);
}
