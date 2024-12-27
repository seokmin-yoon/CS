#include <stdio.h>
#include <malloc.h>

typedef char element;

typedef struct DQNode {
	element data;
	struct DQNode* llink;
	struct DQNode* rlink;
} DQNode;

typedef struct {
	DQNode* front, * rear;
} DQueType;

DQueType* createDQue() {
	DQueType* DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ���� ��ũ�� ������� Ȯ���ϴ� �Լ�
int isEmpty(DQueType* DQ) {
	return (DQ->front == NULL);
}

// �տ� ������ �����ϴ� �Լ�
void insertFront(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->llink = NULL;
    newNode->rlink = DQ->front;

    if (isEmpty(DQ)) {
        DQ->front = DQ->rear = newNode;
    }
    else {
        DQ->front->llink = newNode;
        DQ->front = newNode;
    }
}

// �ڿ� ������ �����ϴ� �Լ�
void insertRear(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->rlink = NULL;
    newNode->llink = DQ->rear;

    if (isEmpty(DQ)) {
        DQ->front = DQ->rear = newNode;
    }
    else {
        DQ->rear->rlink = newNode;
        DQ->rear = newNode;
    }
}

// �տ��� ������ �����ϴ� �Լ�
element deleteFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }

    DQNode* temp = DQ->front;
    element item = temp->data;
    DQ->front = DQ->front->rlink;

    if (DQ->front == NULL) {
        DQ->rear = NULL;  // ��ũ�� ��������� rear�� NULL
    }
    else {
        DQ->front->llink = NULL;
    }

    free(temp);
    return item;
}

// �ڿ��� ������ �����ϴ� �Լ�
element deleteRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }

    DQNode* temp = DQ->rear;
    element item = temp->data;
    DQ->rear = DQ->rear->llink;

    if (DQ->rear == NULL) {
        DQ->front = NULL;  // ��ũ�� ��������� front�� NULL
    }
    else {
        DQ->rear->rlink = NULL;
    }

    free(temp);
    return item;
}

// ���� ��ũ�� �տ� �ִ� ���� Ȯ���ϴ� �Լ�
element peekFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }
    return DQ->front->data;
}

// ���� ��ũ�� �ڿ� �ִ� ���� Ȯ���ϴ� �Լ�
element peekRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }
    return DQ->rear->data;
}

// ���� ��ũ ���� ��� �Լ�
void printDeque(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return;
    }

    DQNode* temp = DQ->front;
    printf("Linked Deque elements: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->rlink;
    }
    printf("\n");
}

int main() {
    DQueType* deque = createDQue();

    // �տ� ����
    insertFront(deque, 'A');
    printDeque(deque);  

    // �ڿ� ����
    insertRear(deque, 'B');
    insertRear(deque, 'C');
    printDeque(deque);

    // �տ��� ����
    printf("Deleted from front: %c\n", deleteFront(deque));  
    printDeque(deque);  

    // �ڿ��� ����
    printf("Deleted from rear: %c\n", deleteRear(deque));  
    printDeque(deque);  

    // ���� ���� Ȯ��
    printf("Front element: %c\n", peekFront(deque));  

    // ���� ���� Ȯ��
    printf("Rear element: %c\n", peekRear(deque));  

    return 0;
}