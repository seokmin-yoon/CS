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

// ���� Ž�� Ʈ������ ��� Ž�� �Լ�
treeNode* search(treeNode* root, element key) {
    // ��Ʈ�� NULL�̰ų� Ű�� ��Ʈ�� �����Ϳ� ������ �ش� ��带 ��ȯ
    if (root == NULL || root->data == key)
        return root;

    // Ű�� ��Ʈ�� �����ͺ��� ������ ���� ����Ʈ������ �˻�
    if (key < root->data)
        return search(root->left, key);

    // Ű�� ��Ʈ�� �����ͺ��� ũ�� ������ ����Ʈ������ �˻�
    return search(root->right, key);
}

// ���� Ž�� Ʈ������ ��� ���� �Լ�
treeNode* insert(treeNode* root, element key) {
    // Ʈ���� ��� ������ ���ο� ��� ����
    if (root == NULL)
        return createNode(key);

    // Ű�� ��Ʈ�� �����ͺ��� ������ ���� ����Ʈ���� ����
    if (key < root->data)
        root->left = insert(root->left, key);
    // Ű�� ��Ʈ�� �����ͺ��� ũ�� ������ ����Ʈ���� ����
    else if (key > root->data)
        root->right = insert(root->right, key);

    // �̹� Ʈ���� ���� �����ϸ� �ƹ� �۾��� ���� ����
    return root;
}

// ���� Ž�� Ʈ������ ���� ���� ���� ���� ��带 ã�� �Լ�
treeNode* minValueNode(treeNode* node) {
    treeNode* current = node;
    // ���� ���ʿ� �ִ� ��带 ã��
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// ���� Ž�� Ʈ������ ��� ���� �Լ�
treeNode* deleteNode(treeNode* root, element key) {
    // 1. ��带 ã��
    if (root == NULL)
        return root;

    // Ű�� ��Ʈ�� �����ͺ��� ������ ���� ����Ʈ������ ����
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    // Ű�� ��Ʈ�� �����ͺ��� ũ�� ������ ����Ʈ������ ����
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    // Ű�� ��Ʈ�� �����Ϳ� ������ �ش� ��带 ����
    else {
        // 2. �ڽ��� ���� ��� (���� ���)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // 3. �ڽ��� �ϳ��� �ִ� ���
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
        // 4. �ڽ��� �� �� �ִ� ���
        else {
            // ������ ����Ʈ������ ���� ���� ��带 ã�Ƽ� ��ü
            treeNode* temp = minValueNode(root->right);
            root->data = temp->data;  // ���� ��ȯ
            root->right = deleteNode(root->right, temp->data);  // ������ ����Ʈ������ �� ���� ���� ��带 ����
        }
    }
    return root;
}

// ���� ��ȸ ���
void preorder(treeNode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// ���� ��ȸ ��� �Լ�
void inorder(treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// ���� ��ȸ ���
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

    // Ʈ���� �� ����
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 2);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 11);
    root = insert(root, 16);

    printf("���� Ž�� Ʈ�� ���� ��ȸ: ");
    preorder(root);  
    printf("\n");

    printf("���� Ž�� Ʈ�� ���� ��ȸ: ");
    inorder(root);  
    printf("\n");

    printf("���� Ž�� Ʈ�� ���� ��ȸ: ");
    postorder(root);  
    printf("\n");

    //��� ����
    root = insert(root, 4);
    printf("��� 4 ���� �� ���� ��ȸ: ");
    inorder(root);
    printf("\n");

    // ��� Ž��
    char searchKey = 11;
    treeNode* foundNode = search(root, searchKey);
    if (foundNode != NULL)
        printf("��� %d�� ã�ҽ��ϴ�.\n", searchKey);
    else
        printf("��� %d�� ã�� ���߽��ϴ�.\n", searchKey);

    // ��� ����
    printf("��� 14 ���� �� ���� ��ȸ: ");
    root = deleteNode(root, 14);
    inorder(root);
    printf("\n");

    // Ʈ�� �޸� ����
    freeTree(root);

    return 0;
}
