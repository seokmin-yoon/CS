#include <stdio.h>
#include <stdlib.h>

typedef char element;

// 연결 리스트의 노드 구조체 정의
typedef struct Node {
    element data;
    struct Node* link;  // 다음 노드를 가리키는 포인터
} Node;

Node* top = NULL;  // 스택의 top을 나타내는 포인터

// 스택이 비었는지 확인하는 함수
int isEmpty() {
    return (top == NULL);
}

// 스택에 데이터를 푸시하는 함수
void push(element item) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // 새 노드를 동적 할당
    if (newNode == NULL) {  // 메모리 할당 실패 시
        printf("메모리 할당 실패!\n");
        return;
    }
    newNode->data = item;  // 노드에 데이터 저장
    newNode->link = top;    // 새 노드의 링크는 현재 top을 가리킴
    top = newNode;          // top을 새 노드로 갱신
    printf("푸시된 데이터: %c\n", item);
}

// 스택에서 데이터를 팝하는 함수
element pop() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return -1;  // 비어 있을 경우 잘못된 값을 반환
    }
    Node* temp = top;         // 팝할 노드를 임시로 저장
    element item = temp->data;  // 팝할 데이터를 저장
    top = top->link;           // top을 다음 노드로 갱신
    free(temp);                // 팝한 노드를 메모리에서 해제
    return item;
}

// 스택의 맨 위에 있는 데이터(peek)를 확인하는 함수
element peek() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return -1;  // 비어 있을 경우 잘못된 값을 반환
    }
    return top->data;
}

// 스택을 출력하는 함수
void printStack() {
    if (isEmpty()) {
        printf("스택이 비어있습니다!\n");
        return;
    }
    printf("스택 상태: ");
    Node* temp = top;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
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
