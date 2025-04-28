#ifndef MULTISET_H
#define MULTISET_H

#include "string.h"

typedef struct Node {
    String *value;
    int cnt;
    struct Node *next;
} Node;

typedef struct HashMultiSet {
    int size, capacity;
    double LOADFACTOR;
    Node **buckets;

    void (*free_HashMultiSet)(struct HashMultiSet *map);

    void (*insert)(struct HashMultiSet *map, String *key);

    int (*count)(struct HashMultiSet *map, String *key);

    void (*remove_node)(struct HashMultiSet *map, String *key);

    int (*contains)(struct HashMultiSet *map, String *key);
} HashMultiSet;

Node *new_Node(String *value);

void free_nodes(Node *node);

HashMultiSet *new_HashMultiSet();

void free_HashMultiSet(HashMultiSet *map);

void insert(HashMultiSet *map, String *key);

int count(HashMultiSet *map, String *key);

void remove_node(HashMultiSet *map, String *key);

int contains(HashMultiSet *map, String *key);

#endif
