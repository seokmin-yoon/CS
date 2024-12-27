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
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// ���� ť�� ������� Ȯ���ϴ� �Լ�
int isEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

// ���� ť�� �� á���� Ȯ���ϴ� �Լ�
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q_SIZE == Q->front);
}

// ���� ť�� �����͸� �����ϴ� �Լ�
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear = (Q->rear + 1) % Q_SIZE;  // rear ��ȯ�ϵ��� ó��
		Q->queue[Q->rear] = item;
	}
}

// ���� ť���� �����͸� �����ϴ� �Լ�
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return '\0';
	else {
		Q->front = (Q->front + 1) % Q_SIZE;  // front ��ȯ�ϵ��� ó��
		return Q->queue[Q->front];
	}
}

// ���� ť�� ���� �տ� �ִ� ���Ҹ� �˻��ϴ� ����
element peek(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return '\0';
    } else {
        return Q->queue[(Q->front + 1) % Q_SIZE];
    }
}

// ���� ť�� ���¸� ����ϴ� �Լ�
void printQueue(QueueType* Q) {
	int i, first, last;
	first = (Q->front + 1) % Q_SIZE;
	last = (Q->rear + 1) % Q_SIZE;
	printf("Circular Queue: [");
	i = first;
	while (i != last) {
		printf("%3c", Q->queue[i]);
		i = (i + 1) % Q_SIZE;
	}
	printf("]\n");
}

int main() {
	QueueType* queue = createQueue();

	enQueue(queue, 'A');
	enQueue(queue, 'B');
	enQueue(queue, 'C');

	printQueue(queue);  // A B C

	printf("Dequeued: %c\n", deQueue(queue));  // A

	printQueue(queue);  // B C

	printf("Peek: %c\n", peek(queue));

	return 0;
}