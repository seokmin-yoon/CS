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

typedef struct stackNode {
	int data;
	struct stackNode* link;
} stackNode;

stackNode* top;

// ������ ������� Ȯ���ϴ� �Լ�
int isEmpty() {
    if (top == NULL) return TRUE;
	return FALSE;
}

// ���ÿ� �����͸� Ǫ���ϴ� �Լ�
void push(element item) {
    stackNode* temp = (stackNode*)malloc(sizeof(stackNode));  // �� ��带 ���� �Ҵ�
    temp->data = item;  // ��忡 ������ ����
    temp->link = top;    // �� ����� ��ũ�� ���� top�� ����Ŵ
    top = temp;          // top�� �� ���� ����
}

// ���ÿ��� �����͸� ���ϴ� �Լ�
element pop() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return -1;  // ��� ���� ��� �߸��� ���� ��ȯ
    }
    stackNode* temp = top;         // ���� ��带 �ӽ÷� ����
    element item = temp->data;  // ���� �����͸� ����
    top = top->link;           // top�� ���� ���� ����
    free(temp);                // ���� ��带 �޸𸮿��� ����
    return item;
}

// ���� �켱 Ž���� ���� �ʱ� ���� �׷����� �����ϴ� ����
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

// �׷��� g���� ���� v�� ���� ���� �켱 Ž�� ����
void DFS_adjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v); // ���� ������ push
	g->visited[v] = TRUE;
	printf(" %c", v + 65);

	// ������ ������ �ƴ� ���� ���� �켱 Ž�� �ݺ�
	while (!isEmpty()) {
		v = pop();
		w = g->adjList_H[v];
		// ���� ������ �ִ� ���� ����
		while (w) {
			// ���� ���� w�� �湮���� ���� ���
			if (!g->visited[w->vertex]) {
				if (isEmpty()) // ���� v�� ���ƿ� ��츦 ���� �ٽ� push
					push(v);
				push(w->vertex); // ���� ���� w�� push
				g->visited[w->vertex] = TRUE; // ���� w�� ���� �湮 ���θ� true�� ����
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			// ���� ���� w�� �̹� �湮�� ���
			else
				w = w->link;
		}
	} // ������ �����̸� ���� �켱 Ž�� ����
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

	printf("\n\n���� �켱 Ž��:");
	DFS_adjList(G9, 0); //0�� �������� ����

	return 0;
}