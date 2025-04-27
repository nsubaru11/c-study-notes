#include "BinarySearchTree.h"

#include <stdio.h>
#include <stdlib.h>

BinarySearchTree *new_BinarySearchTree() {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    tree->size = tree->cnt = 0;
    tree->left = tree->right = nullptr;
    tree->free_BinarySearchTree = free_BinarySearchTree;
    tree->add = add;
    tree->get = get;
    tree->indexOf = indexOf;
    tree->higher = higher;
    tree->lower = lower;
    tree->ceiling = ceiling;
    tree->flooring = flooring;
    tree->getCount = getCount;
    // tree->remove = remove;
    tree->head = head;
    tree->tail = tail;
    return tree;
}

BinarySearchTree *new_BinarySearchTreeNode(const int n) {
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    tree->label = n;
    tree->size = tree->cnt = 1;
    tree->left = tree->right = nullptr;
    tree->free_BinarySearchTree = free_BinarySearchTree;
    tree->add = add;
    tree->get = get;
    tree->indexOf = indexOf;
    tree->higher = higher;
    tree->lower = lower;
    tree->ceiling = ceiling;
    tree->flooring = flooring;
    tree->getCount = getCount;
    // tree->remove = remove;
    tree->head = head;
    tree->tail = tail;
    return tree;
}

void free_BinarySearchTree(BinarySearchTree *tree) {
    if (tree) {
        if (tree->left)
            tree->free_BinarySearchTree(tree->left);
        if (tree->right)
            tree->free_BinarySearchTree(tree->right);
        free(tree);
    }
}

int add(BinarySearchTree *tree, const int value) {
    if (tree->cnt == 0) {
        tree->label = value;
        tree->cnt++;
        tree->size++;
        return value;
    }
    if (tree->label > value) {
        if (tree->left == nullptr) {
            tree->left = new_BinarySearchTreeNode(value);
            tree->size++;
            return value;
        } else {
            int isAdded = tree->add(tree->left, value);
            if (isAdded) tree->size++;
            return isAdded;
        }
    } else if (tree->label < value) {
        if (tree->right == nullptr) {
            tree->right = new_BinarySearchTreeNode(value);
            tree->size++;
            return value;
        } else {
            int isAdded = tree->add(tree->right, value);
            if (isAdded) tree->size++;
            return isAdded;
        }
    } else {
        tree->cnt++;
        return 0;
    }
}

BinarySearchTree *get(BinarySearchTree *tree, const int index) {
    if (index < 0 || index >= tree->size) {
        printf("Index out of range.\n");
        exit(1);
    }
    int leftSize = tree->left ? tree->left->size : 0;
    if (leftSize > index) {
        return tree->get(tree->left, index);
    } else if (leftSize < index) {
        return tree->get(tree->right, index - leftSize - 1);
    } else {
        return tree;
    }
}

int indexOf(const BinarySearchTree *tree, const int value) {
    if (tree->label > value) {
        return tree->left ? tree->left->indexOf(tree->left, value) : ~0;
    } else if (tree->label < value) {
        int leftSize = tree->left ? tree->left->size : 0;
        if (tree->right) {
            int idx = tree->indexOf(tree->right, value);
            if (idx < 0) {
                idx = ~(leftSize + 1 + ~idx);
            } else {
                idx += leftSize + 1;
            }
            return idx;
        } else {
            return ~(leftSize + 1);
        }
    } else {
        return tree->left ? tree->left->size : 0;
    }
}

BinarySearchTree *findBoundary(BinarySearchTree *tree, const int value, const int inclusive, const int higher) {
    if (tree->label > value) {
        if (higher) {
            if (tree->left == nullptr) return tree;
            BinarySearchTree *t2 = findBoundary(tree->left, value, inclusive, higher);
            return t2 ? t2 : tree;
        } else {
            return tree->left ? findBoundary(tree->left, value, inclusive, higher) : nullptr;
        }
    } else if (tree->label < value) {
        if (higher) {
            return tree->right ? findBoundary(tree->right, value, inclusive, higher) : nullptr;
        } else {
            if (tree->right == nullptr) return tree;
            BinarySearchTree *t2 = findBoundary(tree->right, value, inclusive, higher);
            return t2 ? t2 : tree;
        }
    } else {
        if (inclusive) return tree;
        if (higher) {
            return tree->right ? findBoundary(tree->right, value, inclusive, higher) : nullptr;
        } else {
            return tree->left ? findBoundary(tree->left, value, inclusive, higher) : nullptr;
        }
    }
}

BinarySearchTree *higher(BinarySearchTree *tree, const int value) {
    return findBoundary(tree, value, false, true);
}

BinarySearchTree *lower(BinarySearchTree *tree, const int value) {
    return findBoundary(tree, value, false, false);
}

BinarySearchTree *ceiling(BinarySearchTree *tree, const int value) {
    return findBoundary(tree, value, true, true);
}

BinarySearchTree *flooring(BinarySearchTree *tree, const int value) {
    return findBoundary(tree, value, true, false);
}

int getCount(const BinarySearchTree *tree, const int value) {
    if (tree->label > value) {
        return tree->left ? tree->left->getCount(tree->left, value) : 0;
    } else if (tree->label < value) {
        return tree->right ? tree->right->getCount(tree->right, value) : 0;
    } else {
        return tree->cnt;
    }
}

// int remove(BinarySearchTree *tree, int value) {
//     if (tree->label > value) {
//
//     } else if (tree->label < value) {
//
//     } else {
//
//     }
// }

BinarySearchTree *head(BinarySearchTree *tree) {
    if (tree->left)
        return tree->head(tree->left);
    return tree;
}

BinarySearchTree *tail(BinarySearchTree *tree) {
    if (tree == nullptr) return nullptr;
    if (tree->right)
        return tree->tail(tree->right);
    return tree;
}
