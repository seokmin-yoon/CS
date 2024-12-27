#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
} ListNode;

typedef struct LinkedList_h {
	ListNode* head;
} LinkedList_h;

LinkedList_h* createLinkedList_h() {
	LinkedList_h* DL;
	DL = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	DL->head = NULL;
	return DL;
}

void printList(LinkedList_h* DL) {
	ListNode* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

// ���� ���� ����Ʈ�� ������ ���� �����ϴ� ����
void insertNode(LinkedList_h* DL, const char* x) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0';
	newNode->llink = NULL;  // �� ����� ���� ���� �����Ƿ� NULL�� ����
	newNode->rlink = NULL;  // �� ����� ���� ���� �����Ƿ� NULL�� ����

	if (DL->head == NULL) {
		// ����Ʈ�� ��� �ִ� ��� �� ��带 head�� ����
		DL->head = newNode;
	}
	else {
		// ����Ʈ�� ��� ���� ���� ��� ������ ��带 ã�Ƽ� ����
		ListNode* temp = DL->head;
		while (temp->rlink != NULL) {
			temp = temp->rlink;  // ������ ���� �̵�
		}
		temp->rlink = newNode;   // ������ ����� rlink�� �� ��带 ����Ű���� ����
		newNode->llink = temp;   // �� ����� llink�� ���� ��带 ����Ű���� ����
	}
}

// ���� ���� ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(LinkedList_h* DL, ListNode* p) {
	if (DL->head == NULL || p == NULL) return; // ����Ʈ�� ��� �ְų� ������ ��尡 ����

	// ù ��° ��带 �����ϴ� ���
	if (DL->head == p) {
		DL->head = p->rlink;  // ��带 ���� ���� ����
		if (DL->head != NULL) {  // ����Ʈ�� ��尡 �ϳ� �̻� �����ִٸ�
			DL->head->llink = NULL;  // ���ο� ����� ���� ���� NULL�� ����
		}
		free(p);
		return;
	}

	// ������ ��尡 �߰��̳� ������ ����� ���
	if (p->llink != NULL) {
		p->llink->rlink = p->rlink;  // ���� ����� rlink�� ������ ����� rlink�� ����
	}
	if (p->rlink != NULL) {
		p->rlink->llink = p->llink;  // ���� ����� llink�� ������ ����� llink�� ����
	}

	free(p);  // ��� �޸� ����
}

int main() {
	LinkedList_h* list = createLinkedList_h();

	insertNode(list, "��");
	insertNode(list, "��");
	insertNode(list, "��");

	printf("����Ʈ ����:\n");
	printList(list);

	// "ȭ"�� ����
	ListNode* temp = list->head;
	while (temp != NULL && strcmp(temp->data, "��") != 0) {
		temp = temp->rlink;
	}
	if (temp != NULL) {
		deleteNode(list, temp);
	}

	printf("����Ʈ ����(ȭ ���� ��):\n");
	printList(list);

	free(list);
	return 0;
}
