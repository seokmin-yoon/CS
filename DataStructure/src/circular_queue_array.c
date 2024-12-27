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

// 원형 큐가 비었는지 확인하는 함수
int isEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

// 원형 큐가 꽉 찼는지 확인하는 함수
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q_SIZE == Q->front);
}

// 원형 큐에 데이터를 삽입하는 함수
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear = (Q->rear + 1) % Q_SIZE;  // rear 순환하도록 처리
		Q->queue[Q->rear] = item;
	}
}

// 원형 큐에서 데이터를 제거하는 함수
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return '\0';
	else {
		Q->front = (Q->front + 1) % Q_SIZE;  // front 순환하도록 처리
		return Q->queue[Q->front];
	}
}

// 원형 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return '\0';
    } else {
        return Q->queue[(Q->front + 1) % Q_SIZE];
    }
}

// 원형 큐의 상태를 출력하는 함수
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