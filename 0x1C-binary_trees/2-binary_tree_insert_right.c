#include "binary_trees.h"
/**
 *binary_tree_insert_right - inserting to the right of the binary tree
 *@parent: The parent node of what is being inserted
 *@value: The value stored in the struct
 *Return: The newly inserted node or NULL if the parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	if (parent != NULL)
	{
		node->n = value;
		node->parent = parent;
		node->right = parent->right;
		if (node->right != NULL)
			node->right->parent = node;
		parent->right = node;
		node->left = NULL;
		return (node);
	}
	return (NULL);
}
