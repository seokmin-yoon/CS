#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX 30

// ������ �׷��� ����ü ����
typedef struct graphType {
    int n; // ���� ����
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

// ���� �׷����� �����ϴ� ����
void createGraph(graphType* g) {
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    g->n = 0;
}

// �׷��� g�� ���� v�� �����ϴ� ����
void insertVertex(graphType* g, int v) {
    if ((g->n + 1) > MAX_VERTEX) {
        printf("�׷��� ������ ������ �ʰ��Ͽ����ϴ�.\n");
        return;
    }
    g->n++; // �׷��� ���� ���� n ����
}

// �׷��� g�� ���� (u, v)�� �����ϴ� ����
void insertEdge(graphType* g, int u, int v, int weight) {
    if (u >= g->n || v >= g->n) {
        printf("�׷����� ���� �����Դϴ�.\n");
        return;
    }
    g->adjMatrix[u][v] = weight;
    g->adjMatrix[v][u] = weight; // ������ �׷���
}

// Prim �˰��� ����
void prim(graphType* g) {
    int selected[MAX_VERTEX] = { 0 };
    int totalWeight = 0;
    int edgesInTree = 0;

    // B �� {0}
    // ù ��° ���� ����
    selected[0] = 1; 

    printf("Minimum Spanning Tree Edges:\n");

    while (edgesInTree < g->n - 1) { // T�� ���� ������ N-1�� �� ������ �ݺ�
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // Find (u, v) with minimum weight where u �� B and v �� N-B
        // ���õ� �������� ���õ��� ���� �������� ���� �ּ� ����ġ ���� ã��
        for (int i = 0; i < g->n; i++) {
            if (selected[i]) {
                for (int j = 0; j < g->n; j++) {
                    if (!selected[j] && g->adjMatrix[i][j] > 0 && g->adjMatrix[i][j] < minWeight) {
                        minWeight = g->adjMatrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add (u, v) to T and v to B
        // �ּ� ����ġ ���� (u, v) �߰�
        if (u != -1 && v != -1) {
            printf("Edge (%d, %d) with weight %d\n", u, v, minWeight);
            totalWeight += minWeight;
            selected[v] = 1; // ���� v ����
            edgesInTree++;
        }
    }

    printf("Total weight of Minimum Spanning Tree: %d\n", totalWeight);
}

int main() {
    graphType* G10;
    G10 = (graphType*)malloc(sizeof(graphType));
    createGraph(G10);

    // ���� ����
    for (int i = 0; i < 7; i++) {
        insertVertex(G10, i);
    }

    // ���� ���� (���� u, v, weight)
    insertEdge(G10, 'A' - 'A', 'B' - 'A', 3); // (A -> 0, B -> 1, ...) ���� ��ȯ
    insertEdge(G10, 'A' - 'A', 'C' - 'A', 17);
    insertEdge(G10, 'A' - 'A', 'D' - 'A', 6);
    insertEdge(G10, 'B' - 'A', 'D' - 'A', 5);
    insertEdge(G10, 'B' - 'A', 'G' - 'A', 12);
    insertEdge(G10, 'C' - 'A', 'F' - 'A', 8);
    insertEdge(G10, 'C' - 'A', 'E' - 'A', 10);
    insertEdge(G10, 'D' - 'A', 'E' - 'A', 9);
    insertEdge(G10, 'E' - 'A', 'G' - 'A', 2);
    insertEdge(G10, 'E' - 'A', 'F' - 'A', 4);
    insertEdge(G10, 'F' - 'A', 'G' - 'A', 14);

    printf("�׷��� G10�� ");
    // Prim �˰��� ����
    prim(G10);

    free(G10);

    return 0;
}
