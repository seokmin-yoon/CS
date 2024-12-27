#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} ListNode;

typedef struct LinkedList_h {
	ListNode* head;
} LinkedList_h;

LinkedList_h* createLinkedList_h() {
	LinkedList_h* L;
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(LinkedList_h* L) {
	if (L == NULL || L->head == NULL) return;
	ListNode* p = L->head;
	ListNode* temp;
	do {
		temp = p;
		p = p->link;
		free(temp);
	} while (p != L->head);
	free(L);
}

void printList(LinkedList_h* CL) {
	if (CL == NULL || CL->head == NULL) {
		printf("CL = ()\n");
		return;
	}
	ListNode* p = CL->head;
	printf("CL = (");
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(")\n");
}

// ���� ���� ����Ʈ���� ù ��° ���� �����ϴ� ����
void insertFirstNode(LinkedList_h* CL, const char* x) {
	if (CL == NULL) return;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0';
	if (CL->head == NULL) {
		// ����Ʈ�� ����ִ� ���
		newNode->link = newNode;
		CL->head = newNode;
	}
	else {
		// ����Ʈ�� ��尡 �ִ� ���
		ListNode* temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		temp->link = newNode;
		newNode->link = CL->head;
		CL->head = newNode;
	}
}

// ���� ���� ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(LinkedList_h* CL, ListNode* p) {
	ListNode* pre;

	if (CL->head == NULL || p == NULL) return; // ���� ����Ʈ �Ǵ� ������ ��尡 ���� ��� �ߴ�

	// ����Ʈ�� ��尡 �� ���� �ִ� ���
	if (CL->head == CL->head->link) {
		if (CL->head == p) { // ������ ��尡 ������ �����
			free(CL->head);  // �޸� ����
			CL->head = NULL; // ����Ʈ �ʱ�ȭ
		}
		return;
	}

	// ������ ��尡 ù ��° ����� ���
	if (p == CL->head) {
		// ������ ��带 ã�ƾ� ��
		pre = CL->head;
		while (pre->link != CL->head) {
			pre = pre->link;
		}
		pre->link = CL->head->link; // ������ ��尡 ù ��° ����� ���� ��带 ����Ű���� ����
		CL->head = CL->head->link; // ��� ����
		free(p);                   // ���� ��� �޸� ����
		return;
	}

	// ������ ��尡 ù ��° ��尡 �ƴ� ���
	pre = CL->head;
	while (pre->link != p && pre->link != CL->head) {
		pre = pre->link;
	}

	if (pre->link == p) { // ���� ��带 ã�� ���
		pre->link = p->link; // ���� ���� ���� ����� ���� ��� ����
		free(p);             // ���� ��� �޸� ����
	}
}

int main() {
	LinkedList_h* CL = createLinkedList_h();

	// ���� ���� ����Ʈ�� ��� ����
	insertFirstNode(CL, "��");
	insertFirstNode(CL, "ȭ");
	insertFirstNode(CL, "��");
	printList(CL); // ���: �� ȭ ��

	// ��� ����
	deleteNode(CL, CL->head); // "��" ��� ����
	printList(CL); // ���: ȭ ��

	deleteNode(CL, CL->head); // "ȭ" ��� ����
	printList(CL); // ���: ��

	deleteNode(CL, CL->head); // "��" ��� ����
	printList(CL); // ���: ����Ʈ�� ����ֽ��ϴ�.

	freeLinkedList_h(CL);
	return 0;
}

/*
// ���� ���� ����Ʈ�� ù ��° ���� �����ϴ� ����
void insertFirstNode(LinkedList_h* CL, const char* x) {
	if (CL == NULL) return;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0';
	if (CL->head == NULL) {
		// ����Ʈ�� ����ִ� ���
		newNode->link = newNode;
		CL->head = newNode;
	}
	else {
		// ����Ʈ�� ��尡 �ִ� ���
		ListNode* temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		temp->link = newNode;
		newNode->link = CL->head;
		CL->head = newNode;
	}
}

// ���� ���� ����Ʈ���� pre ��� �ڿ� �����ϴ� ����
void insertMiddleNode(LinkedList_h* CL, ListNode* pre, const char* x) {
	if (CL == NULL || pre == NULL) {
		printf("����: ���� ����Ʈ �Ǵ� pre ��尡 NULL�Դϴ�.\n");
		return;
	}

	// ���ο� ��� ���� �� ������ �ʱ�ȭ
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode) {
		printf("����: �޸� �Ҵ� ����\n");
		return;
	}

	strncpy(newNode->data, x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0'; // ���ڿ� ���� ����

	// ��� ����
	newNode->link = pre->link; // �� ����� ��ũ�� pre�� ���� ���� ����
	pre->link = newNode;       // pre�� ��ũ�� �� ���� ����
}

// ���� ���� ����Ʈ�� ��带 �����ϴ� ���� (������ ����)
void insertNode(LinkedList_h* CL, const char* x) {
	ListNode* newNode;
	ListNode* temp;

	// �� ��� ���� �� ������ ����
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0'; // ���ڿ� ���� ����
	newNode->link = NULL; // �ʱ�ȭ (��� �ִ� ���·� ����)

	if (CL->head == NULL) { // ���� ����Ʈ�� ������ ���
		CL->head = newNode;    // �� ��带 ����Ʈ�� ���� ���� ����
		newNode->link = newNode; // �ڱ� �ڽ��� ����Ű���� ����
	}
	else {
		// ���� ����Ʈ�� ������ �ƴ� ���
		temp = CL->head;
		while (temp->link != CL->head) { // ���� ���� ����Ʈ���� ������ ��� ã��
			temp = temp->link;
		}
		temp->link = newNode; // ������ ����� ���� ���� �� ��� ����
		newNode->link = CL->head; // �� ����� ���� ��带 ����Ʈ�� ���� ���� ����
	}
}

// ���� ���� ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(LinkedList_h* CL, ListNode* p) {
	ListNode* pre;

	if (CL->head == NULL || p == NULL) return; // ���� ����Ʈ �Ǵ� ������ ��尡 ���� ��� �ߴ�

	// ����Ʈ�� ��尡 �� ���� �ִ� ���
	if (CL->head == CL->head->link) {
		if (CL->head == p) { // ������ ��尡 ������ �����
			free(CL->head);  // �޸� ����
			CL->head = NULL; // ����Ʈ �ʱ�ȭ
		}
		return;
	}

	// ������ ��尡 ù ��° ����� ���
	if (p == CL->head) {
		// ������ ��带 ã�ƾ� ��
		pre = CL->head;
		while (pre->link != CL->head) {
			pre = pre->link;
		}
		pre->link = CL->head->link; // ������ ��尡 ù ��° ����� ���� ��带 ����Ű���� ����
		CL->head = CL->head->link; // ��� ����
		free(p);                   // ���� ��� �޸� ����
		return;
	}

	// ������ ��尡 ù ��° ��尡 �ƴ� ���
	pre = CL->head;
	while (pre->link != p && pre->link != CL->head) {
		pre = pre->link;
	}

	if (pre->link == p) { // ���� ��带 ã�� ���
		pre->link = p->link; // ���� ���� ���� ����� ���� ��� ����
		free(p);             // ���� ��� �޸� ����
	}
}
*/