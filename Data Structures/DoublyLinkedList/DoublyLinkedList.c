#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 新しいノードを動的に生成する
 * @param value ノードに格納する値
 * @return 生成されたNodeへのポインタ
 */
Node *new_Node(const int value) {
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->next = node->prev = nullptr;
	return node;
}

/**
 * @brief 全てのノードを解放する
 * @param node 解放開始ノード
 */
void free_nodes(Node *node) {
	while (node) {
		Node *next = node->next;
		free(node);
		node = next;
	}
}

/**
 * @brief 新しい双方向連結リストを生成し、関数ポインタをセットする
 * @return 初期化済みDoublyLinkedListへのポインタ
 */
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
	list->free_doubly_linked_list = free_doubly_linked_list;
	return list;
}

/**
 * @brief リストの先頭にノードを追加する
 * @param list 操作対象のリスト
 * @param value 追加する値
 */
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

/**
 * @brief リストの末尾にノードを追加する
 * @param list 操作対象のリスト
 * @param value 追加する値
 */
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

/**
 * @brief 指定インデックスのノードの値を取得する
 * @param list 操作対象のリスト
 * @param index 取得する位置
 * @return 指定ノードの値
 * @attention 範囲外アクセス時終了
 */
int get(DoublyLinkedList *list, const int index) {
	const int size = list->size;
	if (index < 0 || size <= index) {
		printf("IndexOutOfBoundsException %d\n", index);
		list->free_doubly_linked_list(list);
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

/**
 * @brief 指定位置にノードを挿入
 * @param list 操作対象のリスト
 * @param index 挿入する位置
 * @param value 挿入する値
 * @attention 範囲外の場合終了
 */
void insert(DoublyLinkedList *list, const int index, const int value) {
	const int size = list->size;
	if (index < 0 || size < index) {
		printf("IndexOutOfBoundsException %d\n", index);
		list->free_doubly_linked_list(list);
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

/**
 * @brief リストが空か判定
 * @param list 判定するリスト
 * @retval 1 空
 * @retval 0 空でない
 */
int isEmpty(const DoublyLinkedList *list) { return list->size == 0; }

/**
 * @brief 先頭ノードを削除しそのデータを返す
 * @param list 操作対象のリスト
 * @return 削除したノードの値
 * @attention 空リスト時終了
 */
int pollFirst(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->free_doubly_linked_list(list);
		exit(-1);
	}
	Node *head = list->head;
	const int data = head->value;
	if (list->size > 1) {
		list->head = head->next;
		list->head->prev = nullptr;
	} else {
		list->head = list->tail = nullptr;
	}
	list->size--;
	free(head);
	return data;
}

/**
 * @brief 最後尾ノードを削除しそのデータを返す
 * @param list 操作対象のリスト
 * @return 削除したノードの値
 * @attention 空リスト時終了
 */
int pollLast(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->free_doubly_linked_list(list);
		exit(-1);
	}
	Node *tail = list->tail;
	const int data = tail->value;
	if (list->size > 1) {
		list->tail = tail->prev;
		list->tail->next = nullptr;
	} else {
		list->head = list->tail = nullptr;
	}
	free(tail);
	list->size--;
	return data;
}

/**
 * @brief 先頭ノードの値を取得
 * @param list 操作対象のリスト
 * @return 先頭ノードの値
 * @attention 空リスト時終了
 */
int peekFirst(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->free_doubly_linked_list(list);
		exit(-1);
	}
	return list->head->value;
}

/**
 * @brief 最後尾ノードの値を取得
 * @param list 操作対象のリスト
 * @return 最後尾ノードの値
 * @attention 空リスト時終了
 */
int peekLast(DoublyLinkedList *list) {
	if (list->isEmpty(list)) {
		printf("List is empty\n");
		list->free_doubly_linked_list(list);
		exit(-1);
	}
	return list->tail->value;
}

/**
 * @brief 指定インデックスのノードの値を変更する
 * @param list 操作対象のリスト
 * @param index 変更する位置
 * @param value 新しい値
 * @attention 範囲外で実行時終了
 */
void set(DoublyLinkedList *list, const int index, const int value) {
	const int size = list->size;
	if (index < 0 || size < index) {
		printf("IndexOutOfBoundsException %d\n", index);
		list->free_doubly_linked_list(list);
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

/**
 * @brief 双方向連結リストと全ノードを解放する
 * @param list 操作対象リスト
 */
void free_doubly_linked_list(DoublyLinkedList *list) {
	if (list == nullptr)
		return;
	free_nodes(list->head);
	free(list);
}