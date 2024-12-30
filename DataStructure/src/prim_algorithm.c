#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTEX 30

// 간단한 그래프 구조체 정의
typedef struct graphType {
    int n; // 정점 개수
    int adjMatrix[MAX_VERTEX][MAX_VERTEX];
} graphType;

// 공백 그래프를 생성하는 연산
void createGraph(graphType* g) {
    for (int i = 0; i < MAX_VERTEX; i++) {
        for (int j = 0; j < MAX_VERTEX; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    g->n = 0;
}

// 그래프 g에 정점 v를 삽입하는 연산
void insertVertex(graphType* g, int v) {
    if ((g->n + 1) > MAX_VERTEX) {
        printf("그래프 정점의 개수를 초과하였습니다.\n");
        return;
    }
    g->n++; // 그래프 정점 개수 n 증가
}

// 그래프 g에 간선 (u, v)를 삽입하는 연산
void insertEdge(graphType* g, int u, int v, int weight) {
    if (u >= g->n || v >= g->n) {
        printf("그래프에 없는 정점입니다.\n");
        return;
    }
    g->adjMatrix[u][v] = weight;
    g->adjMatrix[v][u] = weight; // 무방향 그래프
}

// Prim 알고리즘 구현
void prim(graphType* g) {
    int selected[MAX_VERTEX] = { 0 };
    int totalWeight = 0;
    int edgesInTree = 0;

    // B ← {0}
    // 첫 번째 정점 선택
    selected[0] = 1; 

    printf("Minimum Spanning Tree Edges:\n");

    while (edgesInTree < g->n - 1) { // T의 간선 개수가 N-1이 될 때까지 반복
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // Find (u, v) with minimum weight where u ∈ B and v ∈ N-B
        // 선택된 정점에서 선택되지 않은 정점으로 가는 최소 가중치 간선 찾기
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
        // 최소 가중치 간선 (u, v) 추가
        if (u != -1 && v != -1) {
            printf("Edge (%d, %d) with weight %d\n", u, v, minWeight);
            totalWeight += minWeight;
            selected[v] = 1; // 정점 v 선택
            edgesInTree++;
        }
    }

    printf("Total weight of Minimum Spanning Tree: %d\n", totalWeight);
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
    // Prim 알고리즘 실행
    prim(G10);

    free(G10);

    return 0;
}
