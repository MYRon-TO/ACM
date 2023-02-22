#include<iostream>

typedef struct Node {
	long long data = -1;
	Node* next=NULL;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
	int num=0;
}List;



void Creat(List& list) {
	int n;
	bool first = true;
	list.head = new Node;
	Node* p=list.head;
	
	std::cin >> list.num;
	for (int i = 0; i < list.num; i++) {
		std::cin >> n;
		p->next = new Node;
		p->next->data = n;
		p=p->next;

	}

	std::cout << "Source:\n";
	p = list.head;
	for (int i = 0; i < list.num; i++) {
		p = p->next;

		if (first) {
			first = false;
			std::cout << "(" << p->data << ")";
		}
		else {
			std::cout << " " << p->data;
		}

	}


}

void InsertSort(List& list) {
	int n;
	bool first = true;
	Node* p = list.head->next;
	Node* q=list.head;
	Node* temp=list.head;

	for (int i = 0; i < list.num-1; i++) {
		p = p->next;
		
		while (q->next != p) {
			
			if (p->data < q->next->data) {
				while (temp->next != p) { temp = temp->next; }
				temp->next = p->next;
				p->next = q->next;
				q->next = p;
				p = temp;
				break;
			}
			q = q->next;
		}
		q = list.head;

		//print
		
		
		for (int k = 0; k < (list.num); k++) {
			if (first) {
				first = false;
				std::cout << "(";
				std::cout << q->next->data;
			}
			else {
				std::cout << " " << q->next->data;
				if (q->next == p) {
					std::cout << ")";
				}
			}
				q = q->next;
		}
		std::cout << std::endl;
		q = list.head;
		first = true;
	}
	std::cout <<"Result:\n"<< "(";
	for (int k = 0; k < (list.num); k++) {
		std::cout << q->next->data;
		if (q->next == p) {
			std::cout << ")";
		}
		std::cout << " ";
		q = q->next;
	}
	std::cout << std::endl;

	q = list.head;

}


int main() {

	List list;
	
	Creat(list);
	std::cout << "\nInsert Sort:\n";
	InsertSort(list);

	return 0;
}