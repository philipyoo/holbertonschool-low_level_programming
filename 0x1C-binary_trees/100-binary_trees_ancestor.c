#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_trees_ancestor - find the lowest common ancestor of 2 nodes
 * @first: first node
 * @second: second node
 * Return: pointer to lowest common ancestor, else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int sz, sz2;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->n == second->n)
		return ((binary_tree_t *)first);

	sz = binary_tree_depth(first);
	sz2 = binary_tree_depth(second);
	if (sz > sz2)
	{
		while (sz > sz2)
		{
			first = first->parent;
			if (first == NULL)
				return (NULL);
			sz = binary_tree_depth(first);
		}
	}
	else if (sz2 > sz)
	{
		while (sz2 > sz)
		{
			second = second->parent;
			if (second == NULL)
				return (NULL);
			sz2 = binary_tree_depth(second);
		}
	}

	while (first && second)
	{
		if (first->n == second->n)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}

	return (NULL);
}

/**
 * binary_tree_depth - measure the depth of a node in a binary tree.
 * Depth is measured from root parent node going down.
 * @node: pointer to node to measure depth of
 * Return: depth of tree from given node
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (0);

	return (binary_tree_depth(node->parent) + 1);
}
