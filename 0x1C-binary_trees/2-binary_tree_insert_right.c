#include "binary_trees.h"
/**
 *binary_tree_insert_right - inserting to the right of the binary tree
 *@parent: The parent node of what is being inserted
 *@value: The value stored in the struct
 *Return: The newly inserted node or NULL if the parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->parent = parent;
	temp = parent->right;
	if (temp != NULL)
	{
		node->right = temp;
		temp->parent = node;
	}
	else
		node->right = NULL;
	parent->right = node;
	node->left = NULL;
	return (node);
}
