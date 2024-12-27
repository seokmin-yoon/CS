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
	LinkedList_h* L;
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(LinkedList_h* L) {
	if (L == NULL || L->head == NULL) return;
	ListNode* p = L->head;
	ListNode* temp;
	do {
		temp = p;
		p = p->link;
		free(temp);
	} while (p != L->head);
	free(L);
}

void printList(LinkedList_h* CL) {
	if (CL == NULL || CL->head == NULL) {
		printf("CL = ()\n");
		return;
	}
	ListNode* p = CL->head;
	printf("CL = (");
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(")\n");
}

// 원형 연결 리스트에서 첫 번째 노드로 삽입하는 연산
void insertFirstNode(LinkedList_h* CL, const char* x) {
	if (CL == NULL) return;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0';
	if (CL->head == NULL) {
		// 리스트가 비어있는 경우
		newNode->link = newNode;
		CL->head = newNode;
	}
	else {
		// 리스트에 노드가 있는 경우
		ListNode* temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		temp->link = newNode;
		newNode->link = CL->head;
		CL->head = newNode;
	}
}

// 원형 연결 리스트에서 노드 p를 삭제하는 연산
void deleteNode(LinkedList_h* CL, ListNode* p) {
	ListNode* pre;

	if (CL->head == NULL || p == NULL) return; // 공백 리스트 또는 삭제할 노드가 없는 경우 중단

	// 리스트에 노드가 한 개만 있는 경우
	if (CL->head == CL->head->link) {
		if (CL->head == p) { // 삭제할 노드가 유일한 노드라면
			free(CL->head);  // 메모리 해제
			CL->head = NULL; // 리스트 초기화
		}
		return;
	}

	// 삭제할 노드가 첫 번째 노드인 경우
	if (p == CL->head) {
		// 마지막 노드를 찾아야 함
		pre = CL->head;
		while (pre->link != CL->head) {
			pre = pre->link;
		}
		pre->link = CL->head->link; // 마지막 노드가 첫 번째 노드의 다음 노드를 가리키도록 설정
		CL->head = CL->head->link; // 헤드 갱신
		free(p);                   // 삭제 노드 메모리 해제
		return;
	}

	// 삭제할 노드가 첫 번째 노드가 아닌 경우
	pre = CL->head;
	while (pre->link != p && pre->link != CL->head) {
		pre = pre->link;
	}

	if (pre->link == p) { // 선행 노드를 찾은 경우
		pre->link = p->link; // 선행 노드와 삭제 노드의 다음 노드 연결
		free(p);             // 삭제 노드 메모리 해제
	}
}

int main() {
	LinkedList_h* CL = createLinkedList_h();

	// 원형 연결 리스트에 노드 삽입
	insertFirstNode(CL, "월");
	insertFirstNode(CL, "화");
	insertFirstNode(CL, "수");
	printList(CL); // 출력: 수 화 월

	// 노드 삭제
	deleteNode(CL, CL->head); // "수" 노드 삭제
	printList(CL); // 출력: 화 월

	deleteNode(CL, CL->head); // "화" 노드 삭제
	printList(CL); // 출력: 월

	deleteNode(CL, CL->head); // "월" 노드 삭제
	printList(CL); // 출력: 리스트가 비어있습니다.

	freeLinkedList_h(CL);
	return 0;
}

/*
// 원형 연결 리스트의 첫 번째 노드로 삽입하는 연산
void insertFirstNode(LinkedList_h* CL, const char* x) {
	if (CL == NULL) return;
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0';
	if (CL->head == NULL) {
		// 리스트가 비어있는 경우
		newNode->link = newNode;
		CL->head = newNode;
	}
	else {
		// 리스트에 노드가 있는 경우
		ListNode* temp = CL->head;
		while (temp->link != CL->head) {
			temp = temp->link;
		}
		temp->link = newNode;
		newNode->link = CL->head;
		CL->head = newNode;
	}
}

// 원형 연결 리스트에서 pre 노드 뒤에 삽입하는 연산
void insertMiddleNode(LinkedList_h* CL, ListNode* pre, const char* x) {
	if (CL == NULL || pre == NULL) {
		printf("오류: 연결 리스트 또는 pre 노드가 NULL입니다.\n");
		return;
	}

	// 새로운 노드 생성 및 데이터 초기화
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (!newNode) {
		printf("오류: 메모리 할당 실패\n");
		return;
	}

	strncpy(newNode->data, x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0'; // 문자열 종료 보장

	// 노드 삽입
	newNode->link = pre->link; // 새 노드의 링크를 pre의 다음 노드로 설정
	pre->link = newNode;       // pre의 링크를 새 노드로 설정
}

// 원형 연결 리스트에 노드를 삽입하는 연산 (마지막 노드로)
void insertNode(LinkedList_h* CL, const char* x) {
	ListNode* newNode;
	ListNode* temp;

	// 새 노드 생성 및 데이터 복사
	newNode = (ListNode*)malloc(sizeof(ListNode));
	strncpy_s(newNode->data, sizeof(newNode->data), x, sizeof(newNode->data) - 1);
	newNode->data[sizeof(newNode->data) - 1] = '\0'; // 문자열 종료 보장
	newNode->link = NULL; // 초기화 (비어 있는 상태로 시작)

	if (CL->head == NULL) { // 현재 리스트가 공백인 경우
		CL->head = newNode;    // 새 노드를 리스트의 시작 노드로 설정
		newNode->link = newNode; // 자기 자신을 가리키도록 설정
	}
	else {
		// 현재 리스트가 공백이 아닌 경우
		temp = CL->head;
		while (temp->link != CL->head) { // 원형 연결 리스트에서 마지막 노드 찾기
			temp = temp->link;
		}
		temp->link = newNode; // 마지막 노드의 다음 노드로 새 노드 연결
		newNode->link = CL->head; // 새 노드의 다음 노드를 리스트의 시작 노드로 연결
	}
}

// 원형 연결 리스트에서 노드 p를 삭제하는 연산
void deleteNode(LinkedList_h* CL, ListNode* p) {
	ListNode* pre;

	if (CL->head == NULL || p == NULL) return; // 공백 리스트 또는 삭제할 노드가 없는 경우 중단

	// 리스트에 노드가 한 개만 있는 경우
	if (CL->head == CL->head->link) {
		if (CL->head == p) { // 삭제할 노드가 유일한 노드라면
			free(CL->head);  // 메모리 해제
			CL->head = NULL; // 리스트 초기화
		}
		return;
	}

	// 삭제할 노드가 첫 번째 노드인 경우
	if (p == CL->head) {
		// 마지막 노드를 찾아야 함
		pre = CL->head;
		while (pre->link != CL->head) {
			pre = pre->link;
		}
		pre->link = CL->head->link; // 마지막 노드가 첫 번째 노드의 다음 노드를 가리키도록 설정
		CL->head = CL->head->link; // 헤드 갱신
		free(p);                   // 삭제 노드 메모리 해제
		return;
	}

	// 삭제할 노드가 첫 번째 노드가 아닌 경우
	pre = CL->head;
	while (pre->link != p && pre->link != CL->head) {
		pre = pre->link;
	}

	if (pre->link == p) { // 선행 노드를 찾은 경우
		pre->link = p->link; // 선행 노드와 삭제 노드의 다음 노드 연결
		free(p);             // 삭제 노드 메모리 해제
	}
}
*/