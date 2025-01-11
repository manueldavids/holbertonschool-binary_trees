#include "binary_trees.h"

/**
* binary_tree_is_perfect- function that checks if a binary tree is perfect
* @tree: is a pointer to the root node
* Return: 1 if perfect 0 is not
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);
	depth = -1;
	return (perfect_recursive(tree, 0, &depth));
}

/**
* perfect_recursive- helper function to check if a binary tree is perfect
* @node: current node being checked
* @current_depth: current depth in the tree
* @depth: pointer to store the depth of the first NULL node
* Return: 1 if perfect, 0 if not
*/

int perfect_recursive(const binary_tree_t *node, int current_depth, int *depth)
{
	if (node == NULL)
	{
		if (*depth == -1)
		{
			*depth = current_depth;
			return (1);
		}
		return (current_depth == *depth);
	}

	if (node->left == NULL && node->right != NULL)
		return (0);

	if (node->left != NULL && node->right == NULL)
		return (0);

	return (perfect_recursive(node->left, current_depth + 1, depth) &&
			perfect_recursive(node->right, current_depth + 1, depth));
}
