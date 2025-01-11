#include "binary_trees.h"

/**
 * binary_tree_t *binary_tree_insert_left - Function that inserts a node
 *
 * @parent: A pointer to the node to insert the left child
 * @value: The value to store in the new node
 *
 * Return: A pointer to the created node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newNode = malloc(sizeof(binary_tree_t));

	if (newNode == NULL || parent == NULL)
	{
		free(newNode);
		return (NULL);
	}

	newNode->n = value;
	newNode->parent = parent;
	newNode->left = parent->left;
	newNode->right = NULL;

	if (parent->left != NULL)
	{
		parent->left->parent = newNode;
	}

	parent->left = newNode;

	return (newNode);
}
