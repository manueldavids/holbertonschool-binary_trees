#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	right_height = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the size.
 *
 * Return: The size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, otherwise 0.
 *         If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, expected_size, actual_size;

	if (tree == NULL)
		return (0);

	/* Calculate height of the tree */
	height = binary_tree_height(tree);

	/* Calculate the expected size of a perfect tree of this height */
	expected_size = (1 << (height + 1)) - 1; /* 2^(height+1) - 1 */

	/* Calculate the actual size of the tree */
	actual_size = binary_tree_size(tree);

	/* Compare actual size to expected size */
	return (actual_size == expected_size);
}

