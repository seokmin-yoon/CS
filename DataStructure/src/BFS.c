#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
} graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX]; // ������ ���� �湮 ǥ�ø� ���� �迭
} graphType;

typedef int element;

typedef struct QNode {
	int data;
	struct QNode* link;
} QNode;

typedef struct {
	QNode* front, * rear;
} LQueueType;

LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// ���� ť�� ������� Ȯ���ϴ� �Լ�
int isEmpty(LQueueType* LQ) {
    if (LQ->front == NULL) return TRUE;
    return FALSE;
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

// �ʺ� �켱 Ž���� ���� �ʱ� ���� �׷����� �����ϴ� ����
void createGraph(graphType* g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}

// �׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("�׷��� ������ ������ �ʰ��Ͽ����ϴ�.\n");
		return;
	}
	g->n++; // �׷��� ���� ���� n�� ����
}

// �׷��� g�� ���� (u, v)�� �����ϴ� ����
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	// ���� (u, v)�� �����ϱ� ���� ���� u�� v�� ���� �׷����� �ִ��� Ȯ��
	if (u >= g->n || v >= g->n) {
		printf("�׷����� ���� �����Դϴ�.\n");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u]; // ���� ������ ���� ��带 ����Ʈ�� ù ��° ���� ����
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
	graphNode* p;
	for (int i = 0; i < g->n; i++) {
		printf("\n\t\t���� %c�� ��������Ʈ", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("-> %c", p->vertex + 65); // ���� 0~3�� A~D�� ���
			p = p->link;
		}
	}
}

// �׷��� g���� ���� v�� ���� �ʺ� �켱 Ž��
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE; // ���� ���� v�� �湮�ߴٰ� ǥ��
	printf(" %c", v + 65);
	enQueue(Q, v); // ���� v�� ť�� enqueue

	// ť�� ������ �ƴ� ���� �ʺ� �켱 Ž�� ����
	while (!isEmpty(Q)) {
		v = deQueue(Q);
		// ���� ���� w�� �湮���� ���� ���
		for (w = g->adjList_H[v]; w; w = w->link) { // ���� ������ �ִ� ���� ����
			if (!g->visited[w->vertex]) { // ���� w�� �湮���� ���� ������ ���
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				enQueue(Q, w->vertex);
			}
		}
	} // ť�� �����̸� �ʺ� �켱 Ž�� ����
}

int main() {
	graphType* G9;
	G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);

	for (int i = 0; i < 7; i++)
		insertVertex(G9, i);
	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);
	printf("G9�� ��������Ʈ");
	print_adjList(G9);

	printf("\n\n�ʺ� �켱 Ž��:");
	BFS_adjList(G9, 0); //0�� �������� ����

	return 0;
}