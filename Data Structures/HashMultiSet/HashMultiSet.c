#include "HashMultiSet.h"

#include <stdio.h>
#include <stdlib.h>

#include "string.h"

HashMultiSet *new_HashMultiSet() {
    HashMultiSet *multi_set = malloc(sizeof(HashMultiSet));
    multi_set->size = 0;
    multi_set->capacity = 1024;
    multi_set->LOADFACTOR = 0.75;
    multi_set->buckets = malloc(sizeof(Node *) * multi_set->capacity);
    for (int i = 0; i < multi_set->capacity; i++) {
        multi_set->buckets[i] = nullptr;
    }
    multi_set->free_HashMultiSet = free_HashMultiSet;
    multi_set->insert = insert;
    multi_set->count = count;
    multi_set->contains = contains;
    multi_set->remove_node = remove_node;
    return multi_set;
}

Node *new_Node(String *value) {
    Node *node = malloc(sizeof(Node));
    node->cnt = 1;
    node->value = value;
    node->next = nullptr;
    return node;
}

void free_HashMultiSet(HashMultiSet *multi_set) {
    if (multi_set) {
        for (int i = 0; i < multi_set->capacity; i++) {
            free_nodes(multi_set->buckets[i]);
        }
        free(multi_set->buckets);
        free(multi_set);
    }
}

void free_nodes(Node *node) {
    while (node) {
        Node *next = node->next;
        free(node);
        node = next;
    }
}

void resize_multiset(HashMultiSet *map) {
    map->capacity *= 2;
    Node **tmp = malloc(sizeof(Node *) * map->capacity);
    for (int i = 0; i < map->capacity; i++) {
        Node *node = map->buckets[i];
        while (node) {
            int hash = node->value->hashCode & (map->capacity - 1);
            if (tmp[hash]) {
                Node *tmp_node = tmp[hash];
                while (tmp_node->next) {
                    tmp_node = tmp_node->next;
                }
                tmp_node->next = node;
            } else {
                tmp[hash] = node;
            }
            node = node->next;
        }
        free(map->buckets[i]);
    }
    free(map->buckets);
    map->buckets = tmp;
}

void insert(HashMultiSet *map, String *key) {
    int hash = key->hashCode & (map->capacity - 1);
    Node *prev = nullptr;
    Node *node = map->buckets[hash];
    while (node) {
        if (equals(key, node->value)) {
            node->cnt++;
            return;
        }
        node = node->next;
        prev = node;
    }
    if (prev) {
        prev->next = new_Node(key);
    } else {
        map->buckets[hash] = new_Node(key);
    }
    map->size++;
    if (map->size > map->capacity * map->LOADFACTOR) {
        resize_multiset(map);
    }
}

int count(HashMultiSet *map, String *key) {
    int hash = key->hashCode & (map->capacity - 1);
    Node *node = map->buckets[hash];
    while (node) {
        if (equals(key, node->value)) {
            return node->cnt;
        }
        node = node->next;
    }
    return 0;
}

void remove_node(HashMultiSet *map, String *key) {
    int hash = key->hashCode & (map->capacity - 1);
    Node *prev = nullptr;
    Node *node = map->buckets[hash];
    while (node) {
        if (equals(key, node->value)) {
            if (prev) {
                prev->next = node->next;
            } else {
                map->buckets[hash] = node->next;
            }
            free(node);
            break;
        }
    }
}

int contains(HashMultiSet *map, String *key) {
    int hash = key->hashCode & (map->capacity - 1);
    Node *node = map->buckets[hash];
    while (node) {
        if (equals(key, node->value)) {
            return 1;
        }
        node = node->next;
    }
    return 0;
}
