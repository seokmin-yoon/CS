#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// 그래프를 인접 행렬로 표현하기 위한 구조체 정의
typedef struct graphType {
	int n; // 정점 개수
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

// 공백 그리프를 생성하는 연산
void createGraph(graphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++)
			g->adjMatrix[i][j] = 0;
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
	if (u >= g->n || v >= g->n) {
		printf("그래프에 없는 정점입니다.\n");
		return;
	}
	g->adjMatrix[u][v] = 1; // 간선이 존재한다고 표기
}

void print_adjMatrix(graphType* g) {
	int i, j;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t");
		for (j = 0; j < g->n; j++)
			printf("%2d", g->adjMatrix[i][j]);
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
	printf("G3의 인접행렬");
	print_adjMatrix(G3);

	return 0;

}