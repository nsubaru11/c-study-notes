#include <stdio.h>
#include "BinarySearchTree.h"

void print(BinarySearchTree *tree);

int main(void) {
    BinarySearchTree *tree = new_BinarySearchTree();
    tree->add(tree, 5);
    tree->add(tree, 3);
    tree->add(tree, 7);
    tree->add(tree, 1);
    tree->add(tree, 2);
    tree->add(tree, 9);
    tree->add(tree, 4);
    print(tree);
    for (int i = 0; i <= 10; i += 2) {
        printf("index of %d: %d\n", i, tree->indexOf(tree, i));
    }
    printf("\n");
    for (int i = 0; i <= 10; i += 2) {
        printf("%2d: ", i);
        BinarySearchTree *temp = tree->higher(tree, i);
        if (temp == nullptr) {
            printf("higher: null, ");
        } else {
            printf("higher: %4d, ", temp->label);
        }
        temp = tree->ceiling(tree, i);
        if (temp == nullptr) {
            printf("ceiling: null, ");
        } else {
            printf("ceiling: %4d, ", temp->label);
        }
        temp = tree->lower(tree, i);
        if (temp == nullptr) {
            printf("lower: null, ");
        } else {
            printf("lower: %4d, ", temp->label);
        }
        temp = tree->flooring(tree, i);
        if (temp == nullptr) {
            printf("flooring: null\n");
        } else {
            printf("flooring: %4d\n", temp->label);
        }
    }
    tree->add(tree, 9);
    tree->add(tree, 9);
    printf("getCount(9): %d\n", tree->getCount(tree, 9));
    printf("head: %d\n", tree->head(tree)->label);
    printf("tail: %d\n", tree->tail(tree)->label);
    free_BinarySearchTree(tree);
    return 0;
}

void print(BinarySearchTree *tree) {
    printf("Size: %d\n", tree->size);
    printf("Tree:");
    for (int i = 0; i < tree->size; i++) {
        printf(" %d", tree->get(tree, i)->label);
    }
    printf("\n\n");
}
