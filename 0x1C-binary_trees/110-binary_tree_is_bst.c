#include "binary_trees.h"

/**
 * binary_tree_is_bst - Check if a binary tree is a valid binary search tree
 * @tree: pointer to root node of tree to check
 * Return: 1 if valid BST, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bst_lesser(tree->left, tree->n) &&
		bst_greater(tree->right, tree->n));
}

/**
 * bst_lesser - BST validator helper function lesser
 * @node: node to compare
 * @val: value to compare with
 * Return: 1 if valid BST, else 0
 */
int bst_lesser(const binary_tree_t *node, int val)
{
	if (node == NULL)
		return (1);
	if (node->n >= val)
		return (0);

	return (bst_lesser(node->left, val) &&
		bst_lesser(node->right, val));
}

/**
 * bst_greater - BST validator helper function greater
 * @node: node to compare
 * @val: value to compare with
 * Return: 1 if valid BST, else 0
 */
int bst_greater(const binary_tree_t *node, int val)
{
	if (node == NULL)
		return (1);
	if (node->n <= val)
		return (0);

	return (bst_greater(node->left, val) &&
		bst_greater(node->right, val));
}
