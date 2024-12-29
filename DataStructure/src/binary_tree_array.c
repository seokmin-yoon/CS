#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // 이진 트리의 최대 크기

typedef char element;

// 이진 트리를 나타내는 구조체
typedef struct {
    element data[MAX_SIZE];  // 트리 데이터를 저장할 배열
    int size;            // 트리의 현재 크기
} BinaryTree;

// 트리 초기화
void initTree(BinaryTree* tree) {
    tree->size = 0;
}

// 트리에 노드 삽입
void insertNode(BinaryTree* tree, element value) {
    if (tree->size >= MAX_SIZE) {
        printf("트리가 가득 찼습니다.\n");
        return;
    }
    tree->data[tree->size] = value;
    tree->size++;
}

// 트리 출력 (단순히 배열을 출력)
void printTree(BinaryTree* tree) {
    printf("이진 트리: ");
    for (int i = 0; i < tree->size; i++) {
        printf("%c ", tree->data[i]);
    }
    printf("\n");
}

// 왼쪽 자식의 인덱스 반환
int leftChild(int index) {
    return 2 * index + 1;
}

// 오른쪽 자식의 인덱스 반환
int rightChild(int index) {
    return 2 * index + 2;
}

// 부모의 인덱스 반환
int parent(int index) {
    if (index == 0) return -1;  // 루트 노드는 부모가 없다
    return (index - 1) / 2;
}

// 트리 그래프 형태로 출력 (계층적 구조)
void printTreeGraph(BinaryTree* tree, int index, int level) {
    if (index >= tree->size) return;

    // 오른쪽 자식 노드 먼저 출력 (오른쪽부터 왼쪽으로 출력)
    int rightIndex = rightChild(index);
    if (rightIndex < tree->size) {
        printTreeGraph(tree, rightIndex, level + 1);
    }

    // 현재 노드 출력 (중앙에 배치)
    for (int i = 0; i < level; i++) {
        printf("    ");  // 공백을 넣어서 들여쓰기
    }
    printf("%c[%d]\n", tree->data[index], index);

    // 왼쪽 자식 노드 출력
    int leftIndex = leftChild(index);
    if (leftIndex < tree->size) {
        printTreeGraph(tree, leftIndex, level + 1);
    }
}

int main() {
    BinaryTree tree;
    initTree(&tree);

    // 트리에 값 삽입
    insertNode(&tree, 'A');
    insertNode(&tree, 'B');
    insertNode(&tree, 'C');
    insertNode(&tree, 'D');
    insertNode(&tree, 'E');
    insertNode(&tree, 'F');
    insertNode(&tree, 'G');

    // 트리 출력
    printTreeGraph(&tree, 0, 0);

    return 0;
}
