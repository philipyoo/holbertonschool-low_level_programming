#include "binary_trees.h"
/**
 *binary_tree_preorder - Going through a binary tree using pre-order traversal
 *@tree: The binary tree to traverse and print
 *@func: A function used to print the number stored in the node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (func == NULL)
		return;
	if (tree == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
