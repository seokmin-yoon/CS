#include <stdio.h>
#include <stdlib.h>

typedef char element;

// ���� Ʈ���� ��� ����ü
typedef struct treeNode {
    element data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

// �� ��� ���� �Լ�
treeNode* createNode(element data) {
    treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ���� Ʈ�� ���� �Լ� (���� ������ ���·� ����: ���� �Ǵ� ������ �ڽ��� ��������� ����)
void insertNode(treeNode** root, element data) {
    if (*root == NULL) {
        *root = createNode(data);
    }
    else {
        // ���� �ڽĺ��� ���� �����ϵ��� ����
        if ((*root)->left == NULL) {
            (*root)->left = createNode(data);
        }
        else if ((*root)->right == NULL) {
            (*root)->right = createNode(data);
        }
        else {
            // ���� �ڽİ� ������ �ڽ��� �� �� ������ ��������� ����
            insertNode(&(*root)->left, data);
        }
    }
}

// ���� ��ȸ ���
void preorder(treeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// ���� ��ȸ ��� �Լ�
void inorder(treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// ���� ��ȸ ���
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

    // ���� Ʈ�� ����
    insertNode(&root, 'A');
    insertNode(&root, 'B');
    insertNode(&root, 'C');
    insertNode(&root, 'D');
    insertNode(&root, 'E');

    // Ʈ�� ��ȸ (����, ����, ����)
    printf("���� ��ȸ (Pre-order): ");
    preorder(root);
    printf("\n");

    printf("���� ��ȸ (In-order): ");
    inorder(root);
    printf("\n");

    printf("���� ��ȸ (Post-order): ");
    postorder(root);
    printf("\n");

    // Ʈ�� �޸� ����
    freeTree(root);

    return 0;
}
