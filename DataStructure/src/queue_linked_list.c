#include <stdio.h>
#include <malloc.h>

typedef char element;

typedef struct QNode {
	element data;
	struct QNode* link;
} QNode;

typedef struct {
	QNode* front, *rear;
} LQueueType;

LQueueType* createLinkedQueue() {
	LQueueType* LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// 연결 큐가 비었는지 확인하는 함수
int isEmpty(LQueueType* LQ) {
	return (LQ->front == NULL);
}

// 연결 큐에 데이터 삽입하는 함수
void enQueue(LQueueType* LQ, element item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;

    if (isEmpty(LQ)) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

// 연결 큐에서 데이터 제거하는 함수
element deQueue(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return '\0';
    }

    QNode* temp = LQ->front;
    element item = temp->data;
    LQ->front = LQ->front->link;

    if (LQ->front == NULL) {
        LQ->rear = NULL;  // 큐가 비어 있으면 rear도 NULL로 설정
    }

    free(temp);
    return item;
}

// 연결 큐의 가장 앞에 있는 원소를 확인하는 함수
element peek(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return '\0';
    }
    return LQ->front->data;
}

// 연결 큐의 상태를 출력하는 함수
void printQueue(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return;
    }

    QNode* temp = LQ->front;
    printf("Linked Queue elements: ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    LQueueType* queue = createLinkedQueue();

    enQueue(queue, 'A');
    enQueue(queue, 'B');
    enQueue(queue, 'C');
    enQueue(queue, 'D');

    printQueue(queue);  

    printf("Dequeued: %c\n", deQueue(queue));  

    printQueue(queue); 

    return 0;
}



