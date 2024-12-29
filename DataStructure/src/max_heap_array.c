#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

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

// 힙의 내용을 출력
void printHeap(heapType* h) {
	printf("Heap: ");
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

int main() {
	int n, item;
	heapType* h = createHeap();
	insertHeap(h, 20);
	insertHeap(h, 15);
	insertHeap(h, 19);
	insertHeap(h, 8);
	insertHeap(h, 13);
	insertHeap(h, 10);

	printHeap(h);

	n = h->heap_size;
	for (int i = 1; i <= n; i++) {
		item = deleteHeap(h);
		printf("\n delete: [%d] ", item);
	}

}
