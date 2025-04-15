#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Node�\����: �o�����A�����X�g�̊e�m�[�h��\���܂��B
 */
typedef struct Node {
	int data; ///< �m�[�h�Ɋi�[���鐮���f�[�^
	struct Node *next; ///< ���̃m�[�h�ւ̃|�C���^
	struct Node *prev; ///< �O�̃m�[�h�ւ̃|�C���^
} Node;

/**
 * @brief DoublyLinkedList�\����: �o�����A�����X�g��\���܂��B
 */
typedef struct DoublyLinkedList {
	Node *head; ///< ���X�g�̐擪�m�[�h���w���|�C���^
	Node *tail; ///< ���X�g�̍Ō�̃m�[�h���w���|�C���^
	int size; ///< ���X�g���̃m�[�h��
	void (*addFirst)(struct DoublyLinkedList *, int); ///< ���X�g�̐擪�Ƀm�[�h��ǉ�
	void (*addLast)(struct DoublyLinkedList *, int); ///< ���X�g�̖����Ƀm�[�h��ǉ�
	int (*get)(struct DoublyLinkedList *, int); ///< �w�肵���C���f�b�N�X�̃f�[�^���擾
	void (*insert)(struct DoublyLinkedList *, int, int); ///< �w��ʒu�Ƀm�[�h��}��
	int (*pollFirst)(struct DoublyLinkedList *); ///< �擪�m�[�h���폜���f�[�^��Ԃ�
	int (*pollLast)(struct DoublyLinkedList *); ///< �Ō���m�[�h���폜���f�[�^��Ԃ�
	int (*peekFirst)(struct DoublyLinkedList *); ///< �擪�m�[�h�̃f�[�^���擾
	int (*peekLast)(struct DoublyLinkedList *); ///< �Ō���m�[�h�̃f�[�^���擾
	void (*print)(struct DoublyLinkedList *); ///< ���X�g�S�̂��o��
} DoublyLinkedList;

/**
 * @brief �V�����m�[�h���쐬���܂��B
 *
 * @param data �m�[�h�Ɋi�[����f�[�^
 * @return Node* �쐬���ꂽ�m�[�h�ւ̃|�C���^
 */
Node *new_Node(int data);

/**
 * @brief �V�����o�����A�����X�g���쐬���܂��B
 *
 * @return DoublyLinkedList* �쐬���ꂽ���X�g�ւ̃|�C���^
 */
DoublyLinkedList *new_DoublyLinkedList(void);

/**
 * @brief ���X�g�̐擪�Ƀm�[�h��ǉ����܂��B
 *
 * @param list �o�����A�����X�g
 * @param data �ǉ�����m�[�h�̃f�[�^
 */
void addFirst(DoublyLinkedList *list, int data);

/**
 * @brief ���X�g�̖����Ƀm�[�h��ǉ����܂��B
 *
 * @param list �o�����A�����X�g
 * @param data �ǉ�����m�[�h�̃f�[�^
 */
void addLast(DoublyLinkedList *list, int data);

/**
 * @brief ���X�g�̓��e�����ׂďo�͂��܂��B
 *
 * @param list �o�����A�����X�g
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
 * @brief �V�����m�[�h���쐬���܂��B
 *
 * @param data �m�[�h�Ɋi�[����f�[�^
 * @return Node* �쐬���ꂽ�m�[�h�̃|�C���^
 */
Node *new_Node(int data) {
	Node *node = malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

/**
 * @brief �V�����o�����A�����X�g�𐶐����܂��B
 *
 * @return DoublyLinkedList* �o�����A�����X�g�̃|�C���^
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
 * @brief ���X�g�̐擪�Ƀm�[�h��ǉ����܂��B
 *
 * @param list �o�����A�����X�g
 * @param data �ǉ�����f�[�^
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
 * @brief ���X�g�̖����Ƀm�[�h��ǉ����܂��B
 *
 * @param list �o�����A�����X�g
 * @param data �ǉ�����f�[�^
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
 * @brief ���X�g�̓��e���o�͂��܂��B
 *
 * @param list �o�����A�����X�g
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
