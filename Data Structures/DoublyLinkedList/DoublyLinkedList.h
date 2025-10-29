#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct Node {
	int value;
	struct Node* next;
	struct Node* prev;
} Node;

typedef struct DoublyLinkedList {
	int size;
	Node *head, *tail;
	void (*addFirst)(struct DoublyLinkedList*, int);
	void (*addLast)(struct DoublyLinkedList*, int);
	int (*get)(struct DoublyLinkedList*, int);
	void (*insert)(struct DoublyLinkedList*, int, int);
	int (*pollFirst)(struct DoublyLinkedList*);
	int (*pollLast)(struct DoublyLinkedList*);
	int (*peekFirst)(struct DoublyLinkedList*);
	int (*peekLast)(struct DoublyLinkedList*);
	int (*isEmpty)(const struct DoublyLinkedList*);
	void (*set)(struct DoublyLinkedList*, int, int);
	void (*destroyDoublyLinkedList)(struct DoublyLinkedList*);
} DoublyLinkedList;

DoublyLinkedList* new_DoublyLinkedList();

void addFirst(DoublyLinkedList*, int);

void addLast(DoublyLinkedList*, int);

int get(DoublyLinkedList*, int);

void insert(DoublyLinkedList*, int, int);

int pollFirst(DoublyLinkedList*);

int pollLast(DoublyLinkedList*);

int peekFirst(DoublyLinkedList*);

int peekLast(DoublyLinkedList*);

int isEmpty(const DoublyLinkedList*);

void set(DoublyLinkedList*, int, int);

void destroyDoublyLinkedList(DoublyLinkedList*);

#endif
