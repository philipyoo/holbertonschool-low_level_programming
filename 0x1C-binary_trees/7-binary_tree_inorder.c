#include "binary_trees.h"
/**
 *binary_tree_inorder - Go through a binary tree using in-order traversal
 *@tree: The tree to be printed in order
 *@func: A pointer to a function used to print the numbers
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
