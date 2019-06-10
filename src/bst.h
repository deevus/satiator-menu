#ifndef _BST_H
#define _BST_H

#include <stdint.h>
#include <stdlib.h>

typedef struct TreeNode tree_node_t;
struct TreeNode
{
    uint16_t key;
    struct TreeNode *left;
    struct TreeNode *right;
    size_t size;
    size_t max_size;
    void *data[];
};

typedef void (*TreeNodeCallback)(tree_node_t *);

tree_node_t *bst_insert(tree_node_t *root, uint16_t x, void *data);

tree_node_t* bst_find_min(tree_node_t* root);

tree_node_t* bst_find_max(tree_node_t* root);

tree_node_t* bst_find(tree_node_t* root, uint16_t x);

uint16_t bst_find_height(tree_node_t* root);

tree_node_t* bst_delete(tree_node_t* root, uint16_t x);

void bst_traverse(tree_node_t *root, TreeNodeCallback callback);

void bst_free(tree_node_t *root);

#endif
