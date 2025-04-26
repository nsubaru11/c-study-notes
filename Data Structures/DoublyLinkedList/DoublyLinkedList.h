#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

typedef struct Node {
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

typedef struct DoublyLinkedList {
	int size;
	Node *head, *tail;
	void (*addFirst)(struct DoublyLinkedList *, int);
	void (*addLast)(struct DoublyLinkedList *, int);
	int (*get)(struct DoublyLinkedList *, int);
	void (*insert)(struct DoublyLinkedList *, int, int);
	int (*pollFirst)(struct DoublyLinkedList *);
	int (*pollLast)(struct DoublyLinkedList *);
	int (*peekFirst)(struct DoublyLinkedList *);
	int (*peekLast)(struct DoublyLinkedList *);
	int (*isEmpty)(const struct DoublyLinkedList *);
	void (*set)(struct DoublyLinkedList *, int, int);
	void (*destroy)(struct DoublyLinkedList *);
} DoublyLinkedList;

DoublyLinkedList *new_DoublyLinkedList();
void addFirst(DoublyLinkedList *, int); ///< リストの先頭にノードを追加
void addLast(DoublyLinkedList *, int); ///< リストの末尾にノードを追加
int get(DoublyLinkedList *, int); ///< 指定したインデックスのデータを取得
void insert(DoublyLinkedList *, int, int); ///< 指定位置にノードを挿入
int pollFirst(DoublyLinkedList *); ///< 先頭ノードを削除しデータを返す
int pollLast(DoublyLinkedList *); ///< 最後尾ノードを削除しデータを返す
int peekFirst(DoublyLinkedList *); ///< 先頭ノードのデータを取得
int peekLast(DoublyLinkedList *); ///< 最後尾ノードのデータを取得
int isEmpty(const DoublyLinkedList *); ///< リストが空かどうかを取得
void set(DoublyLinkedList *, int, int); ///< リストの特定のインデックスの値を変える
void destroy(DoublyLinkedList *); ///< リストを破棄

#endif
