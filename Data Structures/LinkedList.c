#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct DoublyLinkedList {
	Node *head;
	Node *tail;
	int size;
	void (*addFirst)(struct DoublyLinkedList *, int);
	void (*addLast)(struct DoublyLinkedList *, int);
	int (*get)(struct DoublyLinkedList *, int);
	void (*insert)(struct DoublyLinkedList *, int, int);
	int (*pollFirst)(struct DoublyLinkedList *);
	int (*pollLast)(struct DoublyLinkedList *);
	int (*peekFirst)(struct DoublyLinkedList *);
	int (*peekLast)(struct DoublyLinkedList *);
	void (*print)(struct DoublyLinkedList *);
} DoublyLinkedList;

Node *new_Node(int data);
DoublyLinkedList *new_DoublyLinkedList(void);
void addFirst(DoublyLinkedList *list, int data);
void addLast(DoublyLinkedList *list, int data);
void print(const DoublyLinkedList *list);

int main(void) {
	DoublyLinkedList *list = new_DoublyLinkedList();
	for (int i = 0; i < 10; i++) {
		list->addFirst(list, i);
		list->addLast(list, i);
	}
	list->print(list);
	return 0;
}

Node *new_Node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

DoublyLinkedList *new_DoublyLinkedList() {
	DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	list->addFirst = addFirst;
	list->addLast = addLast;
	list->print = print;
	return list;
}

void addFirst(DoublyLinkedList *list, const int data) {
	Node *node = new_Node(data);
	if (list->size == 0) {
		list->tail = node;
	} else {
		node->next = list->head;
		list->head->prev = node;
	}
	list->head = node;
	list->size++;
}

void addLast(DoublyLinkedList *list, const int data) {
	Node *node = new_Node(data);
	if (list->size == 0) {
		list->head = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
	}
	list->tail = node;
	list->size++;
}

void print(const DoublyLinkedList *list) {
	Node *node = list->head;
	printf("List:");
	while (node != NULL) {
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");
}
