#include "binary_trees.h"
/**
 *binary_tree_nodes - Count the nodes that have at least one child
 *@tree: The tree to be evaluated
 *Return: 0 when tree is NULL or a recursive function call
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree != NULL && (tree->left != NULL || tree->right != NULL))
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
	return (0);
}
