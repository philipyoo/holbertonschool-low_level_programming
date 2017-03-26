#include "binary_trees.h"

/**
 * binary_tree_is_avl - check if a binary tree is a valid AVL tree
 * @tree: pointer to root node of tree
 * Return: 1 if AVL tree, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int lheight, rheight;

	if (tree == NULL)
		return (0);

	lheight = custom_binary_tree_height(tree->left);
	rheight = custom_binary_tree_height(tree->right);

	if (abs(lheight - rheight) <= 1)
		return (binary_tree_is_bst(tree));
	return (0);
}

/**
 * custom_binary_tree_height - Measure the height
 * of a binary tree from a given node
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
