#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

/**
 * @file DoublyLinkedList.h
 * @brief �o�����A�����X�g�̐錾�Ƃ��̑���֐�
 */

/**
 * @struct Node
 * @brief �o�������X�g�̊e�m�[�h��\���\����
 * @var Node::value �m�[�h�Ɋi�[�����f�[�^
 * @var Node::next ���̃m�[�h�ւ̃|�C���^
 * @var Node::prev �O�̃m�[�h�ւ̃|�C���^
 */
typedef struct Node {
	int value;
	struct Node *next;
	struct Node *prev;
} Node;

/**
 * @struct DoublyLinkedList
 * @brief �o�����A�����X�g�\����
 * @var DoublyLinkedList::size ���X�g���̗v�f��
 * @var DoublyLinkedList::head �擪�m�[�h�ւ̃|�C���^
 * @var DoublyLinkedList::tail �Ō���m�[�h�ւ̃|�C���^
 *
 * ����֐��|�C���^�Q�i�e�푀��������o�[�֐��I�ɗ��p�\�j
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
 * @brief �V�����o�����A�����X�g�𓮓I�ɐ����E������
 * @return DoublyLinkedList�ւ̃|�C���^
 */
DoublyLinkedList *new_DoublyLinkedList(void);

/**
 * @brief ���X�g�̐擪�ɐV�����m�[�h��ǉ�
 * @param list ����Ώۂ̃��X�g
 * @param value �ǉ�����l
 */
void addFirst(DoublyLinkedList *list, int value);

/**
 * @brief ���X�g�̖����ɐV�����m�[�h��ǉ�
 * @param list ����Ώۂ̃��X�g
 * @param value �ǉ�����l
 */
void addLast(DoublyLinkedList *list, int value);

/**
 * @brief �w��C���f�b�N�X�̃m�[�h����l���擾
 * @param list ����Ώۂ̃��X�g
 * @param index �擾�������m�[�h�̃C���f�b�N�X�i0�n�܂�j
 * @return �C���f�b�N�X�ʒu�̒l
 */
int get(DoublyLinkedList *list, int index);

/**
 * @brief �w��ʒu�Ƀm�[�h��}��
 * @param list ����Ώۂ̃��X�g
 * @param index �}������ʒu
 * @param value �}������l
 */
void insert(DoublyLinkedList *list, int index, int value);

/**
 * @brief �擪�m�[�h���폜���A���̒l��Ԃ�
 * @param list ����Ώۂ̃��X�g
 * @return �폜�m�[�h�̒l
 */
int pollFirst(DoublyLinkedList *list);

/**
 * @brief �Ō���m�[�h���폜���A���̒l��Ԃ�
 * @param list ����Ώۂ̃��X�g
 * @return �폜�m�[�h�̒l
 */
int pollLast(DoublyLinkedList *list);

/**
 * @brief �擪�m�[�h�̒l���擾�i�폜���Ȃ��j
 * @param list ����Ώۂ̃��X�g
 * @return �擪�m�[�h�̒l
 */
int peekFirst(DoublyLinkedList *list);

/**
 * @brief �Ō���m�[�h�̒l���擾�i�폜���Ȃ��j
 * @param list ����Ώۂ̃��X�g
 * @return �Ō���m�[�h�̒l
 */
int peekLast(DoublyLinkedList *list);

/**
 * @brief ���X�g���󂩂ǂ������m�F
 * @param list ����Ώۂ̃��X�g
 * @retval 1 ��
 * @retval 0 ��ł͂Ȃ�
 */
int isEmpty(const DoublyLinkedList *list);

/**
 * @brief �w��C���f�b�N�X�̃m�[�h�̒l��ύX
 * @param list ����Ώۂ̃��X�g
 * @param index �ύX����m�[�h�̃C���f�b�N�X
 * @param value �V�����l
 */
void set(DoublyLinkedList *list, int index, int value);

/**
 * @brief ���X�g�Ɗe�m�[�h�̃����������
 * @param list ����Ώۂ̃��X�g
 */
void free_doubly_linked_list(DoublyLinkedList *list);

#endif