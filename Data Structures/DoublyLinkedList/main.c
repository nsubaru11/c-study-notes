#include <stdio.h>
#include "DoublyLinkedList.h"

void print(DoublyLinkedList *list);

int main(void) {
	DoublyLinkedList *list = new_DoublyLinkedList(); // 初期化
	print(list); // 現在のリストの表示

	for (int i = 0; i < 10; i++) {
		list->addFirst(list, i); // addFirst のテスト
		list->addLast(list, i); // addLast のテスト
	}
	print(list); // 現在のリストの表示

	for (int i = 0; i <= list->size; i += 5) {
		list->insert(list, i, 1000); // insert のテスト
	}
	print(list); // 現在のリストの表示

	printf("peekFirst: %d, ", list->peekFirst(list)); // peekFirstのテスト
	printf("pollFirst: %d\n", list->pollFirst(list)); // pollLastのテスト
	printf("peekLast: %d, ", list->peekLast(list)); // peekLastのテスト
	printf("pollLast: %d\n\n", list->pollLast(list)); //  pollLastのテスト
	list->set(list, list->size / 2, 2000);
	print(list); // 現在のリストの表示

	list->free_doubly_linked_list(list); // メモリの開放
	return 0;
}

void print(DoublyLinkedList *list) {
	printf("isEmpty? %s, ", list->isEmpty(list) ? "true" : "false"); // isEmpty のテスト
	printf("size: %d\n", list->size); // 要素数の表示
	printf("List:");
	for (int i = 0; i < list->size; i++) {
		printf(" %d", list->get(list, i));
	}
	printf("\n\n");
}
