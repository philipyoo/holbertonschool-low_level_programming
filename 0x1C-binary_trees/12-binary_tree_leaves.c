#include "binary_trees.h"
/**
 *binary_tree_leaves - Function that counts how many leaves are in the tree
 *@tree: The tree to be evaluated
 *Return: The addition of both sides of the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left, right;

	left = right = 0;
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	left = binary_tree_leaves(tree->left);
	right = binary_tree_leaves(tree->right);
	return (left + right);
}
