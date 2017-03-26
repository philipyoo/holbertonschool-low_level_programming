#include "binary_trees.h"

/**
 * binary_tree_levelorder - go through binary tree using level-order traversal
 * @tree: pointer to root of tree
 * @func: function pointer to use while traversing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, counter;

	if (tree == NULL || func == NULL)
		return;

	height = custom_binary_tree_height(tree);
	for (counter = 0; counter <= height; counter++)
		levelordering(tree, func, counter);
}

/**
 * levelordering - binary tree level ordering recursive helper function
 * @tree: node of a tree, initially the root
 * @func: function pointer to use at each level
 * @height: height of tree from current node
 */
void levelordering(const binary_tree_t *tree, void (*func)(int), int height)
{
	if (tree == NULL)
		return;
	else if (height == 0)
		func(tree->n);
	else
	{
		levelordering(tree->left, func, height - 1);
		levelordering(tree->right, func, height - 1);
	}
}

/**
 * custom_binary_tree_height - Measure height of a binary tree from given node
 * @tree: pointer to node of tree to measure
 * Description: Edited to work with balance factor function
 * Return: height of tree or -1 if NULL
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
