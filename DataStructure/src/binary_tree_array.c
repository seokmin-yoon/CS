#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // ���� Ʈ���� �ִ� ũ��

typedef char element;

// ���� Ʈ���� ��Ÿ���� ����ü
typedef struct {
    element data[MAX_SIZE];  // Ʈ�� �����͸� ������ �迭
    int size;            // Ʈ���� ���� ũ��
} BinaryTree;

// Ʈ�� �ʱ�ȭ
void initTree(BinaryTree* tree) {
    tree->size = 0;
}

// Ʈ���� ��� ����
void insertNode(BinaryTree* tree, element value) {
    if (tree->size >= MAX_SIZE) {
        printf("Ʈ���� ���� á���ϴ�.\n");
        return;
    }
    tree->data[tree->size] = value;
    tree->size++;
}

// Ʈ�� ��� (�ܼ��� �迭�� ���)
void printTree(BinaryTree* tree) {
    printf("���� Ʈ��: ");
    for (int i = 0; i < tree->size; i++) {
        printf("%c ", tree->data[i]);
    }
    printf("\n");
}

// Ʈ�� �׷��� ���·� ��� (������ ����)
void printTreeGraph(BinaryTree* tree, int index, int level) {
    if (index >= tree->size) return;

    // ������ �ڽ� ��� ���� ��� (�����ʺ��� �������� ���)
    int rightIndex = rightChild(index);
    if (rightIndex < tree->size) {
        printTreeGraph(tree, rightIndex, level + 1);
    }

    // ���� ��� ��� (�߾ӿ� ��ġ)
    for (int i = 0; i < level; i++) {
        printf("    ");  // ������ �־ �鿩����
    }
    printf("%c[%d]\n", tree->data[index], index);

    // ���� �ڽ� ��� ���
    int leftIndex = leftChild(index);
    if (leftIndex < tree->size) {
        printTreeGraph(tree, leftIndex, level + 1);
    }
}

// ���� �ڽ��� �ε��� ��ȯ
int leftChild(int index) {
    return 2 * index + 1;
}

// ������ �ڽ��� �ε��� ��ȯ
int rightChild(int index) {
    return 2 * index + 2;
}

// �θ��� �ε��� ��ȯ
int parent(int index) {
    if (index == 0) return -1;  // ��Ʈ ���� �θ� ����
    return (index - 1) / 2;
}

int main() {
    BinaryTree tree;
    initTree(&tree);

    // Ʈ���� �� ����
    insertNode(&tree, 'A');
    insertNode(&tree, 'B');
    insertNode(&tree, 'C');
    insertNode(&tree, 'D');
    insertNode(&tree, 'E');
    insertNode(&tree, 'F');
    insertNode(&tree, 'G');

    // Ʈ�� ���
    printTreeGraph(&tree, 0, 0);

    return 0;
}