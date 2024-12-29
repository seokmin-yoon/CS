#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// 인접 리스트의 노드 구조를 구조체로 정의
typedef struct graphNode {
	int vertex;	// 정점을 나타내는 데이터 필드
	struct graphNode* link; // 다음 인접 정점을 연결하는 링크 필드
} graphNode;

// 그래프를 인접 리스트로 표현하기 위한 구조체 정의
typedef struct graphType {
	int n; // 정점 개수
	graphNode* adjList_H[MAX_VERTEX]; // 그래프 정점에 대한 헤드 포인트 설정
} graphType;

// 공백 그리프를 생성하는 연산
void createGraph(graphType * g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;	// 그래프의 정점에 대한 헤드 포인터 배열을 NULL으로 초기화
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

int main() {
	graphType* G3;
	G3 = (graphType*)malloc(sizeof(graphType));
	createGraph(G3);

	for (int i = 0; i < 4; i++)
		insertVertex(G3, i);
	insertEdge(G3, 0, 1);
	insertEdge(G3, 0, 3);
	insertEdge(G3, 1, 2);
	insertEdge(G3, 1, 3);
	insertEdge(G3, 2, 3);
	printf("G3의 인접리스트");
	print_adjList(G3);
	return 0;
}
