#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30
#define MAX_EDGES 100

// ���� ����ü ����
typedef struct {
    int u, v;   // ���� (u, v)
    int weight; // ������ ����ġ
} Edge;

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
void insertEdge(graphType* g, int u, int v, int weight) {
    if (u >= g->n || v >= g->n) {
        printf("�׷����� ���� �����Դϴ�.\n");
        return;
    }
    g->adjMatrix[u][v] = weight; // ���� ����ġ�� ����
    g->adjMatrix[v][u] = weight; // ������ �׷����̹Ƿ� ��Ī���� ����
}

// ���� ����Ʈ�� ���ϴ� �Լ� (qsort ���)
int compare_edges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// �θ� ��带 ã�� �Լ� (find)
int parent[MAX_VERTEX];

// find �Լ�: �θ� ã�� ��ȯ (��� ����)
int find_set(int u) {
    if (parent[u] != u) {
        parent[u] = find_set(parent[u]); // ��� ����
    }
    return parent[u];
}

// union �Լ�: �� ������ ��ħ
void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        parent[root_v] = root_u; // root_u�� root_v�� �θ�� ����
    }
}

// Kruskal �˰���
void kruskal(graphType* g) {
    Edge edges[MAX_EDGES];
    int edge_count = 0;

    // ���� ����Ʈ�� ��ȯ (���� ��Ŀ��� ���� ����Ʈ��)
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->adjMatrix[i][j] != 0) { // ������ �����ϸ�
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].weight = g->adjMatrix[i][j];
                edge_count++;
            }
        }
    }

    // ������ ����ġ ������ ����
    qsort(edges, edge_count, sizeof(Edge), compare_edges);

    // �� ������ ���� �θ� ��带 �ڱ� �ڽ����� ����
    for (int i = 0; i < g->n; i++) {
        parent[i] = i;
    }

    printf("Minimum Spanning Tree:\n");
    int mst_weight = 0;
    for (int i = 0; i < edge_count; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // �� ������ ���� ���տ� ������ ������ ���� �߰�
        if (find_set(u) != find_set(v)) {
            printf("Edge (%d, %d) with weight %d\n", u, v, edges[i].weight);
            mst_weight += edges[i].weight;
            union_sets(u, v); // ������ ��ħ
        }
    }
    printf("Total weight of MST: %d\n", mst_weight);
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
    // Kruskal �˰��� ����
    kruskal(G10);

    free(G10);
    return 0;
}
