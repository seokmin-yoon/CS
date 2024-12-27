#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE	100

typedef char element;

element stack[STACK_SIZE];
int top = -1;

// 스택이 비었는지 확인하는 함수
int isEmpty() {
    return (top == -1);
}

// 스택이 꽉 찼는지 확인하는 함수
int isFull() {
    return (top == STACK_SIZE - 1);
}

// 스택에 데이터를 푸시하는 함수
void push(element item) {
    if (isFull()) {
        printf("스택이 꽉 찼습니다!\n");
        return;
    }
    stack[++top] = item;
    printf("푸시된 데이터: %c\n", item);
}

// 스택에서 데이터를 팝하는 함수
element pop() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return -1;  // 비어 있을 경우 잘못된 값을 반환
    }
    return stack[top--];
}

// 스택의 맨 위에 있는 데이터(peek)를 확인하는 함수
element peek() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return -1;  // 비어 있을 경우 잘못된 값을 반환
    }
    return stack[top];
}

// 스택을 출력하는 함수
void printStack() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return;
    }
    printf("스택 상태: ");
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

int main() {
    // 스택에 데이터 푸시
    push('A');
    push('B');
    push('C');

    // 스택 출력
    printStack();

    // 스택에서 데이터 팝
    printf("팝된 데이터: %c\n", pop());

    // 스택 상태 출력
    printStack();

    // 스택의 맨 위 데이터 확인
    printf("스택의 맨 위 데이터: %c\n", peek());

    return 0;
}