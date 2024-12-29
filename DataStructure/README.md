# 1. 리스트
## 1.1. 선형 리스트
배열을 이용하여 구현할 자료들을 논리적인 순서로 메모리에 연속 저장하는 방식의 자료 구조

- 배열: <인덱스, 값>
    - 인덱스: 자료의 순서

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-1.png?raw=true)

## 1.2. 연결 리스트
포인터를 이용하여 구현할 자료의 논리적인 순서와 메모리에 저장되는 물리적인 순서가 다르게 저장되는 방식의 자료 구조

- 노드: <원소, 주소>
    - 주소(포인터): 다음 노드의 메모리 주소

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-2.png?raw=true)

### 단순 연결 리스트
노드가 하나의 링크 필드에 의해서 다음 노드와 연결되는 리스트

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-3.png?raw=true)

singly_linked_list.c

```c
typedef struct ListNode {
    char data[4];
    struct ListNode* link;
} ListNode;

typedef struct LinkedList_h {
    ListNode* head;
} LinkedList_h;

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
```

```c
초기 리스트:
L = (월, 화, 수)
노드 화 삭제 후:
L = (월, 수)
```

### 원형 연결 리스트
단순 연결 리스트에서 마지막 노드를 리스트의 첫 번째 노드로 가리키도록 하여 원형 구조로 만든 리스트

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-4.png?raw=true)

circular_linked_list.c

```c
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
} ListNode;

typedef struct LinkedList_h {
	ListNode* head;
} LinkedList_h;

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
```

```c
월,화,수 노드 삽입
CL = (수, 화, 월)
수 노드 삭제
CL = (화, 월)
화 노드 삭제
CL = (월)
월 노드 삭제
CL = ()
```

### 이중 연결 리스트
리스트를 양쪽 방향으로 순회할 수 있도록 링크 필드를 두 개 사용하여 양방향 노드를 연결한 리스트

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/1-5.png?raw=true)

douply_linked_list.c

```c
typedef struct ListNode{
	struct ListNode* llink;
	char data[4];
	struct ListNode* rlink;
} ListNode;

typedef struct LinkedList_h {
	ListNode* head;
} LinkedList_h;

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
```

```c
리스트 내용:
DL = (월, 수, 금)
리스트 내용(화 삭제 후):
DL = (월, 금)
```

# 2. 스택 (Stack)
자료를 차곡차곡 쌓아 올린 형태의 자료구조
- LIFO (Last-In, First-Out)
- 삽입 연산: push, 위치: top (아래 그림의 노란 블록)
- 삭제 연산: pop, 위치: top

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/2-1.png?raw=true)

## 2.1. 순차 스택
배열을 이용한 스택

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/2-2.png?raw=true)

stack_array.c

```c
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
```

```c
푸시된 데이터: A
푸시된 데이터: B
푸시된 데이터: C
스택 상태: A B C
팝된 데이터: C
스택 상태: A B
스택의 맨 위 데이터: B
```

## 2.2. 연결 스택
연결 리스트를 이용한 스택

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/2-3.png?raw=true)

stack_linked_list.c

```c
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
```

```c
푸시된 데이터: A
푸시된 데이터: B
푸시된 데이터: C
스택 상태: C B A
팝된 데이터: C
스택 상태: B A
스택의 맨 위 데이터: B
```

# 3. 큐 (Queue)
데이터를 뒤에서만 삽입하고, 앞에서만 삭제할 수 있는 구조 
- FIFO (First-In, First-Out)
- 삽입:  enqueue, 위치: rear
- 삭제: dequeue, 위치: front

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-1.png?raw=true)

## 3.1. 순차 큐
1차원 배열을 이용하여 순차적으로 연결된 큐
- rear가 배열의 마지막 인덱스에 도달하면, 배열에 빈자리가 있어도 포화 상태가 될 수 있음

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-2.png?raw=true)

queue_array.c

```c
typedef char element;

typedef struct {
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue() {
	QueueType* Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = -1;
	Q->rear = -1;
	return Q;
}

// 순차 큐가 비었는지 확인하는 함수
int isEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

// 순차 큐가 꽉 찼는지 확인하는 함수
int isFull(QueueType* Q) {
	return (Q->rear == Q_SIZE - 1);
}

// 순차 큐에 데이터를 삽입하는 함수
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear++;
		Q->queue[Q->rear] = item;
	}
}

// 순차 큐에서 데이터를 제거하는 함수
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return;
	else {
		Q->front++;
		return Q->queue[Q->front];
	}
}

// 순차 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType* Q) {
	if (isEmpty(Q)) return;
	else return Q->queue[Q->front + 1];
}
```

```c
Queue elements: A B C
Dequeued: A
Queue elements: B C
```

## 3.2. 원형 큐
1차원 배열에서 처음과 끝을 논리적으로 연결한 큐
- 순차 큐의 잘못된 포화 상태 문제를 해결함

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-3.png?raw=true)

circular_queue_array.c

```c
typedef char element;

typedef struct {
	element queue[Q_SIZE];
	int front, rear;
} QueueType;

QueueType* createQueue() {
	QueueType* Q = (QueueType*)malloc(sizeof(QueueType));
	Q->front = 0;
	Q->rear = 0;
	return Q;
}

// 원형 큐가 비었는지 확인하는 함수
int isEmpty(QueueType* Q) {
	return (Q->front == Q->rear);
}

// 원형 큐가 꽉 찼는지 확인하는 함수
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q_SIZE == Q->front);
}

// 원형 큐에 데이터를 삽입하는 함수
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) return;
	else {
		Q->rear = (Q->rear + 1) % Q_SIZE;  // rear 순환하도록 처리
		Q->queue[Q->rear] = item;
	}
}

// 원형 큐에서 데이터를 제거하는 함수
element deQueue(QueueType* Q) {
	if (isEmpty(Q)) return '\0';
	else {
		Q->front = (Q->front + 1) % Q_SIZE;  // front 순환하도록 처리
		return Q->queue[Q->front];
	}
}

// 원형 큐의 가장 앞에 있는 원소를 검색하는 연산
element peek(QueueType* Q) {
    if (isEmpty(Q)) {
        printf("Queue is empty!\n");
        return '\0';
    } else {
        return Q->queue[(Q->front + 1) % Q_SIZE];
    }
}
```

```c
Circular Queue: [  A  B  C]
Dequeued: A
Circular Queue: [  B  C]
Peek: B
```

## 3.3. 연결 큐
노드의 양쪽에 포인터를 연결하여 구성된 큐

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/3-4.png?raw=true)

queue_linked_list.c

```c
typedef char element;

typedef struct QNode {
	element data;
	struct QNode* link;
} QNode;

typedef struct {
	QNode* front, *rear;
} LQueueType;

LQueueType* createLinkedQueue() {
	LQueueType* LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

// 연결 큐가 비었는지 확인하는 함수
int isEmpty(LQueueType* LQ) {
	return (LQ->front == NULL);
}

// 연결 큐에 데이터 삽입하는 함수
void enQueue(LQueueType* LQ, element item) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;

    if (isEmpty(LQ)) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
}

// 연결 큐에서 데이터 제거하는 함수
element deQueue(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return '\0';
    }

    QNode* temp = LQ->front;
    element item = temp->data;
    LQ->front = LQ->front->link;

    if (LQ->front == NULL) {
        LQ->rear = NULL;  // 큐가 비어 있으면 rear도 NULL로 설정
    }

    free(temp);
    return item;
}

// 연결 큐의 가장 앞에 있는 원소를 확인하는 함수
element peek(LQueueType* LQ) {
    if (isEmpty(LQ)) {
        printf("Queue is empty!\n");
        return '\0';
    }
    return LQ->front->data;
}
```

```c
Linked Queue elements: A B C D
Dequeued: A
Linked Queue elements: B C D
```

# 4. 데크 (Deque)
큐 두 개 중 하나를 좌우로 뒤집어서 붙인 구조로, 큐의 양쪽 끝에서 삽입과 삭제 연산을 수행

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/4-1.png?raw=true)

## 4.1. 순차 데크
효율적인 공간 활용을 위해 원형 큐 기반 데크
- 양쪽 끝에서 삽입, 삭제 연산을 수행하면서 오버헤드가 발생하므로 순차 자료구조는 비효율적

deque_circular_queue.c

```c
typedef char element;

typedef struct {
    element data[MAX_DEQUE_SIZE];
    int front;
    int rear;
} DQueType;

// 순차 데크 생성 함수
DQueType* createDQue() {
    DQueType* DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = 0;
    DQ->rear = 0;
    return DQ;
}

// 순차 데크가 비었는지 확인하는 함수
int isEmpty(DQueType* DQ) {
    return (DQ->front == DQ->rear);
}

// 순차 데크가 가득 찼는지 확인하는 함수
int isFull(DQueType* DQ) {
    return ((DQ->rear + 1) % MAX_DEQUE_SIZE == DQ->front);
}

// 앞에 데이터 삽입하는 함수
void insertFront(DQueType* DQ, element item) {
    if (isFull(DQ)) {
        printf("Array-based Deque is full!\n");
        return;
    }
    DQ->front = (DQ->front - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    DQ->data[DQ->front] = item;
}

// 뒤에 데이터 삽입하는 함수
void insertRear(DQueType* DQ, element item) {
    if (isFull(DQ)) {
        printf("Array-based Deque is full!\n");
        return;
    }
    DQ->data[DQ->rear] = item;
    DQ->rear = (DQ->rear + 1) % MAX_DEQUE_SIZE;
}

// 앞에서 데이터 제거하는 함수
element deleteFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    element item = DQ->data[DQ->front];
    DQ->front = (DQ->front + 1) % MAX_DEQUE_SIZE;
    return item;
}

// 뒤에서 데이터 제거하는 함수
element deleteRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    DQ->rear = (DQ->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
    return DQ->data[DQ->rear];
}

// 순차 데크의 앞에 있는 원소 확인하는 함수
element peekFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    return DQ->data[DQ->front];
}

// 순차 데크의 뒤에 있는 원소 확인하는 함수
element peekRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Array-based Deque is empty!\n");
        return '\0';
    }
    return DQ->data[(DQ->rear - 1 + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE];
}
```

```c
Array-based Deque elements: A
Array-based Deque elements: A B C
Deleted from front: A
Array-based Deque elements: B C
Deleted from rear: C
Array-based Deque elements: B
Front element: B
Rear element: B
```

## 4.2. 연결 데크
이중 연결 리스트를 사용한 데크

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/4-2.png?raw=true)

deque_douply_linked_list.c

```c
typedef char element;

typedef struct DQNode {
    element data;
    struct DQNode* llink;
    struct DQNode* rlink;
} DQNode;

typedef struct {
    DQNode* front, * rear;
} DQueType;

DQueType* createDQue() {
    DQueType* DQ = (DQueType*)malloc(sizeof(DQueType));
    DQ->front = NULL;
    DQ->rear = NULL;
    return DQ;
}

// 연결 데크가 비었는지 확인하는 함수
int isEmpty(DQueType* DQ) {
    return (DQ->front == NULL);
}

// 앞에 데이터 삽입하는 함수
void insertFront(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->llink = NULL;
    newNode->rlink = DQ->front;

    if (isEmpty(DQ)) {
        DQ->front = DQ->rear = newNode;
    }
    else {
        DQ->front->llink = newNode;
        DQ->front = newNode;
    }
}

// 뒤에 데이터 삽입하는 함수
void insertRear(DQueType* DQ, element item) {
    DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
    newNode->data = item;
    newNode->rlink = NULL;
    newNode->llink = DQ->rear;

    if (isEmpty(DQ)) {
        DQ->front = DQ->rear = newNode;
    }
    else {
        DQ->rear->rlink = newNode;
        DQ->rear = newNode;
    }
}

// 앞에서 데이터 제거하는 함수
element deleteFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }

    DQNode* temp = DQ->front;
    element item = temp->data;
    DQ->front = DQ->front->rlink;

    if (DQ->front == NULL) {
        DQ->rear = NULL;  // 데크가 비어있으면 rear도 NULL
    }
    else {
        DQ->front->llink = NULL;
    }

    free(temp);
    return item;
}

// 뒤에서 데이터 제거하는 함수
element deleteRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }

    DQNode* temp = DQ->rear;
    element item = temp->data;
    DQ->rear = DQ->rear->llink;

    if (DQ->rear == NULL) {
        DQ->front = NULL;  // 데크가 비어있으면 front도 NULL
    }
    else {
        DQ->rear->rlink = NULL;
    }

    free(temp);
    return item;
}

// 연결 데크의 앞에 있는 원소 확인하는 함수
element peekFront(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }
    return DQ->front->data;
}

// 연결 데크의 뒤에 있는 원소 확인하는 함수
element peekRear(DQueType* DQ) {
    if (isEmpty(DQ)) {
        printf("Linked Deque is empty!\n");
        return '\0';
    }
    return DQ->rear->data;
}
```

```c
Linked Deque elements: A
Linked Deque elements: A B C
Deleted from front: A
Linked Deque elements: B C
Deleted from rear: C
Linked Deque elements: B
Front element: B
Rear element: B
```

# 5. 트리
상위 원소에서 하위 원소로 내려가면서 확장되는 트리(나무)모양의 계층형 구조, (1:N 관계)
- **노드**: 트리의 원소
- **간선**: 노드를 연결하는 선
- **루트 노드**: 트리의 시작 노드
- **부모 노드**:  자식 노드와 연결된 상위 노드
- **자식 노드**: 부모 노드와 연결된 하위 노드
- **단말 노드 (leaf)**: 자식 노드가 없는 노드
- **서브 트리 (forest)**: 부모 노드와 연결된 간선을 끊었을 때 생성되는 트리
- **차수 (degree)**: 노드에 연결된 자식 노드의 수
- **높이**: 노드의 레벨
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-1.png?raw=true)

## 5.1. 이진 트리
트리의 모든 노드의 차수가 2 이하를 가져 왼쪽과 오른쪽 자식만 가지는 노드로 구성된 트리
- 노드가 n개 일 때, 간선은 n-1개
- 높이가 h일 때, 가질 수 있는 노드 개수는 최소 h+1, 최대 2^(h+1)-1

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-2.png?raw=true)

- **포화 이진 트리 (Full Binary Tree)**: 모든 레벨에 가능한 최대 개수의 노드로 차 있는 이진 트리
    - 각 레벨 k에서 노드는 2^k개
      
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-3.png?raw=true)

- **완전 이진 트리 (Complete Binary Tree)**: 모든 레벨이 가득 차 있으며, 마지막 레벨만 노드가 왼쪽부터 차례대로 채워진 이진 트리

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-4.png?raw=true)

- **편향 이진 트리 (Skewed Binary Tree)**: 모든 노드가 한쪽 방향(왼쪽 또는 오른쪽)으로만 서브 트리를 가지고 있는 이진 트리
    - 높이가 h일 때, 노드는 h+1개

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-5.png?raw=true)

### 배열 기반 구현
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-6.png?raw=true)

binary_tree_array.c

```c
typedef char element;

// 이진 트리를 나타내는 구조체
typedef struct {
    element data[MAX_SIZE];  // 트리 데이터를 저장할 배열
    int size;            // 트리의 현재 크기
} BinaryTree;

// 트리 초기화
void initTree(BinaryTree* tree) {
    tree->size = 0;
}

// 트리에 노드 삽입
void insertNode(BinaryTree* tree, element value) {
    if (tree->size >= MAX_SIZE) {
        printf("트리가 가득 찼습니다.\n");
        return;
    }
    tree->data[tree->size] = value;
    tree->size++;
}

// 트리 출력 (단순히 배열을 출력)
void printTree(BinaryTree* tree) {
    printf("이진 트리: ");
    for (int i = 0; i < tree->size; i++) {
        printf("%c ", tree->data[i]);
    }
    printf("\n");
}

// 트리 그래프 형태로 출력 (계층적 구조)
void printTreeGraph(BinaryTree* tree, int index, int level) {
    if (index >= tree->size) return;

    // 오른쪽 자식 노드 먼저 출력 (오른쪽부터 왼쪽으로 출력)
    int rightIndex = rightChild(index);
    if (rightIndex < tree->size) {
        printTreeGraph(tree, rightIndex, level + 1);
    }

    // 현재 노드 출력 (중앙에 배치)
    for (int i = 0; i < level; i++) {
        printf("    ");  // 공백을 넣어서 들여쓰기
    }
    printf("%c[%d]\n", tree->data[index], index);

    // 왼쪽 자식 노드 출력
    int leftIndex = leftChild(index);
    if (leftIndex < tree->size) {
        printTreeGraph(tree, leftIndex, level + 1);
    }
}

// 왼쪽 자식의 인덱스 반환
int leftChild(int index) {
    return 2 * index + 1;
}

// 오른쪽 자식의 인덱스 반환
int rightChild(int index) {
    return 2 * index + 2;
}

// 부모의 인덱스 반환
int parent(int index) {
    if (index == 0) return -1;  // 루트 노드는 부모가 없다
    return (index - 1) / 2;
}
```

```c
        G[6]
    C[2]
        F[5]
A[0]
        E[4]
    B[1]
        D[3]
```

### 연결 리스트 기반 구현
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-7.png?raw=true)

binary_tree_linked_list.c

```c
// 이진 트리의 노드 구조체
typedef struct treeNode {
    element data;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

// 이진 트리 삽입 함수 (가장 간단한 형태로 삽입: 왼쪽 또는 오른쪽 자식이 비어있으면 삽입)
void insertNode(treeNode** root, element data) {
    if (*root == NULL) {
        *root = createNode(data);
    }
    else {
        // 왼쪽 자식부터 먼저 삽입하도록 변경
        if ((*root)->left == NULL) {
            (*root)->left = createNode(data);
        }
        else if ((*root)->right == NULL) {
            (*root)->right = createNode(data);
        }
        else {
            // 왼쪽 자식과 오른쪽 자식이 다 차 있으면 재귀적으로 삽입
            insertNode(&(*root)->left, data);
        }
    }
}

// 전위 순회 출력
void preorder(treeNode* root) {
    if (root != NULL) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 중위 순회 출력 함수
void inorder(treeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

// 후위 순회 출력
void postorder(treeNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}
```

```c
전위 순회 (Pre-order): A B D E C
중위 순회 (In-order): D B E A C
후위 순회 (Post-order): D E B C A
```

## 5.2. 이진 트리 순회
- **D**: 현재 (루트) 노드
- **L**: 현재 노드의 왼쪽  노드로 이동
- **R**: 현재 노드의 오른쪽 노드로 이동

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-8.png?raw=true)

- **전위 순회(preorder)**: D → L → R
    - 위 트리에서 전위 순회 경로: A-B-D-H-E-I-J-C-F-G-K
- **중위 순회(inorder)**: L → D → R
    - 위 트리에서 중위 순회 경로: H-D-B-I-E-J-A-F-C-G-K
- **후위 순회(postorder)**: L → R → D
    - 위 트리에서 후위 순회 경로: H-D-I-J-E-B-F-K-G-C-A

## 5.3. 이진 탐색 트리 (Binary search tree)
이진 트리를 탐색용 자료구조를 사용하기 위해 원소 크기에 따라 노드 위치를 정의한 것
- 모든 원소는 서로 다른 유일한 키를 가짐
- 왼쪽 서브 트리에 있는 원소들의 키는 그 루트의 키보다 작음
- 오른쪽 서브 트리에 있는 원소들의 키는 그 루트의 키보다 큼
- 양쪽 서브 트리는 모두 이진 트리임

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-9.png?raw=true)

1. 이진 탐색 트리의 탐색 과정
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-10.png?raw=true)

2. 이진 탐색 트리의 삽입 과정
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-11.png?raw=true)

3. 이진 탐색 트리의 삭제 과정
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-12.png?raw=true)

binary_search_tree.c

```c
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
```

```c
이진 탐색 트리 전위 순회: 8 3 2 5 10 14 11 16
이진 탐색 트리 중위 순회: 2 3 5 8 10 11 14 16
이진 탐색 트리 후위 순회: 2 5 3 11 16 14 10 8
노드 4 삽입 후 중위 순회: 2 3 4 5 8 10 11 14 16
노드 11를 찾았습니다.
노드 14 삭제 후 중위 순회: 2 3 4 5 8 10 11 16
```

## 5.4. AVL 트리 (Adelson-Velskii, Landis Tree)
균형 잡힌 이진 탐색 트리로, 각 노드에서 왼쪽 서브 트리 높이와 오른쪽 서브 트리 높이의 차이가 1 이하인 트리
- **균형 이진 탐색 트리 또는 균형 트리**: 이진 탐색 트리의 왼쪽과 오른쪽 서브 트리의 높이에 대한 균형 조건을 추가한 트리
- **균형 인수 (BF: Balance Factor)**: 각 노드에서 왼쪽 서브 트리의 높이 hL (height of Left subtree)과 오른쪽 서브 트리 높이 hR (height of Right subtree)의 차이
    - BF = hL - hR
- AVL 트리의 각 노드는 균형 인수로 {-1, 0, +1} 값만 가질 수 있음

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-13.png?raw=true)

위 그림은 모든 노드가 균형 인수로 {-1, 0, 1} 값을 가지므로 AVL 트리임

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-14.png?raw=true)

위 그림은 균형 인수로 {-1, 0, 1} 외의 값을 가져 균형이 깨지므로 비 AVL 트리임

## 5.5. 힙 (Heap)
완전 이진 트리 형태에서, 노드 중 키 값이 가장 큰 노드나 키 값이 가장 작은 노드를 찾기 위해서 만든 자료 구조
- **최대 힙 (max heap)**: 키 값이 가장 큰 노드를  찾기 위한 완전 이진 트리
    - 부모 노드의 키가 자식 노드보다 큼
- **최소 힙 (min heap)** : 키 값이 가장 작은 노드를  찾기 위한 완전 이진  트리
    - 부모 노드의 키가 자식 노드보다 작음

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-15.png?raw=true)

### 배열 기반으로 최대 힙 구현
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/5-16.png?raw=true)

max_heap_array.c

```c
typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} heapType;

heapType* createHeap() {
	heapType* h = (heapType*)malloc(sizeof(heapType));
	h->heap_size = 0;
	return h;
}

// 힙에 삽입하는 연산 (최대 힙 구현)
void insertHeap(heapType* h, int item) {
	int i;

	// 1. 힙 크기 증가
	h->heap_size++;

	// 2. 마지막 위치에 아이템 삽입
	i = h->heap_size;

	// 3. 부모 노드와 비교하여 아이템이 더 크면 자리 교환 (최대 힙 유지)
	while (i != 1 && item > h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];  // 부모 노드 내려보냄
		i /= 2;  // 부모 노드로 이동
	}

	// 4. 아이템 삽입
	h->heap[i] = item;
}

// 힙의 루트를 삭제하는 연산 (가장 큰 값을 가지는 노드)
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;

	// 1. 루트 노드를 삭제하려면 먼저 루트 값을 저장하고, 마지막 노드를 루트로 이동
	item = h->heap[1];  // 삭제할 루트 값을 item에 저장
	temp = h->heap[h->heap_size];  // 마지막 노드 값을 temp에 저장

	// 2. 힙 크기를 하나 줄임
	h->heap_size = h->heap_size - 1;

	// 3. 루트에 마지막 노드(temp)를 삽입한 뒤, 힙 속성을 만족하도록 재조정
	parent = 1;  // 부모 노드는 루트(인덱스 1)부터 시작
	child = 2;   // 자식 노드는 왼쪽 자식부터 시작 (인덱스 2)

	// 4. 자식이 존재하는 동안 반복하여 힙의 속성(최대 힙)을 유지
	while (child <= h->heap_size) {
		// 자식이 둘 이상일 경우, 더 큰 자식을 선택
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) {
			child++;  // 오른쪽 자식이 더 크다면 오른쪽 자식으로 이동
		}

		// 5. temp 값이 자식 노드보다 크면 힙의 속성이 유지되므로 종료
		if (temp >= h->heap[child]) {
			break;
		}
		else {
			// 6. 자식 노드와 부모 노드의 값을 바꾸고, 부모는 자식으로 이동
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;  // 왼쪽 자식으로 이동
		}
	}

	// 7. 마지막으로 temp 값을 적절한 위치에 삽입
	h->heap[parent] = temp;

	// 8. 삭제된 루트 값을 반환
	return item;
}
```

```c
Heap: [20] [15] [19] [8] [13] [10]

 delete: [20]
 delete: [19]
 delete: [15]
 delete: [13]
 delete: [10]
 delete: [8]
```

# 6. 그래프
연결되어 있는 원소 사이의 다대다 관계를 표현하는 자료구조
- **G = (V, E)**
    - G: 그래프
    - V: 정점(노드) 집합
    - E: 간선(링크) 집합
- **인접 (adjacent)**: 두 정점을 연결하는 간선이 존재할 때, 두 정점을 서로 인접 되어 있다고 함
- **부속 (incident)**: 두 정점을 연결하는 간선이 존재할 때, 두 정점을 연결하는 간선은 부속 되어 있다고 함
- **사이클(cycle)**: 시작점과 끝점이 동일한 경로로, 모든 간선을 한 번씩만 지나면서 순환하는 경로

## 6.1. 그래프 종류
- **무방향 그래프 (undirected graph)**: 두 정점을 연결하는 간선에 방향이 없는 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-1.png?raw=true)

- **방향 그래프 (directed graph), 다이그래프 (digraph)**: 간선에 방향이 있는 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-2.png?raw=true)

- **완전 그래프 (complete graph)**: 각 정점에서 다른 모든 정점을 연결하여 최대로 많은 간선 수를 가진 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-3.png?raw=true)

- **부분 그래프 (subgraph)**: 원래의 그래프에서 정점이나 간선을 일부만 제외하여 만든 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-4.png?raw=true)

- **가중 그래프 (weight graph), 네트워크 (network)**: 정점을 연결하는 간선에 가중치를 할당한 그래프
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-5.png?raw=true)

## 6.2. 그래프 구현
### 인접 행렬
2차원 배열을 사용하여 그래프의 두 정점을 연결한 간선의 유무를 행렬로 나타내는 방법

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-6.png?raw=true)

graph_adjmatrix.c

```c
```

```c
```

### 인접 리스트
연결 리스트를 사용하여 각 정점에 대한 인접 정점들을 연결하여 나타내는 방법

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-7.png?raw=true)

graph_adjlist.c

```c
```

```c
```

## 6.3. 그래프 순회
### **깊이 우선 탐색 (DFS: Depth First Search)**
시작 정점에서 가능한 깊이까지 탐색한 후 되돌아와 미탐색 방향으로 진행해 모든 정점을 방문하는 방법
- 스택 사용
- **탐색 과정**
    1. 시작 정점 v를 결정 하여 방문
    2. 정점 v에 인접한 정점 중에서 방문하지 않은 정점 w가 
        1. 있으면 정점 v를 스택에 push하고 w를 방문
        2. 없으면 스택을 pop 하고 pop된 정점 v에서 2를 반복 수행
    3. 스택이 공백이 될 때까지 위를 반복

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-8.png?raw=true)

DFS.c

```c
```

```c
```

### **너비 우선 탐색 (BFS: Breadth First Search)**
시작 정점에서 가까운 정점부터 차례로 방문하며, 인접 정점을 레벨 별로 탐색하는 방법
- 큐 사용
- **탐색 과정**
    1. 시작 정점 v를 결정하여 방문
    2. 정점 v에 인접한 정점 중에서 방문하지 않은 정점이
        1. 있으면 정점 v를 큐에 enqueue
        2. 없으면 정점 v를 큐에서 dequeue하여 정점 w를 받고 2를 반복 수행
    3. 큐가 공백이 될 때까지 위를 반복

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-9.png?raw=true)

BFS.c

```c
```

```c
```

## 6.4. 신장 트리와 최소 비용 신장 트리
### 신장 트리 (Spanning Tree)
n개의 정점으로 이루어진 무 방향 그래프 G에서 n개의 모든 정점과 n-1개의 간선으로 만들어진 트리
![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-10.png?raw=true)

### 최소 비용 신장 트리 (Minimum cost Spanning Tree)
무 방향 가중치 그래프에서 신장 트리를 구성하는 간선들의 가중치 합이 최소인 신장 트리

### 크루스칼 알고리즘 (Kruskal Algorithm)
가중치가 높은 간선을 제거하면서 최소 비용 신장 트리를 만드는 방법
- Greedy Algorithm

- **MST 구하는 과정**
    1. 먼저 그래프 G의 모든 간선을 가중치에 따라 오름차순으로 정렬
    2. 그래프 G에 가중치가 가장 낮은 간선을 최소 비용 신장 트리(MST) 집합에 삽입
        1. 단, 싸이클을 형성하지 않는 간선을 삽입
    3. 그래프 G에 간선이 n-1개가 아니라면 2를 반복
    4. 그래프 G의 간선이 n-1개 라면 알고리즘 종료

알고리즘

kruskal_algorithm.c

```c
void kruskal(graphType* g) {
    Edge edges[MAX_EDGES];
    int edge_count = 0;

    // 간선 리스트로 변환 (인접 행렬에서 간선 리스트로)
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->adjMatrix[i][j] != 0) { // 간선이 존재하면
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].weight = g->adjMatrix[i][j];
                edge_count++;
            }
        }
    }

    // 간선을 가중치 순으로 정렬
    qsort(edges, edge_count, sizeof(Edge), compare_edges);

    // 각 정점에 대해 부모 노드를 자기 자신으로 설정
    for (int i = 0; i < g->n; i++) {
        parent[i] = i;
    }

    printf("Minimum Spanning Tree:\n");
    int mst_weight = 0;
    for (int i = 0; i < edge_count; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        // 두 정점이 같은 집합에 속하지 않으면 간선 추가
        if (find_set(u) != find_set(v)) {
            printf("Edge (%d, %d) with weight %d\n", u, v, edges[i].weight);
            mst_weight += edges[i].weight;
            union_sets(u, v); // 집합을 합침
        }
    }
    printf("Total weight of MST: %d\n", mst_weight);
}
```

그래프 G10 실행 결과

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-11.png?raw=true)

```c
그래프 G10의 Minimum Spanning Tree:
Edge (4, 6) with weight 2
Edge (0, 1) with weight 3
Edge (4, 5) with weight 4
Edge (1, 3) with weight 5
Edge (2, 5) with weight 8
Edge (3, 4) with weight 9
Total weight of MST: 31
```

### 프림 알고리즘 (Prim Algorithm)
간선을 정렬하지 않고 하나의 정점에서 시작하여 트리를 확장해 나가는 방법
- Greedy Algorithm

- **MST 구하는 과정**
    1. 그래프 G에서 시작 정점을 선택
    2. 현재 정점에 부속된 모든 간선 중에서 가중치가 가장 낮은 간선을 최소 비용 신장 트리(MST) 집합에 삽입하여 트리를 확장
    3. 그래프 G에 간선이 n-1개가 아니라면 2를 반복 수행
    4. 그래프 G의 간선이 n-1개 라면 알고리즘 종료

알고리즘

```c
void prim(graphType* g) {
    int selected[MAX_VERTEX] = { 0 };
    int totalWeight = 0;
    int edgesInTree = 0;

    // B ← {0}
    // 첫 번째 정점 선택
    selected[0] = 1; 

    printf("Minimum Spanning Tree Edges:\n");

    while (edgesInTree < g->n - 1) { // T의 간선 개수가 N-1이 될 때까지 반복
        int minWeight = INT_MAX;
        int u = -1, v = -1;

        // Find (u, v) with minimum weight where u ∈ B and v ∈ N-B
        // 선택된 정점에서 선택되지 않은 정점으로 가는 최소 가중치 간선 찾기
        for (int i = 0; i < g->n; i++) {
            if (selected[i]) {
                for (int j = 0; j < g->n; j++) {
                    if (!selected[j] && g->adjMatrix[i][j] > 0 && g->adjMatrix[i][j] < minWeight) {
                        minWeight = g->adjMatrix[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add (u, v) to T and v to B
        // 최소 가중치 간선 (u, v) 추가
        if (u != -1 && v != -1) {
            printf("Edge (%d, %d) with weight %d\n", u, v, minWeight);
            totalWeight += minWeight;
            selected[v] = 1; // 정점 v 선택
            edgesInTree++;
        }
    }

    printf("Total weight of Minimum Spanning Tree: %d\n", totalWeight);
}
```

그래프 G10 실행 결과

![](https://github.com/seokmin-yoon/CS/blob/main/DataStructure/images/6-12.png?raw=true)

```c
그래프 G10의 Minimum Spanning Tree Edges:
Edge (0, 1) with weight 3
Edge (1, 3) with weight 5
Edge (3, 4) with weight 9
Edge (4, 6) with weight 2
Edge (4, 5) with weight 4
Edge (5, 2) with weight 8
Total weight of Minimum Spanning Tree: 31
```

## 6.5. 최단 경로
신장 트리가 아닌 가중치 그래프 (네트워크)에서 정점 u와 v를 연결하는 경로 중 가중치의 합이 최소인 경로
- **가중치 인접 행렬**: 최단 경로를 구하려는 가중치 그래프의 가중치를 저장한 2차원 배열
    - 간선이 없으면 ∞(무한대) 값을 저장

### 다익스트라 알고리즘 (Dijkstra Algorithm)
- 하나의 시작 정점에서 다른 정점까지의 최단 경로를 구함
- 무방향 그래프나 방향 그래프에 모두 적용 가능
- 단일점에서의 최단 경로 알고리즘 중 가장 많이 사용됨
- Dynamic Programming Algorithm

- **최단 경로 구하는 과정**
    1. **경로 길이를 저장할 배열 distance 준비**:
        - 시작 정점으로부터 각 정점에 이르는 경로의 길이를 저장하기 위한 배열 distance를 무한대로 초기화
    2. **시작 정점 초기화**:
        - 시작 정점의 distance를 0으로 초기화
        - 최단 경로 정점 집합 S에 해당 정점을 추가
    3. **최단 거리 수정**:
        - 집합 S에 속하지 않은 정점 중에서 distance가 최소인 정점 u를 찾음
        - 정점 u를 집합 S에 추가하고, 집합 S에 포함되지 않은 정점 w의 distance 값을 다음 식에 따라 업데이트
           - weight: 가중치 인접 행렬
            
            $$
            distance[w]=min(distance[w], distance[u]+weight[u][w])
            $$
 
            이 공식은 현재 경로 보다 정점 u를 거쳐서 w으로 가는 경로가 더 짧다면, w의 distance 값을 갱신하는 방식임
          
        4. 집합 S에 모든 정점이 추가될 때까지 3번 과정을 반복

알고리즘

```c
//1. distance 배열을 무한대로 초기화.
//2. 시작 정점의 distance 값을 0으로 설정하고 집합 S에 추가.
//3. 최단 경로를 갱신하며 집합 S에 정점을 추가.
//4. 모든 정점이 집합 S에 포함될 때까지 이 과정을 반복.
```

그래프 G11 실행 결과

```c
```

### 플로이드-워셜 알고리즘 (Floyd-Warshall Algorithm)
- 모든 정점 사이의 최단 경로를 구함
- Dynamic Programming Algorithm

- **최단 경로 구는 과정**

알고리즘

```c
```

그래프 G11 실행 결과

```c
```

### 벨만-포드 알고리즘 (Bellman-Ford Algorithm)
- Dynamic Programming Algorithm

- **최단 경로 구는 과정**

알고리즘

```c
```

그래프 G11 실행 결과

```c
```

# Reference
C로 배우는 쉬운 자료구조 (개정 3판), 이지영, 한빛아카데미
