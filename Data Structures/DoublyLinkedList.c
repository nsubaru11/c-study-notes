#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node構造体: 双方向連結リストの各ノードを表します。
 */
typedef struct Node {
	int data; ///< ノードに格納する整数データ
	struct Node *next; ///< 次のノードへのポインタ
	struct Node *prev; ///< 前のノードへのポインタ
} Node;

/**
 * @brief DoublyLinkedList構造体: 双方向連結リストを表します。
 */
typedef struct DoublyLinkedList {
	Node *head; ///< リストの先頭ノードを指すポインタ
	Node *tail; ///< リストの最後のノードを指すポインタ
	int size; ///< リスト内のノード数
	void (*addFirst)(struct DoublyLinkedList *, int); ///< リストの先頭にノードを追加
	void (*addLast)(struct DoublyLinkedList *, int); ///< リストの末尾にノードを追加
	int (*get)(struct DoublyLinkedList *, int); ///< 指定したインデックスのデータを取得
	void (*insert)(struct DoublyLinkedList *, int, int); ///< 指定位置にノードを挿入
	int (*pollFirst)(struct DoublyLinkedList *); ///< 先頭ノードを削除しデータを返す
	int (*pollLast)(struct DoublyLinkedList *); ///< 最後尾ノードを削除しデータを返す
	int (*peekFirst)(struct DoublyLinkedList *); ///< 先頭ノードのデータを取得
	int (*peekLast)(struct DoublyLinkedList *); ///< 最後尾ノードのデータを取得
	void (*print)(struct DoublyLinkedList *); ///< リスト全体を出力
} DoublyLinkedList;

/**
 * @brief 新しいノードを作成します。
 *
 * @param data ノードに格納するデータ
 * @return Node* 作成されたノードへのポインタ
 */
Node *new_Node(int data);

/**
 * @brief 新しい双方向連結リストを作成します。
 *
 * @return DoublyLinkedList* 作成されたリストへのポインタ
 */
DoublyLinkedList *new_DoublyLinkedList(void);

/**
 * @brief リストの先頭にノードを追加します。
 *
 * @param list 双方向連結リスト
 * @param data 追加するノードのデータ
 */
void addFirst(DoublyLinkedList *list, int data);

/**
 * @brief リストの末尾にノードを追加します。
 *
 * @param list 双方向連結リスト
 * @param data 追加するノードのデータ
 */
void addLast(DoublyLinkedList *list, int data);

/**
 * @brief リストの内容をすべて出力します。
 *
 * @param list 双方向連結リスト
 */
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

/**
 * @brief 新しいノードを作成します。
 *
 * @param data ノードに格納するデータ
 * @return Node* 作成されたノードのポインタ
 */
Node *new_Node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/**
 * @brief 新しい双方向連結リストを生成します。
 *
 * @return DoublyLinkedList* 双方向連結リストのポインタ
 */
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

/**
 * @brief リストの先頭にノードを追加します。
 *
 * @param list 双方向連結リスト
 * @param data 追加するデータ
 */
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

/**
 * @brief リストの末尾にノードを追加します。
 *
 * @param list 双方向連結リスト
 * @param data 追加するデータ
 */
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

/**
 * @brief リストの内容を出力します。
 *
 * @param list 双方向連結リスト
 */
void print(const DoublyLinkedList *list) {
	Node *node = list->head;
	printf("List:");
	while (node != NULL) {
		printf(" %d", node->data);
		node = node->next;
	}
	printf("\n");
}
