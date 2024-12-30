#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 30
#define MAX_EDGES 100

// 간선 구조체 정의
typedef struct {
    int u, v;   // 간선 (u, v)
    int weight; // 간선의 가중치
} Edge;

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
void insertEdge(graphType* g, int u, int v, int weight) {
    if (u >= g->n || v >= g->n) {
        printf("그래프에 없는 정점입니다.\n");
        return;
    }
    g->adjMatrix[u][v] = weight; // 간선 가중치를 설정
    g->adjMatrix[v][u] = weight; // 무방향 그래프이므로 대칭으로 설정
}

// 간선 리스트를 비교하는 함수 (qsort 사용)
int compare_edges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// 부모 노드를 찾는 함수 (find)
int parent[MAX_VERTEX];

// find 함수: 부모를 찾아 반환 (경로 압축)
int find_set(int u) {
    if (parent[u] != u) {
        parent[u] = find_set(parent[u]); // 경로 압축
    }
    return parent[u];
}

// union 함수: 두 집합을 합침
void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        parent[root_v] = root_u; // root_u를 root_v의 부모로 설정
    }
}

// Kruskal 알고리즘
void kruskal(graphType* g) {
    Edge edges[MAX_EDGES];
    int edge_count = 0;

    // 간선 리스트로 변환 (인접 행렬에서 간선 리스트로)
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->adjMatrix[i][j] != 0) { // 간선이 존재하면
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].weight = g->adjMatrix[i][j];
                edge_count++;
            }
        }
    }

    // 간선을 가중치 순으로 정렬
    qsort(edges, edge_count, sizeof(Edge), compare_edges);

    // 각 정점에 대해 부모 노드를 자기 자신으로 설정
    for (int i = 0; i < g->n; i++) {
        parent[i] = i;
    }

    printf("Minimum Spanning Tree:\n");
    int mst_weight = 0;
    for (int i = 0; i < edge_count; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // 두 정점이 같은 집합에 속하지 않으면 간선 추가
        if (find_set(u) != find_set(v)) {
            printf("Edge (%d, %d) with weight %d\n", u, v, edges[i].weight);
            mst_weight += edges[i].weight;
            union_sets(u, v); // 집합을 합침
        }
    }
    printf("Total weight of MST: %d\n", mst_weight);
}

int main() {
    graphType* G10;
    G10 = (graphType*)malloc(sizeof(graphType));
    createGraph(G10);

    // 정점 삽입
    for (int i = 0; i < 7; i++) {
        insertVertex(G10, i);
    }

    // 간선 삽입 (간선 u, v, weight)
    insertEdge(G10, 'A' - 'A', 'B' - 'A', 3); // (A -> 0, B -> 1, ...) 으로 변환
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

    printf("그래프 G10의 ");
    // Kruskal 알고리즘 실행
    kruskal(G10);

    free(G10);
    return 0;
}
