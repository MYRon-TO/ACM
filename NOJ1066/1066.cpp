#include<iostream>

void AdjustDown(int heap[], int current, int border);

void AdjustDown(int heap[], int current, int border) {
	int p = current;
	int minChild;
	int temp;
	while (2 * p + 1 <= border) {
		if ((2 * p + 2 <= border) && (heap[2 * p + 1] > heap[2 * p + 2]))
			minChild = 2 * p + 2;
		else
			minChild = 2 * p + 1;
		if (heap[p] <= heap[minChild])
			break;
		else {
			temp = heap[p];
			heap[p] = heap[minChild];
			heap[minChild] = temp;
			p = minChild;
		}
	}
}

void CreateHeap(int heap[],int n) {
	int i;
	for (i = (n - 2) / 2; i > -1; i--)
		AdjustDown(heap, i, n - 1);
}

void HeapSort(int heap[],int n) {
	int i, temp;
	for (i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(heap, i, n-1);
	for (i = n - 1; i > 0; i--) {
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		AdjustDown(heap, 0, i-1);
	}

}

int main() {
	int n;
	std::cin >> n;
	int* heap = new int[n];
	for (int i = 0; i < n; i++)
		std::cin >> heap[i];
	//CreateHeap(heap,n);
	HeapSort(heap, n);
	for (int i = n-1; i >=0; i--)
		std::cout<< heap[i]<<" ";



	return 0;
}