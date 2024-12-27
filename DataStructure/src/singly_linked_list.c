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
    LinkedList_h* L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList_h(LinkedList_h* L) {
    ListNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
}

void printList(LinkedList_h* L) {
    ListNode* p = L->head;
    printf("L = (");
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

// �ܼ� ���� ����Ʈ�� ������ ���� �����ϴ� ����
void insertNode(LinkedList_h* L, const char* x) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0';
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    ListNode* temp = L->head;
    while (temp->link != NULL) temp = temp->link; // ������ ���� �̵�
    temp->link = newNode;
}

// �ܼ� ���� ����Ʈ���� ��� p�� �����ϴ� ����
void deleteNode(LinkedList_h* L, ListNode* p) {
    if (L->head == NULL || p == NULL) return; // ����Ʈ�� ��� �ְų� ������ ��尡 ����

    if (L->head == p) {  // ������ ��尡 ù ��° ����� ���
        L->head = p->link;  // ��带 ���� ���� ����
        free(p);
        return;
    }

    // ��带 ã�� ���� ���� ��� ã��
    ListNode* pre = L->head;
    while (pre->link != NULL && pre->link != p) {
        pre = pre->link;
    }

    if (pre->link == p) {  // p�� ã���� ���
        pre->link = p->link;  // ���� ���� ���� ����� ��ũ�� ����
        free(p);  // ��� �޸� ����
    }
}

int main() {
    LinkedList_h* list = createLinkedList_h();

    insertNode(list, "��");
    insertNode(list, "ȭ");
    insertNode(list, "��");

    printf("�ʱ� ����Ʈ:\n");
    printList(list);

    // "ȭ" �����ϱ�
    ListNode* temp = list->head;
    while (temp != NULL && strcmp(temp->data, "ȭ") != 0) {
        temp = temp->link;
    }

    if (temp != NULL) {
        deleteNode(list, temp);  // "ȭ" ��� ����
        printf("��� ȭ ���� ��:\n");
        printList(list);
    }
    else {
        printf("������ ��带 ã�� �� �����ϴ�.\n");
    }

    freeLinkedList_h(list);
    free(list);

    return 0;
}
