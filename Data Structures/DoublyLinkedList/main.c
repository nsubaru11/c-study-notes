#include <stdio.h>
#include "DoublyLinkedList.h"

void print(DoublyLinkedList *list);

int main(void) {
	DoublyLinkedList *list = new_DoublyLinkedList();
	printf("%s", list->isEmpty(list) ? "true\n" : "false\n");
	for (int i = 0; i < 10; i++) {
		list->addFirst(list, i);
		list->addLast(list, i);
	}
	print(list);
	printf("%s", list->isEmpty(list) ? "true\n" : "false\n");
	for (int i = 0; i <= list->size; i += 5) {
		list->insert(list, i, 1000);
	}
	print(list);
	printf("%d ", list->peekFirst(list));
	printf("%d\n", list->pollFirst(list));
	printf("%d ", list->peekLast(list));
	printf("%d\n", list->pollLast(list));
	list->set(list, list->size / 2, 2000);
	print(list);
	list->destroy(list);
	return 0;
}

void print(DoublyLinkedList *list) {
	for (int i = 0; i < list->size; i++) {
		printf("%d ", list->get(list, i));
	}
	printf("\n");
}