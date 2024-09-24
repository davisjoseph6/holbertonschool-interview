#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_last_node - Finds the last level-order node of the heap
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *queue[1024];  /* Assume a fixed size for simplicity */
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
		root = queue[front++];
		if (root->left)
			queue[rear++] = root->left;
		if (root->right)
			queue[rear++] = root->right;
	}
	return (root);
}

/**
 * heapify_down - Restores the Max Binary Heap property from a node
 * @node: Pointer to the root node to start heapifying from
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	int temp;

	while (node)
	{
		if (node->left && node->left->n > largest->n)
			largest = node->left;
		if (node->right && node->right->n > largest->n)
			largest = node->right;

		if (largest != node)
		{
			temp = node->n;
			node->n = largest->n;
			largest->n = temp;
			node = largest;
		}
		else
			break;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *last_node, *parent;

	if (!root || !*root)
		return (0);

	root_value = (*root)->n;
	last_node = find_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	(*root)->n = last_node->n;
	parent = last_node->parent;

	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last_node);
	heapify_down(*root);

	return (root_value);
}
