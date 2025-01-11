#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: Pointer to the node to find the uncle.
 *
 * Return: Pointer to the uncle node, or NULL if:
 *         - node is NULL,
 *         - the parent is NULL,
 *         - the node has no uncle.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Check if the parent is the left child */
	if (node->parent->parent->left == node->parent)
		return (node->parent->parent->right);

	/* Otherwise, check if the parent is the right child */
	if (node->parent->parent->right == node->parent)
		return (node->parent->parent->left);

	/* If neither case matches, there is no uncle */
	return (NULL);
}

