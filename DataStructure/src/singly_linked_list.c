#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} ListNode;

typedef struct LinkedList_h {
    ListNode* head;
} LinkedList_h;

LinkedList_h* createLinkedList_h() {
    LinkedList_h* L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
    L->head = NULL;
    return L;
}

void freeLinkedList_h(LinkedList_h* L) {
    ListNode* p;
    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;
        free(p);
    }
}

void printList(LinkedList_h* L) {
    ListNode* p = L->head;
    printf("L = (");
    while (p != NULL) {
        printf("%s", p->data);
        p = p->link;
        if (p != NULL) printf(", ");
    }
    printf(")\n");
}

// 단순 연결 리스트에 마지막 노드로 삽입하는 연산
void insertNode(LinkedList_h* L, const char* x) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
    newNode->data[sizeof(newNode->data) - 1] = '\0';
    newNode->link = NULL;

    if (L->head == NULL) {
        L->head = newNode;
        return;
    }

    ListNode* temp = L->head;
    while (temp->link != NULL) temp = temp->link; // 마지막 노드로 이동
    temp->link = newNode;
}

// 단순 연결 리스트에서 노드 p를 삭제하는 연산
void deleteNode(LinkedList_h* L, ListNode* p) {
    if (L->head == NULL || p == NULL) return; // 리스트가 비어 있거나 삭제할 노드가 없음

    if (L->head == p) {  // 삭제할 노드가 첫 번째 노드일 경우
        L->head = p->link;  // 헤드를 다음 노드로 갱신
        free(p);
        return;
    }

    // 노드를 찾기 위한 선행 노드 찾기
    ListNode* pre = L->head;
    while (pre->link != NULL && pre->link != p) {
        pre = pre->link;
    }

    if (pre->link == p) {  // p를 찾았을 경우
        pre->link = p->link;  // 선행 노드와 삭제 노드의 링크를 연결
        free(p);  // 노드 메모리 해제
    }
}

int main() {
    LinkedList_h* list = createLinkedList_h();

    insertNode(list, "월");
    insertNode(list, "화");
    insertNode(list, "수");

    printf("초기 리스트:\n");
    printList(list);

    // "화" 삭제하기
    ListNode* temp = list->head;
    while (temp != NULL && strcmp(temp->data, "화") != 0) {
        temp = temp->link;
    }

    if (temp != NULL) {
        deleteNode(list, temp);  // "화" 노드 삭제
        printf("노드 화 삭제 후:\n");
        printList(list);
    }
    else {
        printf("삭제할 노드를 찾을 수 없습니다.\n");
    }

    freeLinkedList_h(list);
    free(list);

    return 0;
}
