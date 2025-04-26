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
void addFirst(DoublyLinkedList *, int); ///< ���X�g�̐擪�Ƀm�[�h��ǉ�
void addLast(DoublyLinkedList *, int); ///< ���X�g�̖����Ƀm�[�h��ǉ�
int get(DoublyLinkedList *, int); ///< �w�肵���C���f�b�N�X�̃f�[�^���擾
void insert(DoublyLinkedList *, int, int); ///< �w��ʒu�Ƀm�[�h��}��
int pollFirst(DoublyLinkedList *); ///< �擪�m�[�h���폜���f�[�^��Ԃ�
int pollLast(DoublyLinkedList *); ///< �Ō���m�[�h���폜���f�[�^��Ԃ�
int peekFirst(DoublyLinkedList *); ///< �擪�m�[�h�̃f�[�^���擾
int peekLast(DoublyLinkedList *); ///< �Ō���m�[�h�̃f�[�^���擾
int isEmpty(const DoublyLinkedList *); ///< ���X�g���󂩂ǂ������擾
void set(DoublyLinkedList *, int, int); ///< ���X�g�̓���̃C���f�b�N�X�̒l��ς���
void destroy(DoublyLinkedList *); ///< ���X�g��j��

#endif
