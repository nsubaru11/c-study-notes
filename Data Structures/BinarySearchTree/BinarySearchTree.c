#include <stdio.h>
#include <stdlib.h>

struct Tree {
	int size;
	int label;
	struct Tree *left, *right;
};

struct Tree *Tree();
void add(struct Tree *tree, int value);
int lower(struct Tree *tree, int value);
int higher(struct Tree *tree, int value);

int main(void) {
	printf("Hello, World!\n");
	struct Tree tree2;
	tree2.size = 0;
	//	struct Tree* tree = Tree();
	add(&tree2, 1);
}

struct Tree *Tree(void) {
	struct Tree *tree = (struct Tree *) malloc(sizeof(struct Tree));
	tree->size = 0;
	return tree;
}

void add(struct Tree *tree, int value) {
	if (tree == NULL) {
		struct Tree *tree = Tree();
		tree->label = value;
		tree->size = 1;
	} else {
		tree->size++;
		if (value < tree->label) {
			add(tree->left, value);
		} else {
			add(tree->right, value);
		}
	}
}

int higher(struct Tree *tree, int value) {
	int a = 0;
	if (tree == NULL) {
		return INT_MAX;
	} else {
		if (value < tree->label) {

		} else {
		}
	}
	return a;
}
