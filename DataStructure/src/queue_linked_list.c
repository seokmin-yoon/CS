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

// ���� ť�� ������� Ȯ���ϴ� �Լ�
int isEmpty(LQueueType* LQ) {
	return (LQ->front == NULL);
}

// ���� ť�� ������ �����ϴ� �Լ�
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

// ���� ť���� ������ �����ϴ� �Լ�
element deQueue(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return '\0';
    }

    QNode* temp = LQ->front;
    element item = temp->data;
    LQ->front = LQ->front->link;

    if (LQ->front == NULL) {
        LQ->rear = NULL;  // ť�� ��� ������ rear�� NULL�� ����
    }

    free(temp);
    return item;
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� Ȯ���ϴ� �Լ�
element peek(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return '\0';
    }
    return LQ->front->data;
}

// ���� ť�� ���¸� ����ϴ� �Լ�
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



