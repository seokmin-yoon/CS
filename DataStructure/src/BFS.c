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
	int visited[MAX_VERTEX]; // 정점에 대한 방문 표시를 위한 배열
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

// 연결 큐가 비었는지 확인하는 함수
int isEmpty(LQueueType* LQ) {
    if (LQ->front == NULL) return TRUE;
    return FALSE;
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

// 너비 우선 탐색을 위해 초기 공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("그래프 정점의 개수를 초과하였습니다.\n");
		return;
	}
	g->n++; // 그래프 정점 개수 n을 증가
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v) {
	graphNode* node;

	// 간선 (u, v)를 삽입하기 위해 정점 u와 v가 현재 그래프에 있는지 확인
	if (u >= g->n || v >= g->n) {
		printf("그래프에 없는 정점입니다.\n");
		return;
	}
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u]; // 삽입 간선에 대한 노드를 리스트의 첫 번째 노드로 연결
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g) {
	graphNode* p;
	for (int i = 0; i < g->n; i++) {
		printf("\n\t\t정점 %c의 인접리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf("-> %c", p->vertex + 65); // 정점 0~3을 A~D로 출력
			p = p->link;
		}
	}
}

// 그래프 g에서 정점 v에 대한 너비 우선 탐색
void BFS_adjList(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited[v] = TRUE; // 시작 정점 v를 방문했다고 표기
	printf(" %c", v + 65);
	enQueue(Q, v); // 정점 v를 큐에 enqueue

	// 큐가 공백이 아닌 동안 너비 우선 탐색 수행
	while (!isEmpty(Q)) {
		v = deQueue(Q);
		// 현재 정점 w를 방문하지 않은 경우
		for (w = g->adjList_H[v]; w; w = w->link) { // 인접 정점이 있는 동안 수행
			if (!g->visited[w->vertex]) { // 정점 w가 방문하지 않은 정점인 경우
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				enQueue(Q, w->vertex);
			}
		}
	} // 큐가 공백이면 너비 우선 탐색 종료
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
	printf("G9의 인접리스트");
	print_adjList(G9);

	printf("\n\n너비 우선 탐색:");
	BFS_adjList(G9, 0); //0번 정점에서 시작

	return 0;
}