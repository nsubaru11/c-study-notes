#include <stdio.h>
#include "DoublyLinkedList.h"

void print(DoublyLinkedList* list);

int main(void) {
	DoublyLinkedList* list = new_DoublyLinkedList();
	print(list);

	for (int i = 0; i < 10; i++) {
		list->addFirst(list, i);
		list->addLast(list, i);
	}
	print(list);

	for (int i = 0; i <= list->size; i += 5) {
		list->insert(list, i, 1000);
	}
	print(list);

	printf("peekFirst: %d, ", list->peekFirst(list));
	printf("pollFirst: %d\n", list->pollFirst(list));
	printf("peekLast: %d, ", list->peekLast(list));
	printf("pollLast: %d\n\n", list->pollLast(list));
	list->set(list, list->size / 2, 2000);
	print(list);

	DoublyLinkedList* list2 = new_DoublyLinkedList();
	for (int i = 0; i < 5; i++)
		list2->addLast(list2, i);
	print(list2);
	list2->insert(list2, 2, 100);
	print(list2);

	list->destroyDoublyLinkedList(list);
	list2->destroyDoublyLinkedList(list2);
	return 0;
}

void print(DoublyLinkedList* list) {
	printf("isEmpty? %s, ", list->isEmpty(list) ? "true" : "false");
	printf("size: %d\n", list->size);
	printf("List:");
	for (int i = 0; i < list->size; i++) {
		printf(" %d", list->get(list, i));
	}
	printf("\n\n");
}
