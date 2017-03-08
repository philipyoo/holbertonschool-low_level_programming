#include "binary_trees.h"

/**
 * binary_trees_ancestor - find the lowest common ancestor of 2 nodes
 * @first: first node
 * @second: second node
 * Return: pointer to lowest common ancestor, else NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *tmp, *tmp2;
	int sz, sz2;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first->n == second->n)
		return ((binary_tree_t *)first);

	if (first->parent && second->parent)
	{
		if (first->parent->n == second->parent->n)
			return ((binary_tree_t *)first->parent);
	}

	tmp = binary_trees_ancestor(second->parent, first);
	tmp2 = binary_trees_ancestor(first->parent, second);
	if (tmp2 != NULL)
	{
		sz = custom_binary_tree_height(tmp);
		sz2 = custom_binary_tree_height(tmp2);
		if (sz > sz2)
			tmp = tmp2;
	}

	return (tmp);
}

/**
 * custom_binary_tree_height - Measure height of a binary tree from given node
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
