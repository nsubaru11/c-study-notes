#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef struct BinarySearchTree {
    int size, cnt, label;
    struct BinarySearchTree *left, *right;

    void (*free_BinarySearchTree)(struct BinarySearchTree *tree);

    int (*add)(struct BinarySearchTree *tree, int value);

    struct BinarySearchTree * (*get)(struct BinarySearchTree *tree, int index);

    int (*indexOf)(const struct BinarySearchTree *tree, int value);

    struct BinarySearchTree * (*higher)(struct BinarySearchTree *tree, int value);

    struct BinarySearchTree * (*lower)(struct BinarySearchTree *tree, int value);

    struct BinarySearchTree * (*ceiling)(struct BinarySearchTree *tree, int value);

    struct BinarySearchTree * (*flooring)(struct BinarySearchTree *tree, int value);

    int (*getCount)(const struct BinarySearchTree *tree, int value);

    // int (*remove)(struct BinarySearchTree *tree, int value);

    struct BinarySearchTree *(*head)(struct BinarySearchTree *tree);

    struct BinarySearchTree *(*tail)(struct BinarySearchTree *tree);
} BinarySearchTree;

BinarySearchTree *new_BinarySearchTree();

BinarySearchTree *new_BinarySearchTreeNode(int n);

void free_BinarySearchTree(BinarySearchTree *tree);

int add(BinarySearchTree *tree, int value);

BinarySearchTree *get(BinarySearchTree *tree, int index);

int indexOf(const BinarySearchTree *tree, int value);

BinarySearchTree *higher(BinarySearchTree *tree, int value);

BinarySearchTree *lower(BinarySearchTree *tree, int value);

BinarySearchTree *ceiling(BinarySearchTree *tree, int value);

BinarySearchTree *flooring(BinarySearchTree *tree, int value);

int getCount(const BinarySearchTree *tree, int value);

// int remove(BinarySearchTree *tree, int value);

BinarySearchTree *head(BinarySearchTree *tree);

BinarySearchTree *tail(BinarySearchTree *tree);

#endif
