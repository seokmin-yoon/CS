#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 4

typedef char element;

typedef struct {
    element data[MAX_DEQUE_SIZE];
    int front;
    int rear;
} DQueType;

// ���� ��ũ ���� �Լ�
DQueType* createDQue() {
    DQueType* DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = 0;
    DQ->rear = 0;
    return DQ;
}

// ���� ��ũ�� ������� Ȯ���ϴ� �Լ�
int isEmpty(DQueType* DQ) {
    return (DQ->front == DQ->rear);
}

// ���� ��ũ�� ���� á���� Ȯ���ϴ� �Լ�
int isFull(DQueType* DQ) {
    return ((DQ->rear + 1) % MAX_DEQUE_SIZE == DQ->front);
}

// �տ� ������ �����ϴ� �Լ�
void insertFront(DQueType* DQ, element item) {
    if (isFull(DQ)) {
        printf("Array-based Deque is full!\n");
        return;
    }
    DQ->front = (DQ->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    DQ->data[DQ->front] = item;
}

// �ڿ� ������ �����ϴ� �Լ�
void insertRear(DQueType* DQ, element item) {
    if (isFull(DQ)) {
        printf("Array-based Deque is full!\n");
        return;
    }
    DQ->data[DQ->rear] = item;
    DQ->rear = (DQ->rear + 1) % MAX_DEQUE_SIZE;
}

// �տ��� ������ �����ϴ� �Լ�
element deleteFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    element item = DQ->data[DQ->front];
    DQ->front = (DQ->front + 1) % MAX_DEQUE_SIZE;
    return item;
}

// �ڿ��� ������ �����ϴ� �Լ�
element deleteRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    DQ->rear = (DQ->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return DQ->data[DQ->rear];
}

// ���� ��ũ�� �տ� �ִ� ���� Ȯ���ϴ� �Լ�
element peekFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    return DQ->data[DQ->front];
}

// ���� ��ũ�� �ڿ� �ִ� ���� Ȯ���ϴ� �Լ�
element peekRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    return DQ->data[(DQ->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE];
}

// ���� ��ũ ���� ��� �Լ�
void printDeque(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return;
    }
    printf("Array-based Deque elements: ");
    int i = DQ->front;
    while (i != DQ->rear) {
        printf("%c ", DQ->data[i]);
        i = (i + 1) % MAX_DEQUE_SIZE;
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

    free(deque);
    return 0;
}
