#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 4

typedef char element;

typedef struct {
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue() {
	QueueType* Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

// ���� ť�� ������� Ȯ���ϴ� �Լ�
int isEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

// ���� ť�� �� á���� Ȯ���ϴ� �Լ�
int isFull(QueueType* Q) {
	return (Q->rear == Q_SIZE - 1);
}

// ���� ť�� �����͸� �����ϴ� �Լ�
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

// ���� ť���� �����͸� �����ϴ� �Լ�
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peek(QueueType* Q) {
	if (isEmpty(Q)) return;
	else return Q->queue[Q->front + 1];
}

// ���� ť�� ���¸� ����ϴ� �Լ�
void printQueue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Queue is empty!\n");
		return;
	}
	printf("Queue elements: ");
	for (int i = Q->front + 1; i <= Q->rear; i++) {
		printf("%c ", Q->queue[i]);
	}
	printf("\n");
}

int main() {
	QueueType* queue = createQueue();

	enQueue(queue, 'A');
	enQueue(queue, 'B');
	enQueue(queue, 'C');

	printQueue(queue);  // A B C

	printf("Dequeued: %c\n", deQueue(queue));  // A

	printQueue(queue);  // B C

	return 0;
}