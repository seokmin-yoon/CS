#include <stdio.h>
#include <stdlib.h>

#define MAX_DEQUE_SIZE 4

typedef char element;

typedef struct {
    element data[MAX_DEQUE_SIZE];
    int front;
    int rear;
} DQueType;

// 순차 데크 생성 함수
DQueType* createDQue() {
    DQueType* DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = 0;
    DQ->rear = 0;
    return DQ;
}

// 순차 데크가 비었는지 확인하는 함수
int isEmpty(DQueType* DQ) {
    return (DQ->front == DQ->rear);
}

// 순차 데크가 가득 찼는지 확인하는 함수
int isFull(DQueType* DQ) {
    return ((DQ->rear + 1) % MAX_DEQUE_SIZE == DQ->front);
}

// 앞에 데이터 삽입하는 함수
void insertFront(DQueType* DQ, element item) {
    if (isFull(DQ)) {
        printf("Array-based Deque is full!\n");
        return;
    }
    DQ->front = (DQ->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    DQ->data[DQ->front] = item;
}

// 뒤에 데이터 삽입하는 함수
void insertRear(DQueType* DQ, element item) {
    if (isFull(DQ)) {
        printf("Array-based Deque is full!\n");
        return;
    }
    DQ->data[DQ->rear] = item;
    DQ->rear = (DQ->rear + 1) % MAX_DEQUE_SIZE;
}

// 앞에서 데이터 제거하는 함수
element deleteFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    element item = DQ->data[DQ->front];
    DQ->front = (DQ->front + 1) % MAX_DEQUE_SIZE;
    return item;
}

// 뒤에서 데이터 제거하는 함수
element deleteRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    DQ->rear = (DQ->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return DQ->data[DQ->rear];
}

// 순차 데크의 앞에 있는 원소 확인하는 함수
element peekFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    return DQ->data[DQ->front];
}

// 순차 데크의 뒤에 있는 원소 확인하는 함수
element peekRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    return DQ->data[(DQ->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE];
}

// 순차 데크 상태 출력 함수
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

    // 앞에 삽입
    insertFront(deque, 'A');
    printDeque(deque);

    // 뒤에 삽입
    insertRear(deque, 'B');
    insertRear(deque, 'C');
    printDeque(deque);

    // 앞에서 제거
    printf("Deleted from front: %c\n", deleteFront(deque));
    printDeque(deque);

    // 뒤에서 제거
    printf("Deleted from rear: %c\n", deleteRear(deque));
    printDeque(deque);

    // 앞의 원소 확인
    printf("Front element: %c\n", peekFront(deque));

    // 뒤의 원소 확인
    printf("Rear element: %c\n", peekRear(deque));

    free(deque);
    return 0;
}
