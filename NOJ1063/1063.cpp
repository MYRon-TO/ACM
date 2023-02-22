#include<iostream>

typedef struct List {
	long long a[800];
	int num;
}List;

void Creat(List* list) {
	std::cin >> list->num;
	for (int i = 0; i < list->num; i++) {
		std::cin >> list->a[i];
	}

	std::cout << "Source:\n(" << list->a[0];
	for (int i = 1; i < list->num; i++) {
		std::cout << " " << list->a[i];
	}
	std::cout << ")\nBubble Sort:\n";
}

void Sort(List* list) {
	int n =-1;
	int temp;
	bool first = true;
	bool isSwap = false;
	bool end = false;

	for (int j = list->num - 1; j > 0; j--) {
		isSwap = false;
		//n = -1;

		for (int i = 0; i <j; i++) {

			if (list->a[i] > list->a[i + 1]) {
				temp = list->a[i];
				list->a[i] = list->a[i + 1];
				list->a[i + 1] = temp;
				n = i;
				isSwap = true;
			}


		}

		if (isSwap) {
			for (int i = 0; i < list->num; i++) {
				if (first) {
					std::cout << "(" << list->a[i];
					first = false;
				}
				else {
					std::cout << " " << list->a[i];
				}
				if (i == n) {
					std::cout << ")";
					
				}

			}
			std::cout << "\n";
		}
		//std::cout << "\nn=" << n;
		if (n == 1) {
			end = true;
		}
		first = true;

	}
	if (!end) {
		std::cout << "(" << list->a[0]<<")";
		for (int i = 1; i < list->num; i++)
			std::cout<< " " <<list->a[i];
		std::cout << "\n";
	}

	std::cout << "Result\n(";
	for (int i = 0; i < list->num; i++) {
		if (first) {
			std::cout << list->a[i];
			first = false;
		}
		else {
			std::cout << " " << list->a[i];
		}
	}

	std::cout << ")";
}

int main() {
	List list;
	Creat(&list);
	Sort(&list);
	return 0;
}