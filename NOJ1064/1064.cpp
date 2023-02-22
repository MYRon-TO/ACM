#include<iostream>

typedef struct List {
	long long a[10086];
	int num;

}List;

void Swap(long long* a,int i,int j) {
	long long temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

int Partition(List* list, int low, int high) {
	int i = low, j = high + 1; 
	int pivot = list->a[low];
	while (i < j){
		do i++; while (i <= high && list->a[i] < pivot);
		do j--; while (list->a[j]>pivot&&j>=low);
		if (i < j) Swap(list->a, i, j);
	} 
	Swap(list->a, low, j);
	return j;
}

void QuickSort(List* list, int low, int high) {
	int k;
	if (low < high) {
		k = Partition(list, low, high);
		QuickSort(list, low, k - 1);
		QuickSort(list, k + 1, high);
	}
}

void QuickSort(List* list) {
	QuickSort(list,0,list->num-1);
}

int main() {
	List* list=new List;
	bool first=true;
	std::cin >> list->num;
	for (int i = 0; i < list->num; i++) {
		std::cin >> list->a[i];
	}
	QuickSort(list);
	for (int i = 0; i < list->num; i++) {
		if(!first){
			std::cout << " ";
		}
		first = false;
		std::cout<< list->a[i];
	}
	return 0;
}