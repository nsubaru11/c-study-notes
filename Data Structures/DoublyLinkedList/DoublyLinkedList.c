#include "DoublyLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

Node *new_Node(const int value) {
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->next = nullptr;
	node->prev = nullptr;
	return node;
}

DoublyLinkedList *new_DoublyLinkedList() {
	DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
	list->size = 0;
	list->head = list->tail = nullptr;
	list->addFirst = addFirst;
	list->addLast = addLast;
	list->get = get;
	list->insert = insert;
	list->pollFirst = pollFirst;
	list->pollLast = pollLast;
	list->peekFirst = peekFirst;
	list->peekLast = peekLast;
	list->isEmpty = isEmpty;
	list->set = set;
	list->destroy = destroy;
	return list;
}

void addFirst(DoublyLinkedList *list, const int value) {
	Node *node = new_Node(value);
	if (list->isEmpty(list)) {
		list->tail = node;
	} else {
		node->next = list->head;
		list->head->prev = node;
	}
	list->head = node;
	list->size++;
}

void addLast(DoublyLinkedList *list, const int value) {
	Node *node = new_Node(value);
	if (list->isEmpty(list)) {
		list->head = node;
	} else {
		list->tail->next = node;
		node->prev = list->tail;
	}
	list->tail = node;
	list->size++;
}

int get(DoublyLinkedList *list, const int index) {
	const int size = list->size;
	if (index < 0 || size <= index) {
		printf("IndexOutOfBoundsException %d\n", index);
		list->destroy(list);
		exit(-1);
	}
	if (index > size / 2) {
		int pos = size - 1;
		Node *node = list->tail;
		while (pos-- > index) {
			node = node->prev;
		}
		return node->value;
	}
	int pos = 0;
	Node *node = list->head;
	while (pos++ < index) {
		node = node->next;
	}
	return node->value;
}

void insert(DoublyLinkedList *list, const int index, const int value) {
	const int size = list->size;
	if (index < 0 || size < index) {
		printf("IndexOutOfBoundsException %d\n", index);
		list->destroy(list);
		exit(-1);
	}
	if (index == size) {
		list->addLast(list, value);
	} else if (index == 0) {
		list->addFirst(list, value);
	} else {
		Node *node = new_Node(value);
		Node *next, *prev;
		if (index > size / 2) {
			int pos = size - 1;
			next = list->tail;
			while (pos-- > index) {
				next = next->prev;
			}
			prev = next->prev;
		} else {
			int pos = 0;
			prev = list->head;
			while (pos++ < index) {
				prev = prev->next;
			}
			next = prev->next;
		}
		prev->next = next->prev = node;
		node->prev = prev;
		node->next = next;
		list->size++;
	}
}

int isEmpty(const DoublyLinkedList *list) { return list->size == 0; }

int pollFirst(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->destroy(list);
		exit(-1);
	}
	Node *head = list->head;
	const int data = head->value;
	if (list->size > 1) {
		list->head = head->next;
	} else {
		list->head = list->tail = nullptr;
	}
	list->size--;
	free(head);
	return data;
}

int pollLast(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->destroy(list);
		exit(-1);
	}
	Node *tail = list->tail;
	const int data = tail->value;
	if (list->size > 1) {
		list->tail = tail->prev;
	} else {
		list->head = list->tail = nullptr;
	}
	free(tail);
	list->size--;
	return data;
}

int peekFirst(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->destroy(list);
		exit(-1);
	}
	return list->head->value;
}

int peekLast(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->destroy(list);
		exit(-1);
	}
	return list->tail->value;
}

void set(DoublyLinkedList *list, const int index, const int value) {
	const int size = list->size;
	if (index < 0 || size < index) {
		printf("IndexOutOfBoundsException %d\n", index);
		list->destroy(list);
		exit(-1);
	}
	if (index > size / 2) {
		int pos = size - 1;
		Node *node = list->tail;
		while (pos-- > index) {
			node = node->prev;
		}
		node->value = value;
	} else {
		int pos = 0;
		Node *node = list->head;
		while (pos++ < index) {
			node = node->next;
		}
		node->value = value;
	}
}

void destroy(DoublyLinkedList *list) {
	if (list == NULL) {
		return;
	}
	Node *node = list->head;
	while (node->next) {
		Node *next = node->next;
		free(node);
		node = next;
	}
	free(node);
	free(list);
}
