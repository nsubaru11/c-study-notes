#ifndef MULTISET_H
#define MULTISET_H

#include "../String/string.h"

typedef struct Node {
	String* value;
	int cnt;
	struct Node* next;
} Node;

typedef struct HashMultiSet {
	int size, capacity;
	double LOADFACTOR;
	Node** buckets;

	void (*free_HashMultiSet)(struct HashMultiSet*);

	void (*insert)(struct HashMultiSet*, String*);

	int (*count)(struct HashMultiSet*, String*);

	void (*remove_node)(struct HashMultiSet*, String*);

	int (*contains)(struct HashMultiSet*, String*);
} HashMultiSet;

Node* new_Node(String*);

void free_nodes(Node*);

HashMultiSet* new_HashMultiSet();

void free_HashMultiSet(HashMultiSet*);

void insert(HashMultiSet*, String*);

int count(HashMultiSet*, String*);

void remove_node(HashMultiSet*, String*);

int contains(HashMultiSet*, String*);

#endif
