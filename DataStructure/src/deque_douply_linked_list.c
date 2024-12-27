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

// 연결 데크가 비었는지 확인하는 함수
int isEmpty(DQueType* DQ) {
	return (DQ->front == NULL);
}

// 앞에 데이터 삽입하는 함수
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

// 뒤에 데이터 삽입하는 함수
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

// 앞에서 데이터 제거하는 함수
element deleteFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }

    DQNode* temp = DQ->front;
    element item = temp->data;
    DQ->front = DQ->front->rlink;

    if (DQ->front == NULL) {
        DQ->rear = NULL;  // 데크가 비어있으면 rear도 NULL
    }
    else {
        DQ->front->llink = NULL;
    }

    free(temp);
    return item;
}

// 뒤에서 데이터 제거하는 함수
element deleteRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }

    DQNode* temp = DQ->rear;
    element item = temp->data;
    DQ->rear = DQ->rear->llink;

    if (DQ->rear == NULL) {
        DQ->front = NULL;  // 데크가 비어있으면 front도 NULL
    }
    else {
        DQ->rear->rlink = NULL;
    }

    free(temp);
    return item;
}

// 연결 데크의 앞에 있는 원소 확인하는 함수
element peekFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }
    return DQ->front->data;
}

// 연결 데크의 뒤에 있는 원소 확인하는 함수
element peekRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }
    return DQ->rear->data;
}

// 연결 데크 상태 출력 함수
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

    return 0;
}