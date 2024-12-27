#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct treeNode {
    element data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

treeNode* createNode(element data) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// 이진 탐색 트리에서 노드 탐색 함수
treeNode* search(treeNode* root, element key) {
    // 루트가 NULL이거나 키가 루트의 데이터와 같으면 해당 노드를 반환
    if (root == NULL || root->data == key)
        return root;

    // 키가 루트의 데이터보다 작으면 왼쪽 서브트리에서 검색
    if (key < root->data)
        return search(root->left, key);

    // 키가 루트의 데이터보다 크면 오른쪽 서브트리에서 검색
    return search(root->right, key);
}

// 이진 탐색 트리에서 노드 삽입 함수
treeNode* insert(treeNode* root, element key) {
    // 트리가 비어 있으면 새로운 노드 생성
    if (root == NULL)
        return createNode(key);

    // 키가 루트의 데이터보다 작으면 왼쪽 서브트리에 삽입
    if (key < root->data)
        root->left = insert(root->left, key);
    // 키가 루트의 데이터보다 크면 오른쪽 서브트리에 삽입
    else if (key > root->data)
        root->right = insert(root->right, key);

    // 이미 트리에 값이 존재하면 아무 작업도 하지 않음
    return root;
}

// 이진 탐색 트리에서 가장 작은 값을 가진 노드를 찾는 함수
treeNode* minValueNode(treeNode* node) {
    treeNode* current = node;
    // 가장 왼쪽에 있는 노드를 찾음
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// 이진 탐색 트리에서 노드 삭제 함수
treeNode* deleteNode(treeNode* root, element key) {
    // 1. 노드를 찾음
    if (root == NULL)
        return root;

    // 키가 루트의 데이터보다 작으면 왼쪽 서브트리에서 삭제
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    // 키가 루트의 데이터보다 크면 오른쪽 서브트리에서 삭제
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    // 키가 루트의 데이터와 같으면 해당 노드를 삭제
    else {
        // 2. 자식이 없는 노드 (리프 노드)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // 3. 자식이 하나만 있는 경우
        else if (root->left == NULL) {
            treeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            treeNode* temp = root->left;
            free(root);
            return temp;
        }
        // 4. 자식이 두 개 있는 경우
        else {
            // 오른쪽 서브트리에서 가장 작은 노드를 찾아서 교체
            treeNode* temp = minValueNode(root->right);
            root->data = temp->data;  // 값을 교환
            root->right = deleteNode(root->right, temp->data);  // 오른쪽 서브트리에서 그 값을 가진 노드를 삭제
        }
    }
    return root;
}

// 전위 순회 출력
void preorder(treeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회 출력 함수
void inorder(treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 후위 순회 출력
void postorder(treeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
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

    // 트리에 값 삽입
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 11);
    root = insert(root, 16);

    printf("이진 탐색 트리 전위 순회: ");
    preorder(root);  
    printf("\n");

    printf("이진 탐색 트리 중위 순회: ");
    inorder(root);  
    printf("\n");

    printf("이진 탐색 트리 후위 순회: ");
    postorder(root);  
    printf("\n");

    //노드 삽입
    root = insert(root, 4);
    printf("노드 4 삽입 후 중위 순회: ");
    inorder(root);
    printf("\n");

    // 노드 탐색
    char searchKey = 11;
    treeNode* foundNode = search(root, searchKey);
    if (foundNode != NULL)
        printf("노드 %d를 찾았습니다.\n", searchKey);
    else
        printf("노드 %d를 찾지 못했습니다.\n", searchKey);

    // 노드 삭제
    printf("노드 14 삭제 후 중위 순회: ");
    root = deleteNode(root, 14);
    inorder(root);
    printf("\n");

    // 트리 메모리 해제
    freeTree(root);

    return 0;
}
