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

// ���� �����ϴ� ���� (�ִ� �� ����)
void insertHeap(heapType* h, int item) {
	int i;

	// 1. �� ũ�� ����
	h->heap_size++;

	// 2. ������ ��ġ�� ������ ����
	i = h->heap_size;

	// 3. �θ� ���� ���Ͽ� �������� �� ũ�� �ڸ� ��ȯ (�ִ� �� ����)
	while (i != 1 && item > h->heap[i / 2]) {
		h->heap[i] = h->heap[i / 2];  // �θ� ��� ��������
		i /= 2;  // �θ� ���� �̵�
	}

	// 4. ������ ����
	h->heap[i] = item;
}

// ���� ��Ʈ�� �����ϴ� ���� (���� ū ���� ������ ���)
int deleteHeap(heapType* h) {
	int parent, child;
	int item, temp;

	// 1. ��Ʈ ��带 �����Ϸ��� ���� ��Ʈ ���� �����ϰ�, ������ ��带 ��Ʈ�� �̵�
	item = h->heap[1];  // ������ ��Ʈ ���� item�� ����
	temp = h->heap[h->heap_size];  // ������ ��� ���� temp�� ����

	// 2. �� ũ�⸦ �ϳ� ����
	h->heap_size = h->heap_size - 1;

	// 3. ��Ʈ�� ������ ���(temp)�� ������ ��, �� �Ӽ��� �����ϵ��� ������
	parent = 1;  // �θ� ���� ��Ʈ(�ε��� 1)���� ����
	child = 2;   // �ڽ� ���� ���� �ڽĺ��� ���� (�ε��� 2)

	// 4. �ڽ��� �����ϴ� ���� �ݺ��Ͽ� ���� �Ӽ�(�ִ� ��)�� ����
	while (child <= h->heap_size) {
		// �ڽ��� �� �̻��� ���, �� ū �ڽ��� ����
		if ((child < h->heap_size) && (h->heap[child] < h->heap[child + 1])) {
			child++;  // ������ �ڽ��� �� ũ�ٸ� ������ �ڽ����� �̵�
		}

		// 5. temp ���� �ڽ� ��庸�� ũ�� ���� �Ӽ��� �����ǹǷ� ����
		if (temp >= h->heap[child]) {
			break;
		}
		else {
			// 6. �ڽ� ���� �θ� ����� ���� �ٲٰ�, �θ�� �ڽ����� �̵�
			h->heap[parent] = h->heap[child];
			parent = child;
			child = child * 2;  // ���� �ڽ����� �̵�
		}
	}

	// 7. ���������� temp ���� ������ ��ġ�� ����
	h->heap[parent] = temp;

	// 8. ������ ��Ʈ ���� ��ȯ
	return item;
}

// ���� ������ ���
void printHeap(heapType* h) {
	printf("Heap: ");
	for (int i = 1; i <= h->heap_size; i++)
		printf("[%d] ", h->heap[i]);
	printf("\n");
}

int main() {
	int i, n, item;
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