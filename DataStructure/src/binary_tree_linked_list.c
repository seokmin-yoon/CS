#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 이진 트리의 노드 구조체
typedef struct treeNode {
    element data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

// 새 노드 생성 함수
treeNode* createNode(element data) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 이진 트리 삽입 함수 (가장 간단한 형태로 삽입: 왼쪽 또는 오른쪽 자식이 비어있으면 삽입)
void insertNode(treeNode** root, element data) {
    if (*root == NULL) {
        *root = createNode(data);
    }
    else {
        // 왼쪽 자식부터 먼저 삽입하도록 변경
        if ((*root)->left == NULL) {
            (*root)->left = createNode(data);
        }
        else if ((*root)->right == NULL) {
            (*root)->right = createNode(data);
        }
        else {
            // 왼쪽 자식과 오른쪽 자식이 다 차 있으면 재귀적으로 삽입
            insertNode(&(*root)->left, data);
        }
    }
}

// 전위 순회 출력
void preorder(treeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회 출력 함수
void inorder(treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// 후위 순회 출력
void postorder(treeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

void freeTree(treeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    treeNode* root = NULL;

    // 이진 트리 구성
    insertNode(&root, 'A');
    insertNode(&root, 'B');
    insertNode(&root, 'C');
    insertNode(&root, 'D');
    insertNode(&root, 'E');

    // 트리 순회 (전위, 중위, 후위)
    printf("전위 순회 (Pre-order): ");
    preorder(root);
    printf("\n");

    printf("중위 순회 (In-order): ");
    inorder(root);
    printf("\n");

    printf("후위 순회 (Post-order): ");
    postorder(root);
    printf("\n");

    // 트리 메모리 해제
    freeTree(root);

    return 0;
}
