/* Binary Search Tree Implementation in C */
/* Harish R */
#include "bst.h"

#include <stdlib.h>
#include <stdint.h>
#include <jo/jo.h>

#define MIN_DATA_SIZE 4

tree_node_t *bst_insert(tree_node_t *root, uint16_t x, void *data) {
    if(root == NULL) {
        root = malloc(sizeof(tree_node_t) + sizeof(void *) * MIN_DATA_SIZE);
        root->key  = x;
        root->size = 1;
        root->max_size = MIN_DATA_SIZE;
        root->data[0] = data;
        root->left = root->right = NULL;
    } else if (x == root->key) {
        if (root->size < root->max_size) {
            root->data[root->size] = data;
            root->size++;
        } else {
            tree_node_t *newroot = malloc(sizeof(tree_node_t) + sizeof(void *) * (root->max_size + MIN_DATA_SIZE));
            newroot->key = root->key;

            for (size_t i = 0; i < root->size; i++) {
                newroot->data[i] = root->data[i];
            }

            newroot->data[root->size] = data;
            newroot->size = root->size + 1;

            free(root);
            root = newroot;
        }
    } else if(x < root->key) {
        root->left = bst_insert(root->left, x, data);
    } else if(x > root->key) {
        root->right = bst_insert(root->right, x, data);
    }

    return root;
}

tree_node_t* bst_find_min(tree_node_t* root) {
    if(root == NULL)
    	return NULL;
    else if(root->left == NULL)
    	return root;
    else
    	return bst_find_min(root->left);
}

tree_node_t* bst_find_max(tree_node_t* root) {
    if(root == NULL)
    	return NULL;
    else if(root->right == NULL)
    	return root;
    else
    	return bst_find_max(root->right);
}

tree_node_t* bst_find(tree_node_t* root, uint16_t x) {
    if(root == NULL)
        return NULL;
    else if(x < root->key)
        return bst_find(root->left, x);
    else if(x > root->key)
        return bst_find(root->right, x);
    else
        return root;
}

uint16_t bst_find_height(tree_node_t* root) {
    uint16_t lefth, righth;
    if(root == NULL)
        return -1;
    lefth = bst_find_height(root->left);
    righth = bst_find_height(root->right);
    return (lefth > righth ? lefth : righth)+1;
}

tree_node_t* bst_delete(tree_node_t* root, uint16_t x) {
    tree_node_t* temp;
    if(root == NULL)
        return NULL;
    else if(x < root->key)
        root->left = bst_delete(root->left, x);
    else if(x > root->key)
        root->right = bst_delete(root->right, x);
    else if(root->left && root->right) {
        temp = bst_find_min(root->right);
        root->key = temp->key;
        root->right = bst_delete(root->right, root->key);
    } else {
        temp = root;
        if(root->left == NULL)
            root = root->right;
        else if(root->right == NULL)
            root = root->left;
        free(temp);
    }

    return root;
}

void bst_traverse(tree_node_t *root, TreeNodeCallback callback) {
    if (root == NULL) {
        return;
    }

    bst_traverse(root->left, callback);
    callback(root);
    bst_traverse(root->right, callback);
}

void bst_free(tree_node_t *root) {
    if (root == NULL) {
        return;
    }

    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

