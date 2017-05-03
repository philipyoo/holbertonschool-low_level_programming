#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rb_trees.h"

/* Original code from http://stackoverflow.com/a/13755911/5184480 */

/**
 * rb_print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */
static int rb_print_t(const rb_tree_t *tree, int offset, int depth, char **s)
{
	char b[12];
	int width, left, right, i;
	int is_left;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	width = sprintf(b, "%c(%03d)", (tree->color == RED ? 'R' : 'B'), tree->n);
	left = rb_print_t(tree->left, offset, depth + 1, s);
	right = rb_print_t(tree->right, offset + left + width, depth + 1, s);
	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - width / 2 + i] = '-';
		s[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

/**
 * rb_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t rb_height(const rb_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + rb_height(tree->left) : 0;
	height_r = tree->right ? 1 + rb_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * rb_tree_print - Prints a red-black tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void rb_tree_print(const rb_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = rb_height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	rb_print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
