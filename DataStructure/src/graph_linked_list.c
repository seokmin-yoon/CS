#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct graphNode {
	int vertex;	// ������ ��Ÿ���� ������ �ʵ�
	struct graphNode* link; // ���� ���� ������ �����ϴ� ��ũ �ʵ�
} graphNode;

// �׷����� ���� ����Ʈ�� ǥ���ϱ� ���� ����ü ����
typedef struct graphType {
	int n; // ���� ����
	graphNode* adjList_H[MAX_VERTEX]; // �׷��� ������ ���� ��� ����Ʈ ����
} graphType;

// ���� �׸����� �����ϴ� ����
void createGraph(graphType * g) {
	g->n = 0;
	for (int v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;	// �׷����� ������ ���� ��� ������ �迭�� NULL���� �ʱ�ȭ
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
	printf("G3�� ��������Ʈ");
	print_adjList(G3);
	return 0;
}
