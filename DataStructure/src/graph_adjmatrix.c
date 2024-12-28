#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// �׷����� ���� ��ķ� ǥ���ϱ� ���� ����ü ����
typedef struct graphType {
	int n; // ���� ����
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

// ���� �׸����� �����ϴ� ����
void createGraph(graphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++)
			g->adjMatrix[i][j] = 0;
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
	if (u >= g->n || v >= g->n) {
		printf("�׷����� ���� �����Դϴ�.\n");
		return;
	}
	g->adjMatrix[u][v] = 1; // ������ �����Ѵٰ� ǥ��
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
	printf("G3�� �������");
	print_adjMatrix(G3);

	return 0;

}