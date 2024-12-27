#include <stdio.h>
#include <stdlib.h>

typedef char element;

// ���� ����Ʈ�� ��� ����ü ����
typedef struct Node {
    element data;
    struct Node* link;  // ���� ��带 ����Ű�� ������
} Node;

Node* top = NULL;  // ������ top�� ��Ÿ���� ������

// ������ ������� Ȯ���ϴ� �Լ�
int isEmpty() {
    return (top == NULL);
}

// ���ÿ� �����͸� Ǫ���ϴ� �Լ�
void push(element item) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // �� ��带 ���� �Ҵ�
    if (newNode == NULL) {  // �޸� �Ҵ� ���� ��
        printf("�޸� �Ҵ� ����!\n");
        return;
    }
    newNode->data = item;  // ��忡 ������ ����
    newNode->link = top;    // �� ����� ��ũ�� ���� top�� ����Ŵ
    top = newNode;          // top�� �� ���� ����
    printf("Ǫ�õ� ������: %c\n", item);
}

// ���ÿ��� �����͸� ���ϴ� �Լ�
element pop() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return -1;  // ��� ���� ��� �߸��� ���� ��ȯ
    }
    Node* temp = top;         // ���� ��带 �ӽ÷� ����
    element item = temp->data;  // ���� �����͸� ����
    top = top->link;           // top�� ���� ���� ����
    free(temp);                // ���� ��带 �޸𸮿��� ����
    return item;
}

// ������ �� ���� �ִ� ������(peek)�� Ȯ���ϴ� �Լ�
element peek() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return -1;  // ��� ���� ��� �߸��� ���� ��ȯ
    }
    return top->data;
}

// ������ ����ϴ� �Լ�
void printStack() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return;
    }
    printf("���� ����: ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    // ���ÿ� ������ Ǫ��
    push('A');
    push('B');
    push('C');

    // ���� ���
    printStack();

    // ���ÿ��� ������ ��
    printf("�˵� ������: %c\n", pop());

    // ���� ���� ���
    printStack();

    // ������ �� �� ������ Ȯ��
    printf("������ �� �� ������: %c\n", peek());

    return 0;
}
