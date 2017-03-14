#include "binary_trees.h"

/**
 * bst_remove - Remove a node from a Binary Search Tree
 * The deleted node must be replaced with its first in-order successor.
 * @root: root node
 * @value: value in node to look for and remove
 * Return: pointer to new root node of tree after removing desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *del_node, *replacement, *new_root;
	int status; /* 1 if right, 0 if left */

	del_node = bst_search(root, value);
	if (del_node == NULL)
		return (NULL);

	replacement = NULL, status = 0;
	if (del_node->right)
	{
		replacement = del_node->right, status = 1;
		while (replacement->left)
			replacement = replacement->left;
	}
	else if (del_node->left)
		replacement = del_node->left;

	if (replacement == NULL)
	{
		if (del_node->parent->left->n == del_node->n)
			del_node->parent->left = NULL;
		else
			del_node->parent->right = NULL;
		new_root = bst_find_root(del_node);
		free(del_node);
	}
	else if (status == 1)
	{
		del_node->n = replacement->n;
		new_root = bst_find_root(replacement);
		if (replacement->parent->left->n == replacement->n)
			replacement->parent->left = NULL;
		else
			replacement->parent->right = NULL;
		free(replacement);
	}
	else
	{
		del_node->n = replacement->n;
		del_node->left = del_node->left->left;
		if (del_node->left)
			del_node->left->parent = del_node;
		new_root = bst_find_root(del_node);
		free(replacement);
	}
	return (new_root);
}

/**
 * bst_search - Search for a value in a Binary Search Tree
 * @tree: pointer to root node of BST
 * @value: value to look for 9bst_t *bst_search(const bst_t *tree, int value)
 * Return: pointer to node containing value, else NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}

/**
 * bst_find_root - find the root of a Binary Search Tree
 * @node: node in a BST
 * Return: pointer to root node, else NULL
 */
bst_t *bst_find_root(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->parent)
		node = node->parent;

	return (node);
}
