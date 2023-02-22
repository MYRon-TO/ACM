#include <iostream>

#define MAXSIZE 11451419

typedef struct List {
	int a[MAXSIZE];
	int n;
}List;

void Merge(List* list,int* temp,int low,int n1,int n2) {
	int i = low, j = low + n1;
	while (i <= low + n1 - 1 && j <= low + n1 + n2 - 1) {
		if (list->a[i] <= list->a[j])
			*temp++ = list->a[i++];
		else
			*temp++ = list->a[j++];
	}
	while (i <= low + n1 - 1)
		*temp++ = list->a[i++];
	while (j <= low + n1 + n2 - 1)
		*temp++ = list->a[j++];
}

void MergeSort(List* list) {
	int temp[MAXSIZE];
	int low, n1, n2, i, size = 1;
	while (size < list->n) {
		low = 0;
		while (low + size < list->n) {
			n1 = size;
			if(low + size * 2<list->n) {
				n2 = size;
			}
			else {
				n2 = list->n - low - size;
			}
			Merge(list, temp + low, low, n1, n2);
			low += n1 + n2;
		}
		for (i = 0; i < low; i++) {
			list->a[i] = temp[i];
		}
		size *= 2;
	}
}

int main() {
	List list;
	std::cin >> list.n;
	for (int i = 0; i < list.n; i++)
		std::cin >> list.a[i];
	MergeSort(&list);
	for (int i = 0; i < list.n; i++)
		std::cout << list.a[i]<<" ";

	return 0;
}