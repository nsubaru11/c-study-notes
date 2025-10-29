#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

typedef struct BinarySearchTree {
	int size, cnt, label;
	struct BinarySearchTree *left, *right;

	void (*free_BinarySearchTree)(struct BinarySearchTree*);

	int (*add)(struct BinarySearchTree*, int);

	struct BinarySearchTree* (*get)(struct BinarySearchTree*, int);

	int (*indexOf)(const struct BinarySearchTree*, int);

	struct BinarySearchTree* (*higher)(struct BinarySearchTree*, int);

	struct BinarySearchTree* (*lower)(struct BinarySearchTree*, int);

	struct BinarySearchTree* (*ceiling)(struct BinarySearchTree*, int);

	struct BinarySearchTree* (*flooring)(struct BinarySearchTree*, int);

	int (*count)(const struct BinarySearchTree*, int);

	// int (*remove)(struct BinarySearchTree*, int);

	struct BinarySearchTree* (*head)(struct BinarySearchTree*);

	struct BinarySearchTree* (*tail)(struct BinarySearchTree*);
} BinarySearchTree;

BinarySearchTree* new_BinarySearchTree();

BinarySearchTree* new_BinarySearchTreeNode(int);

void free_BinarySearchTree(BinarySearchTree*);

int add(BinarySearchTree*, int);

BinarySearchTree* get(BinarySearchTree*, int);

int indexOf(const BinarySearchTree*, int);

BinarySearchTree* higher(BinarySearchTree*, int);

BinarySearchTree* lower(BinarySearchTree*, int);

BinarySearchTree* ceiling(BinarySearchTree*, int);

BinarySearchTree* flooring(BinarySearchTree*, int);

int count(const BinarySearchTree*, int);

// int remove(BinarySearchTree*, int);

BinarySearchTree* head(BinarySearchTree*);

BinarySearchTree* tail(BinarySearchTree* tree);

#endif
