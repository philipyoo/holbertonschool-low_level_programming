#include <stdlib.h>
#include <stdio.h>
#include "../binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	binary_tree_t *root;
	int ret;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);
	binary_tree_insert_left(root->right, 128);
	binary_tree_insert_left(root, 54);
	binary_tree_print(root);

	ret = binary_tree_is_leaf(root);
	printf("Is %d a leaf: %d\n", root->n, ret);
	ret = binary_tree_is_leaf(root->right);
	printf("Is %d a leaf: %d\n", root->right->n, ret);
	ret = binary_tree_is_leaf(root->right->left);
	printf("Is %d a leaf: %d\n", root->right->left->n, ret);
	return (0);
}
