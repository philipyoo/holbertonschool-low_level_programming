#include "binary_trees.h"
#include <stdio.h>
/**
 * bst_insert - insert a value into a Binary Search Tree
 * @tree: double pointer to root node
 * @value: value to store in new node
 * Return: pointer to new node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (bst_insert_help(*tree, value));
}

/**
 * bst_insert_help - helper function for inserting nodes into BST
 * @node: pointer to current potential parent node
 * @value: value to store in new node
 * Return: pointer to new node or NULL on failure
 */
bst_t *bst_insert_help(bst_t *node, int value)
{
	bst_t *new_node;

	if (value > node->n)
	{
		if (node->right)
			return (bst_insert_help(node->right, value));
		else
		{
			new_node = binary_tree_node(node, value);
			node->right = new_node;
			return (new_node);
		}
	}
	else if (value < node->n)
	{
		if (node->left)
			return (bst_insert_help(node->left, value));
		else
		{
			new_node = binary_tree_node(node, value);
			node->left = new_node;
			return (new_node);
		}
	}

	return (NULL);
}
