#include "binary_trees.h"
/**
 *binary_tree_is_root - Function that checks if a given node is a root
 *@node: a pointer that points to the value of what we want to check
 *Return: 1 if the node is a root or else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node->parent == NULL)
		return (1);
	return (0);
}
