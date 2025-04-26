#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief �V�����m�[�h�𓮓I�ɐ�������
 * @param value �m�[�h�Ɋi�[����l
 * @return �������ꂽNode�ւ̃|�C���^
 */
Node *new_Node(const int value) {
	Node *node = malloc(sizeof(Node));
	node->value = value;
	node->next = node->prev = nullptr;
	return node;
}

/**
 * @brief �S�Ẵm�[�h���������
 * @param node ����J�n�m�[�h
 */
void free_nodes(Node *node) {
	while (node) {
		Node *next = node->next;
		free(node);
		node = next;
	}
}

/**
 * @brief �V�����o�����A�����X�g�𐶐����A�֐��|�C���^���Z�b�g����
 * @return �������ς�DoublyLinkedList�ւ̃|�C���^
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
 * @brief ���X�g�̐擪�Ƀm�[�h��ǉ�����
 * @param list ����Ώۂ̃��X�g
 * @param value �ǉ�����l
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
 * @brief ���X�g�̖����Ƀm�[�h��ǉ�����
 * @param list ����Ώۂ̃��X�g
 * @param value �ǉ�����l
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
 * @brief �w��C���f�b�N�X�̃m�[�h�̒l���擾����
 * @param list ����Ώۂ̃��X�g
 * @param index �擾����ʒu
 * @return �w��m�[�h�̒l
 * @attention �͈͊O�A�N�Z�X���I��
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
 * @brief �w��ʒu�Ƀm�[�h��}��
 * @param list ����Ώۂ̃��X�g
 * @param index �}������ʒu
 * @param value �}������l
 * @attention �͈͊O�̏ꍇ�I��
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
 * @brief ���X�g���󂩔���
 * @param list ���肷�郊�X�g
 * @retval 1 ��
 * @retval 0 ��łȂ�
 */
int isEmpty(const DoublyLinkedList *list) { return list->size == 0; }

/**
 * @brief �擪�m�[�h���폜�����̃f�[�^��Ԃ�
 * @param list ����Ώۂ̃��X�g
 * @return �폜�����m�[�h�̒l
 * @attention �󃊃X�g���I��
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
 * @brief �Ō���m�[�h���폜�����̃f�[�^��Ԃ�
 * @param list ����Ώۂ̃��X�g
 * @return �폜�����m�[�h�̒l
 * @attention �󃊃X�g���I��
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
 * @brief �擪�m�[�h�̒l���擾
 * @param list ����Ώۂ̃��X�g
 * @return �擪�m�[�h�̒l
 * @attention �󃊃X�g���I��
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
 * @brief �Ō���m�[�h�̒l���擾
 * @param list ����Ώۂ̃��X�g
 * @return �Ō���m�[�h�̒l
 * @attention �󃊃X�g���I��
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
 * @brief �w��C���f�b�N�X�̃m�[�h�̒l��ύX����
 * @param list ����Ώۂ̃��X�g
 * @param index �ύX����ʒu
 * @param value �V�����l
 * @attention �͈͊O�Ŏ��s���I��
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
 * @brief �o�����A�����X�g�ƑS�m�[�h���������
 * @param list ����Ώۃ��X�g
 */
void free_doubly_linked_list(DoublyLinkedList *list) {
	if (list == nullptr)
		return;
	free_nodes(list->head);
	free(list);
}