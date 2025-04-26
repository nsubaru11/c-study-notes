#include <stdio.h>
#include "DoublyLinkedList.h"

void print(DoublyLinkedList *list);

int main(void) {
	DoublyLinkedList *list = new_DoublyLinkedList(); // ������
	print(list); // ���݂̃��X�g�̕\��

	for (int i = 0; i < 10; i++) {
		list->addFirst(list, i); // addFirst �̃e�X�g
		list->addLast(list, i); // addLast �̃e�X�g
	}
	print(list); // ���݂̃��X�g�̕\��

	for (int i = 0; i <= list->size; i += 5) {
		list->insert(list, i, 1000); // insert �̃e�X�g
	}
	print(list); // ���݂̃��X�g�̕\��

	printf("peekFirst: %d, ", list->peekFirst(list)); // peekFirst�̃e�X�g
	printf("pollFirst: %d\n", list->pollFirst(list)); // pollLast�̃e�X�g
	printf("peekLast: %d, ", list->peekLast(list)); // peekLast�̃e�X�g
	printf("pollLast: %d\n\n", list->pollLast(list)); //  pollLast�̃e�X�g
	list->set(list, list->size / 2, 2000);
	print(list); // ���݂̃��X�g�̕\��

	list->free_doubly_linked_list(list); // �������̊J��
	return 0;
}

void print(DoublyLinkedList *list) {
	printf("isEmpty? %s, ", list->isEmpty(list) ? "true" : "false"); // isEmpty �̃e�X�g
	printf("size: %d\n", list->size); // �v�f���̕\��
	printf("List:");
	for (int i = 0; i < list->size; i++) {
		printf(" %d", list->get(list, i));
	}
	printf("\n\n");
}
