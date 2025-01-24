#include <stdlib.h>   /* For malloc, free, abs */
#include <limits.h>   /* For INT_MIN, INT_MAX */
#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to put in the new node
 *
 * Return: Pointer to the newly created node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * is_avl_helper - Recursive helper to check if a binary tree is AVL
 * @tree: Pointer to the current node
 * @height: Pointer to an int where the function will store this node's height
 * @min_val: Minimum valid value for the current node (BST property)
 * @max_val: Maximum valid value for the current node (BST property)
 *
 * Return: 1 if subtree is AVL, 0 otherwise
 */
static int is_avl_helper(const binary_tree_t *tree, int *height,
			 int min_val, int max_val)
{
	int left_height = 0, right_height = 0;
	int left_is_avl, right_is_avl;

	if (!tree)
	{
		*height = 0;
		return (1);
	}

	/* Check BST property: value must be strictly between min_val and max_val */
	if (tree->n <= min_val || tree->n >= max_val)
		return (0);

	left_is_avl = is_avl_helper(tree->left, &left_height, min_val, tree->n);
	right_is_avl = is_avl_helper(tree->right, &right_height, tree->n, max_val);

	if (!left_is_avl || !right_is_avl)
		return (0);

	/* Check height balance: difference <= 1 */
	if (abs(left_height - right_height) > 1)
		return (0);

	/* Height of current node is max of children + 1 */
	*height = (left_height > right_height ? left_height : right_height) + 1;
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;

	if (!tree)
		return (0);

	return (is_avl_helper(tree, &height, INT_MIN, INT_MAX));
}

