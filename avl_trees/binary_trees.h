#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h> /* for size_t */

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/* (Optional) typedef for AVL, if needed */
typedef struct binary_tree_s avl_t;

void binary_tree_print(const binary_tree_t *tree);

/* Add the prototype for binary_tree_node here */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* Prototype for your AVL check function */
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* _BINARY_TREES_H_ */

