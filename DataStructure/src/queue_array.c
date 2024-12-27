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

// 순차 큐가 비었는지 확인하는 함수
int isEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

// 순차 큐가 꽉 찼는지 확인하는 함수
int isFull(QueueType* Q) {
	return (Q->rear == Q_SIZE - 1);
}

// 순차 큐에 데이터를 삽입하는 함수
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

// 순차 큐에서 데이터를 제거하는 함수
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

// 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType* Q) {
	if (isEmpty(Q)) return;
	else return Q->queue[Q->front + 1];
}

// 순차 큐의 상태를 출력하는 함수
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