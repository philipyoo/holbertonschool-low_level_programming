#include "binary_trees.h"
#include <stdio.h>
/**
 *binary_tree_rotate_left - left rotate the tree
 *@tree: The tree to be rotated
 *Return: The new tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *new_root;

	temp = NULL;
	if (tree == NULL)
		return (NULL);
	if (tree->right->left != NULL)
		temp = tree->right->left;
	if (tree->right == NULL)
		return (tree);
	new_root = tree->right;
	tree->right->left = tree;
	tree->parent = tree->right;
	tree->right->parent = NULL;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	return (new_root);
}
