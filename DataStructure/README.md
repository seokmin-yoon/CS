# 1. 리스트
## 1.1. 선형 리스트
배열을 이용하여 구현할 자료들을 논리적인 순서로 메모리에 연속 저장하는 방식의 자료 구조

- 배열: <인덱스, 값>
    - 인덱스: 자료의 순서

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-1.png?raw=true)

## 1.2. 연결 리스트
포인터를 이용하여 구현할 자료의 논리적인 순서와 메모리에 저장되는 물리적인 순서가 다르게 저장되는 방식의 자료 구조

- 노드: <원소, 주소>
    - 주소(포인터): 다음 노드의 메모리 주소

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-2.png?raw=true)

### 단순 연결 리스트
노드가 하나의 링크 필드에 의해서 다음 노드와 연결되는 리스트

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-3.png?raw=true)

singly_linked_list.c

```c
typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} ListNode;

typedef struct LinkedList_h {
    ListNode* head;
} LinkedList_h;

// 단순 연결 리스트에 마지막 노드로 삽입하는 연산
void insertNode(LinkedList_h* L, const char* x) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0';
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    ListNode* temp = L->head;
    while (temp->link != NULL) temp = temp->link; // 마지막 노드로 이동
    temp->link = newNode;
}

// 단순 연결 리스트에서 노드 p를 삭제하는 연산
void deleteNode(LinkedList_h* L, ListNode* p) {
    if (L->head == NULL || p == NULL) return; // 리스트가 비어 있거나 삭제할 노드가 없음

    if (L->head == p) {  // 삭제할 노드가 첫 번째 노드일 경우
        L->head = p->link;  // 헤드를 다음 노드로 갱신
        free(p);
        return;
    }

    // 노드를 찾기 위한 선행 노드 찾기
    ListNode* pre = L->head;
    while (pre->link != NULL && pre->link != p) {
        pre = pre->link;
    }

    if (pre->link == p) {  // p를 찾았을 경우
        pre->link = p->link;  // 선행 노드와 삭제 노드의 링크를 연결
        free(p);  // 노드 메모리 해제
    }
}

int main() {
    LinkedList_h* list = createLinkedList_h();

    insertNode(list, "월");
    insertNode(list, "화");
    insertNode(list, "수");

    printf("초기 리스트:\n");
    printList(list);

    // "화" 삭제하기
    ListNode* temp = list->head;
    while (temp != NULL && strcmp(temp->data, "화") != 0) {
        temp = temp->link;
    }

    if (temp != NULL) {
        deleteNode(list, temp);  // "화" 노드 삭제
        printf("노드 화 삭제 후:\n");
        printList(list);
    }
    else {
        printf("삭제할 노드를 찾을 수 없습니다.\n");
    }

    freeLinkedList_h(list);
    free(list);

    return 0;
}
```

```c
```

### 원형 연결 리스트
단순 연결 리스트에서 마지막 노드를 리스트의 첫 번째 노드로 가리키도록 하여 원형 구조로 만든 리스트

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-4.png?raw=true)

circular_linked_list.c

```c
```

```c
```

### 이중 연결 리스트
리스트를 양쪽 방향으로 순회할 수 있도록 링크 필드를 두 개 사용하여 양방향 노드를 연결한 리스트

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-5.png?raw=true)

douply_linked_list.c

```c
```

```c
```

# 2. 스택 (Stack)
자료를 차곡차곡 쌓아 올린 형태의 자료구조
- LIFO (Last-In, First-Out)
- 삽입 연산: push, 위치: top (아래 그림의 노란 블록)
- 삭제 연산: pop, 위치: top

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/2-1.png?raw=true)

## 2.1. 순차 스택
배열을 이용한 스택

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/2-2.png?raw=true)

stack_array.c

```c
```

## 2.2. 연결 스택
연결 리스트를 이용한 스택

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/2-3.png?raw=true)

stack_linked_list.c

```c
```

# 3. 큐 (Queue)
데이터를 뒤에서만 삽입하고, 앞에서만 삭제할 수 있는 구조 
- FIFO (First-In, First-Out)
- 삽입:  enqueue, 위치: rear
- 삭제: dequeue, 위치: front

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-1.png?raw=true)

## 3.1. 순차 큐
1차원 배열을 이용하여 순차적으로 연결된 큐
- rear가 배열의 마지막 인덱스에 도달하면, 배열에 빈자리가 있어도 포화 상태가 될 수 있음

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-2.png?raw=true)

queue_array.c

```c
```

## 3.2. 원형 큐
1차원 배열에서 처음과 끝을 논리적으로 연결한 큐
- 순차 큐의 잘못된 포화 상태 문제를 해결함

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-3.png?raw=true)

circular_queue_array.c

```c
```

## 3.3. 연결 큐
노드의 양쪽에 포인터를 연결하여 구성된 큐

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-4.png?raw=true)

queue_linked_list.c

```c
```

# 4. 데크 (Deque)
큐 두 개 중 하나를 좌우로 뒤집어서 붙인 구조로, 큐의 양쪽 끝에서 삽입과 삭제 연산을 수행

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/4-1.png?raw=true)

## 4.1. 순차 데크
효율적인 공간 활용을 위해 원형 큐 기반 데크
- 양쪽 끝에서 삽입, 삭제 연산을 수행하면서 오버헤드가 발생하므로 순차 자료구조는 비효율적

deque_circular_queue.c

```c
```

## 4.2. 연결 데크
이중 연결 리스트를 사용한 데크

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/4-2.png?raw=true)

deque_douply_linked_list.c

```c
```

# 5. 트리
상위 원소에서 하위 원소로 내려가면서 확장되는 트리(나무)모양의 계층형 구조, (1:N 관계)
- **노드**: 트리의 원소
- **간선**: 노드를 연결하는 선
- **루트 노드**: 트리의 시작 노드
- **부모 노드**:  자식 노드와 연결된 상위 노드
- **자식 노드**: 부모 노드와 연결된 하위 노드
- **단말 노드 (leaf)**: 자식 노드가 없는 노드
- **서브 트리 (forest)**: 부모 노드와 연결된 간선을 끊었을 때 생성되는 트리
- **차수 (degree)**: 노드에 연결된 자식 노드의 수
- **높이**: 노드의 레벨
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-1.png?raw=true)

## 5.1. 이진 트리
트리의 모든 노드의 차수가 2 이하를 가져 왼쪽과 오른쪽 자식만 가지는 노드로 구성된 트리
- 노드가 n개 일 때, 간선은 n-1개
- 높이가 h일 때, 가질 수 있는 노드 개수는 최소 h+1, 최대 2^(h+1)-1

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-2.png?raw=true)

- **포화 이진 트리 (Full Binary Tree)**: 모든 레벨에 가능한 최대 개수의 노드로 차 있는 이진 트리
    - 각 레벨 k에서 노드는 2^k개
      
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-3.png?raw=true)

- **완전 이진 트리 (Complete Binary Tree)**: 모든 레벨이 가득 차 있으며, 마지막 레벨만 노드가 왼쪽부터 차례대로 채워진 이진 트리

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-4.png?raw=true)

- **편향 이진 트리 (Skewed Binary Tree)**: 모든 노드가 한쪽 방향(왼쪽 또는 오른쪽)으로만 서브 트리를 가지고 있는 이진 트리
    - 높이가 h일 때, 노드는 h+1개

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-5.png?raw=true)

### 배열 기반 구현
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-6.png?raw=true)

binary_tree_array.c

```c
```

### 연결 리스트 기반 구현
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-7.png?raw=true)

binary_tree_linked_list.c

```c
```

## 5.2. 이진 트리 순회
- **D**: 현재 (루트) 노드
- **L**: 현재 노드의 왼쪽  노드로 이동
- **R**: 현재 노드의 오른쪽 노드로 이동

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-8.png?raw=true)

- **전위 순회(preorder)**: D → L → R
    - 위 트리에서 전위 순회 경로: A-B-D-H-E-I-J-C-F-G-K
- **중위 순회(inorder)**: L → D → R
    - 위 트리에서 중위 순회 경로: H-D-B-I-E-J-A-F-C-G-K
- **후위 순회(postorder)**: L → R → D
    - 위 트리에서 후위 순회 경로: H-D-I-J-E-B-F-K-G-C-A

## 5.3. 이진 탐색 트리 (Binary search tree)
이진 트리를 탐색용 자료구조를 사용하기 위해 원소 크기에 따라 노드 위치를 정의한 것
- 모든 원소는 서로 다른 유일한 키를 가짐
- 왼쪽 서브 트리에 있는 원소들의 키는 그 루트의 키보다 작음
- 오른쪽 서브 트리에 있는 원소들의 키는 그 루트의 키보다 큼
- 양쪽 서브 트리는 모두 이진 트리임

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-9.png?raw=true)

1. 이진 탐색 트리의 탐색 과정
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-10.png?raw=true)

2. 이진 탐색 트리의 삽입 과정
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-11.png?raw=true)

3. 이진 탐색 트리의 삭제 과정
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-12.png?raw=true)

binary_search_tree.c

```c
```

## 5.4. AVL 트리 (Adelson-Velskii, Landis Tree)
균형 잡힌 이진 탐색 트리로, 각 노드에서 왼쪽 서브 트리 높이와 오른쪽 서브 트리 높이의 차이가 1 이하인 트리
- **균형 이진 탐색 트리 또는 균형 트리**: 이진 탐색 트리의 왼쪽과 오른쪽 서브 트리의 높이에 대한 균형 조건을 추가한 트리
- **균형 인수 (BF: Balance Factor)**: 각 노드에서 왼쪽 서브 트리의 높이 hL (height of Left subtree)과 오른쪽 서브 트리 높이 hR (height of Right subtree)의 차이
    - BF = hL - hR
- AVL 트리의 각 노드는 균형 인수로 {-1, 0, +1} 값만 가질 수 있음

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-13.png?raw=true)

위 그림은 모든 노드가 균형 인수로 {-1, 0, 1} 값을 가지므로 AVL 트리임

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-14.png?raw=true)

위 그림은 균형 인수로 {-1, 0, 1} 외의 값을 가져 균형이 깨지므로 비 AVL 트리임

## 5.5. 힙 (Heap)
완전 이진 트리 형태에서, 노드 중 키 값이 가장 큰 노드나 키 값이 가장 작은 노드를 찾기 위해서 만든 자료 구조
- **최대 힙 (max heap)**: 키 값이 가장 큰 노드를  찾기 위한 완전 이진 트리
    - 부모 노드의 키가 자식 노드보다 큼
- **최소 힙 (min heap)** : 키 값이 가장 작은 노드를  찾기 위한 완전 이진  트리
    - 부모 노드의 키가 자식 노드보다 작음

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-15.png?raw=true)

### 배열 기반으로 최대 힙 구현
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-16.png?raw=true)

max_heap_array.c

```c
```

# 6. 그래프
연결되어 있는 원소 사이의 다대다 관계를 표현하는 자료구조
- **G = (V, E)**
    - G: 그래프
    - V: 정점(노드) 집합
    - E: 간선(링크) 집합
- **인접 (adjacent)**: 두 정점을 연결하는 간선이 존재할 때, 두 정점을 서로 인접 되어 있다고 함
- **부속 (incident)**: 두 정점을 연결하는 간선이 존재할 때, 두 정점을 연결하는 간선은 부속 되어 있다고 함
- **사이클(cycle)**: 시작점과 끝점이 동일한 경로로, 모든 간선을 한 번씩만 지나면서 순환하는 경로

## 6.1. 그래프 종류
- **무방향 그래프 (undirected graph)**: 두 정점을 연결하는 간선에 방향이 없는 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-1.png?raw=true)

- **방향 그래프 (directed graph), 다이그래프 (digraph)**: 간선에 방향이 있는 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-2.png?raw=true)

- **완전 그래프 (complete graph)**: 각 정점에서 다른 모든 정점을 연결하여 최대로 많은 간선 수를 가진 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-3.png?raw=true)

- **부분 그래프 (subgraph)**: 원래의 그래프에서 정점이나 간선을 일부만 제외하여 만든 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-4.png?raw=true)

- **가중 그래프 (weight graph), 네트워크 (network)**: 정점을 연결하는 간선에 가중치를 할당한 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-5.png?raw=true)

## 6.2. 그래프 구현
### 인접 행렬
2차원 배열을 사용하여 그래프의 두 정점을 연결한 간선의 유무를 행렬로 나타내는 방법

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-6.png?raw=true)

graph_adjmatrix.c

```c
```

### 인접 리스트
연결 리스트를 사용하여 각 정점에 대한 인접 정점들을 연결하여 나타내는 방법

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-7.png?raw=true)

graph_adjlist.c

```c
```

## 6.3. 그래프 순회
### **깊이 우선 탐색 (DFS: Depth First Search)**
시작 정점에서 가능한 깊이까지 탐색한 후 되돌아와 미탐색 방향으로 진행해 모든 정점을 방문하는 방법
- 스택 사용
- **탐색 과정**
    1. 시작 정점 v를 결정 하여 방문
    2. 정점 v에 인접한 정점 중에서 방문하지 않은 정점 w가 
        1. 있으면 정점 v를 스택에 push하고 w를 방문
        2. 없으면 스택을 pop 하고 pop된 정점 v에서 2를 반복 수행
    3. 스택이 공백이 될 때까지 위를 반복

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-8.png?raw=true)

DFS.c

```c
```

### **너비 우선 탐색 (BFS: Breadth First Search)**
시작 정점에서 가까운 정점부터 차례로 방문하며, 인접 정점을 레벨 별로 탐색하는 방법
- 큐 사용
- **탐색 과정**
    1. 시작 정점 v를 결정하여 방문
    2. 정점 v에 인접한 정점 중에서 방문하지 않은 정점이
        1. 있으면 정점 v를 큐에 enqueue
        2. 없으면 정점 v를 큐에서 dequeue하여 정점 w를 받고 2를 반복 수행
    3. 큐가 공백이 될 때까지 위를 반복

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-9.png?raw=true)

BFS.c

```c
```

## 6.4. 신장 트리와 최소 비용 신장 트리
### 신장 트리 (Spanning Tree)
n개의 정점으로 이루어진 무 방향 그래프 G에서 n개의 모든 정점과 n-1개의 간선으로 만들어진 트리
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-10.png?raw=true)

### 최소 비용 신장 트리 (Minimum cost Spanning Tree)
무 방향 가중치 그래프에서 신장 트리를 구성하는 간선들의 가중치 합이 최소인 신장 트리

### 크루스칼 알고리즘 (Kruskal Algorithm)
가중치가 높은 간선을 제거하면서 최소 비용 신장 트리를 만드는 방법
- Greedy Algorithm

- **MST 구하는 과정**
    1. 먼저 그래프 G의 모든 간선을 가중치에 따라 오름차순으로 정렬
    2. 그래프 G에 가중치가 가장 낮은 간선을 최소 비용 신장 트리(MST) 집합에 삽입
        1. 단, 싸이클을 형성하지 않는 간선을 삽입
    3. 그래프 G에 간선이 n-1개가 아니라면 2를 반복
    4. 그래프 G의 간선이 n-1개 라면 알고리즘 종료

알고리즘

kruskal_algorithm.c

```c
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
```

그래프 G10 실행 결과

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-11.png?raw=true)

```c
그래프 G10의 Minimum Spanning Tree:
Edge (4, 6) with weight 2
Edge (0, 1) with weight 3
Edge (4, 5) with weight 4
Edge (1, 3) with weight 5
Edge (2, 5) with weight 8
Edge (3, 4) with weight 9
Total weight of MST: 31
```

### 프림 알고리즘 (Prim Algorithm)
간선을 정렬하지 않고 하나의 정점에서 시작하여 트리를 확장해 나가는 방법
- Greedy Algorithm

- **MST 구하는 과정**
    1. 그래프 G에서 시작 정점을 선택
    2. 현재 정점에 부속된 모든 간선 중에서 가중치가 가장 낮은 간선을 최소 비용 신장 트리(MST) 집합에 삽입하여 트리를 확장
    3. 그래프 G에 간선이 n-1개가 아니라면 2를 반복 수행
    4. 그래프 G의 간선이 n-1개 라면 알고리즘 종료

알고리즘

```c
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
```

그래프 G10 실행 결과

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-12.png?raw=true)

```c
그래프 G10의 Minimum Spanning Tree Edges:
Edge (0, 1) with weight 3
Edge (1, 3) with weight 5
Edge (3, 4) with weight 9
Edge (4, 6) with weight 2
Edge (4, 5) with weight 4
Edge (5, 2) with weight 8
Total weight of Minimum Spanning Tree: 31
```

## 6.5. 최단 경로
신장 트리가 아닌 가중치 그래프 (네트워크)에서 정점 u와 v를 연결하는 경로 중 가중치의 합이 최소인 경로
- **가중치 인접 행렬**: 최단 경로를 구하려는 가중치 그래프의 가중치를 저장한 2차원 배열
    - 간선이 없으면 ∞(무한대) 값을 저장

### 다익스트라 알고리즘 (Dijkstra Algorithm)
- 하나의 시작 정점에서 다른 정점까지의 최단 경로를 구함
- 무방향 그래프나 방향 그래프에 모두 적용 가능
- 단일점에서의 최단 경로 알고리즘 중 가장 많이 사용됨
- Dynamic Programming Algorithm

- **최단 경로 구하는 과정**
    1. **경로 길이를 저장할 배열 distance 준비**:
        - 시작 정점으로부터 각 정점에 이르는 경로의 길이를 저장하기 위한 배열 distance를 무한대로 초기화
    2. **시작 정점 초기화**:
        - 시작 정점의 distance를 0으로 초기화
        - 최단 경로 정점 집합 S에 해당 정점을 추가
    3. **최단 거리 수정**:
        - 집합 S에 속하지 않은 정점 중에서 distance가 최소인 정점 u를 찾음
        - 정점 u를 집합 S에 추가하고, 집합 S에 포함되지 않은 정점 w의 distance 값을 다음 식에 따라 업데이트
           - weight: 가중치 인접 행렬
            
            $$
            distance[w]=min(distance[w], distance[u]+weight[u][w])
            $$
 
            이 공식은 현재 경로 보다 정점 u를 거쳐서 w으로 가는 경로가 더 짧다면, w의 distance 값을 갱신하는 방식임
          
        4. 집합 S에 모든 정점이 추가될 때까지 3번 과정을 반복

알고리즘

```c
//1. distance 배열을 무한대로 초기화.
//2. 시작 정점의 distance 값을 0으로 설정하고 집합 S에 추가.
//3. 최단 경로를 갱신하며 집합 S에 정점을 추가.
//4. 모든 정점이 집합 S에 포함될 때까지 이 과정을 반복.
```

그래프 G11 실행 결과

```c
```

### 플로이드-워셜 알고리즘 (Floyd-Warshall Algorithm)
- 모든 정점 사이의 최단 경로를 구함
- Dynamic Programming Algorithm

- **최단 경로 구는 과정**

알고리즘

```c
```

그래프 G11 실행 결과

```c
```

### 벨만-포드 알고리즘 (Bellman-Ford Algorithm)
- Dynamic Programming Algorithm

- **최단 경로 구는 과정**

알고리즘

```c
```

그래프 G11 실행 결과

```c
```

# Reference
C로 배우는 쉬운 자료구조 (개정 3판), 이지영, 한빛아카데미
