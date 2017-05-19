#include "heap.h"

/**
 * binary_tree_node - Create a Heap node
 * @parent: pointer to parent node
 * @data: data to be stored in node
 * Return: pointer to new created node or NULL if fail
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	new_node = malloc(sizeof(binary_tree_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
