#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>
#include <stddef.h>


/**
 * struct binary_tree_s - Binary t node structure
 *
 * @n: Integer stored in the node
 * @p: Pointer to the p node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *p;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *p, int v);
binary_tree_t *binary_tree_insert_left(binary_tree_t *p, int v);
binary_tree_t *binary_tree_insert_right(binary_tree_t *p, int v);
void binary_tree_delete(binary_tree_t *t);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *t, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *t, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *t, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *t);
size_t my_binary_tree_height(const binary_tree_t *t);
size_t binary_tree_depth(const binary_tree_t *t);
size_t binary_tree_size(const binary_tree_t *t);
size_t binary_tree_leaves(const binary_tree_t *t);
size_t binary_tree_nodes(const binary_tree_t *t);
int binary_tree_balance(const binary_tree_t *t);
int binary_tree_is_full(const binary_tree_t *t);
int binary_tree_is_perfect(const binary_tree_t *t);
int binary_tree_is_perfect(const binary_tree_t *t);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *t);
void binary_tree_levelorder(const binary_tree_t *t, void (*func)(int));
int binary_tree_is_bst(const binary_tree_t *t);
int bst_true(const binary_tree_t *t);
int binary_tree_search(const binary_tree_t *first, const binary_tree_t *second);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second);


#endif /* BINARY_TREES_H*/
