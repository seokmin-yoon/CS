#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE	100

typedef char element;

element stack[STACK_SIZE];
int top = -1;

// ������ ������� Ȯ���ϴ� �Լ�
int isEmpty() {
    return (top == -1);
}

// ������ �� á���� Ȯ���ϴ� �Լ�
int isFull() {
    return (top == STACK_SIZE - 1);
}

// ���ÿ� �����͸� Ǫ���ϴ� �Լ�
void push(element item) {
    if (isFull()) {
        printf("������ �� á���ϴ�!\n");
        return;
    }
    stack[++top] = item;
    printf("Ǫ�õ� ������: %c\n", item);
}

// ���ÿ��� �����͸� ���ϴ� �Լ�
element pop() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return -1;  // ��� ���� ��� �߸��� ���� ��ȯ
    }
    return stack[top--];
}

// ������ �� ���� �ִ� ������(peek)�� Ȯ���ϴ� �Լ�
element peek() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return -1;  // ��� ���� ��� �߸��� ���� ��ȯ
    }
    return stack[top];
}

// ������ ����ϴ� �Լ�
void printStack() {
    if (isEmpty()) {
        printf("������ ����ֽ��ϴ�!\n");
        return;
    }
    printf("���� ����: ");
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
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