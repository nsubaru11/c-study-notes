#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

/**
 * @file DoublyLinkedList.h
 * @brief 双方向連結リストの宣言とその操作関数
 */

/**
 * @struct Node
 * @brief 双方向リストの各ノードを表す構造体
 * @var Node::value ノードに格納されるデータ
 * @var Node::next 次のノードへのポインタ
 * @var Node::prev 前のノードへのポインタ
 */
typedef struct Node {
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

/**
 * @struct DoublyLinkedList
 * @brief 双方向連結リスト構造体
 * @var DoublyLinkedList::size リスト内の要素数
 * @var DoublyLinkedList::head 先頭ノードへのポインタ
 * @var DoublyLinkedList::tail 最後尾ノードへのポインタ
 *
 * 操作関数ポインタ群（各種操作をメンバー関数的に利用可能）
 */
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
	void (*free_doubly_linked_list)(struct DoublyLinkedList *);
} DoublyLinkedList;

/**
 * @brief 新しい双方向連結リストを動的に生成・初期化
 * @return DoublyLinkedListへのポインタ
 */
DoublyLinkedList *new_DoublyLinkedList(void);

/**
 * @brief リストの先頭に新しいノードを追加
 * @param list 操作対象のリスト
 * @param value 追加する値
 */
void addFirst(DoublyLinkedList *list, int value);

/**
 * @brief リストの末尾に新しいノードを追加
 * @param list 操作対象のリスト
 * @param value 追加する値
 */
void addLast(DoublyLinkedList *list, int value);

/**
 * @brief 指定インデックスのノードから値を取得
 * @param list 操作対象のリスト
 * @param index 取得したいノードのインデックス（0始まり）
 * @return インデックス位置の値
 */
int get(DoublyLinkedList *list, int index);

/**
 * @brief 指定位置にノードを挿入
 * @param list 操作対象のリスト
 * @param index 挿入する位置
 * @param value 挿入する値
 */
void insert(DoublyLinkedList *list, int index, int value);

/**
 * @brief 先頭ノードを削除し、その値を返す
 * @param list 操作対象のリスト
 * @return 削除ノードの値
 */
int pollFirst(DoublyLinkedList *list);

/**
 * @brief 最後尾ノードを削除し、その値を返す
 * @param list 操作対象のリスト
 * @return 削除ノードの値
 */
int pollLast(DoublyLinkedList *list);

/**
 * @brief 先頭ノードの値を取得（削除しない）
 * @param list 操作対象のリスト
 * @return 先頭ノードの値
 */
int peekFirst(DoublyLinkedList *list);

/**
 * @brief 最後尾ノードの値を取得（削除しない）
 * @param list 操作対象のリスト
 * @return 最後尾ノードの値
 */
int peekLast(DoublyLinkedList *list);

/**
 * @brief リストが空かどうかを確認
 * @param list 操作対象のリスト
 * @retval 1 空
 * @retval 0 空ではない
 */
int isEmpty(const DoublyLinkedList *list);

/**
 * @brief 指定インデックスのノードの値を変更
 * @param list 操作対象のリスト
 * @param index 変更するノードのインデックス
 * @param value 新しい値
 */
void set(DoublyLinkedList *list, int index, int value);

/**
 * @brief リストと各ノードのメモリを解放
 * @param list 操作対象のリスト
 */
void free_doubly_linked_list(DoublyLinkedList *list);

#endif