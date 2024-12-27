#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
} ListNode;

typedef struct LinkedList_h {
	ListNode* head;
} LinkedList_h;

LinkedList_h* createLinkedList_h() {
	LinkedList_h* DL;
	DL = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	DL->head = NULL;
	return DL;
}

void printList(LinkedList_h* DL) {
	ListNode* p;
	printf("DL = (");
	p = DL->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->rlink;
		if (p != NULL) printf(", ");
	}
	printf(")\n");
}

// 이중 연결 리스트에 마지막 노드로 삽입하는 연산
void insertNode(LinkedList_h* DL, const char* x) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0';
	newNode->llink = NULL;  // 새 노드의 이전 노드는 없으므로 NULL로 설정
	newNode->rlink = NULL;  // 새 노드의 다음 노드는 없으므로 NULL로 설정

	if (DL->head == NULL) {
		// 리스트가 비어 있는 경우 새 노드를 head로 설정
		DL->head = newNode;
	}
	else {
		// 리스트가 비어 있지 않은 경우 마지막 노드를 찾아서 연결
		ListNode* temp = DL->head;
		while (temp->rlink != NULL) {
			temp = temp->rlink;  // 마지막 노드로 이동
		}
		temp->rlink = newNode;   // 마지막 노드의 rlink가 새 노드를 가리키도록 설정
		newNode->llink = temp;   // 새 노드의 llink가 이전 노드를 가리키도록 설정
	}
}

// 이중 연결 리스트에서 노드 p를 삭제하는 연산
void deleteNode(LinkedList_h* DL, ListNode* p) {
	if (DL->head == NULL || p == NULL) return; // 리스트가 비어 있거나 삭제할 노드가 없음

	// 첫 번째 노드를 삭제하는 경우
	if (DL->head == p) {
		DL->head = p->rlink;  // 헤드를 다음 노드로 갱신
		if (DL->head != NULL) {  // 리스트에 노드가 하나 이상 남아있다면
			DL->head->llink = NULL;  // 새로운 헤드의 이전 노드는 NULL로 설정
		}
		free(p);
		return;
	}

	// 삭제할 노드가 중간이나 마지막 노드인 경우
	if (p->llink != NULL) {
		p->llink->rlink = p->rlink;  // 이전 노드의 rlink를 삭제할 노드의 rlink로 연결
	}
	if (p->rlink != NULL) {
		p->rlink->llink = p->llink;  // 다음 노드의 llink를 삭제할 노드의 llink로 연결
	}

	free(p);  // 노드 메모리 해제
}

int main() {
	LinkedList_h* list = createLinkedList_h();

	insertNode(list, "월");
	insertNode(list, "수");
	insertNode(list, "금");

	printf("리스트 내용:\n");
	printList(list);

	// "화"를 삭제
	ListNode* temp = list->head;
	while (temp != NULL && strcmp(temp->data, "수") != 0) {
		temp = temp->rlink;
	}
	if (temp != NULL) {
		deleteNode(list, temp);
	}

	printf("리스트 내용(화 삭제 후):\n");
	printList(list);

	free(list);
	return 0;
}
