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

typedef struct stackNode {
	int data;
	struct stackNode* link;
} stackNode;

stackNode* top;

// 스택이 비었는지 확인하는 함수
int isEmpty() {
    if (top == NULL) return TRUE;
	return FALSE;
}

// 스택에 데이터를 푸시하는 함수
void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));  // 새 노드를 동적 할당
    temp->data = item;  // 노드에 데이터 저장
    temp->link = top;    // 새 노드의 링크는 현재 top을 가리킴
    top = temp;          // top을 새 노드로 갱신
}

// 스택에서 데이터를 팝하는 함수
element pop() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return -1;  // 비어 있을 경우 잘못된 값을 반환
    }
    stackNode* temp = top;         // 팝할 노드를 임시로 저장
    element item = temp->data;  // 팝할 데이터를 저장
    top = top->link;           // top을 다음 노드로 갱신
    free(temp);                // 팝한 노드를 메모리에서 해제
    return item;
}

// 깊이 우선 탐색을 위해 초기 공백 그래프를 생성하는 연산
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

// 그래프 g에서 정점 v에 대한 깊이 우선 탐색 연산
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v); // 시작 정점을 push
	g->visited[v] = TRUE;
	printf(" %c", v + 65);

	// 스택이 공백이 아닌 동안 깊이 우선 탐색 반복
	while (!isEmpty()) {
		v = pop();
		w = g->adjList_H[v];
		// 인접 정점이 있는 동안 수행
		while (w) {
			// 현재 정점 w를 방문하지 않은 경우
			if (!g->visited[w->vertex]) {
				if (isEmpty()) // 정점 v로 돌아올 경우를 위해 다시 push
					push(v);
				push(w->vertex); // 현재 정점 w를 push
				g->visited[w->vertex] = TRUE; // 정점 w에 대한 방문 여부를 true로 설정
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			// 현재 정점 w가 이미 방문된 경우
			else
				w = w->link;
		}
	} // 스택이 공백이면 깊이 우선 탐색 종료
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

	printf("\n\n깊이 우선 탐색:");
	DFS_adjList(G9, 0); //0번 정점에서 시작

	return 0;
}