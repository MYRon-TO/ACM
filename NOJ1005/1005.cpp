#include<iostream>

//const char IS_First = 1 << 0;
const char IS_Positive = 1 << 1;
const char IS_Constant = 1 << 2;
const char IS_Zero = 1 << 3;
const char IS_One = 1 << 4;
const char IS_X = 1 << 5;

typedef struct Node {
	int C;
	int Index;
	Node* next = NULL;
	char Mask;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
	//int FirstIndex = -1;
	int num = 0;
}List;

void CheckMask(Node* new_node, List* list) {
	/*
	if (list->FirstIndex < new_node->Index && new_node->C != 0) {
		new_node->Mask = new_node->Mask | IS_First;
		list->FirstIndex = new_node->Index;
	}
	*/
	if (new_node->C == 0) {
		new_node->Mask = new_node->Mask | IS_Zero;
	}
	else if (new_node->C > 0) {
		new_node->Mask = new_node->Mask | IS_Positive;
	}

	if (new_node->C == 1 || new_node->C == -1) {
		new_node->Mask = new_node->Mask | IS_One;
	}

	if (new_node->Index == 0) {
		new_node->Mask = new_node->Mask | IS_Constant;
	}
	else if (new_node->Index == 1) {
		new_node->Mask = new_node->Mask | IS_X;
	}
}

Node* CheckNode(List* list, int Index) {
	Node* p;
	p = list->head->next;

	while (p) {

		if (p->Index == Index) {
			return p;
		}
		p = p->next;
	}
	return NULL;
}

bool AddNode(List* list) {

	Node* check_index;
	Node* new_node = new Node;
	std::cin >> new_node->C >> new_node->Index;

	if (new_node->C == 0 && new_node->Index == -1) {
		delete new_node;
		return false;
	}

	check_index = CheckNode(list, new_node->Index);
	if (check_index) {
		check_index->C += new_node->C;
		delete new_node;
		CheckMask(check_index, list);
	}
	else {
		list->num++;

		new_node->next = NULL;
		list->tail->next = new_node;
		list->tail = new_node;

		new_node->Mask = 0b0;
		CheckMask(new_node, list);
	}

	//std::cout << new_node->C << new_node->Index;
	return true;
}

void AddNode(List* list, int C, int Index) {

	Node* new_node = new Node;
	new_node->C = C;
	new_node->Index = Index;

	new_node->Mask = 0b0;
	new_node->next = NULL;

	list->tail->next = new_node;
	list->tail = new_node;

	list->num++;

	CheckMask(new_node, list);
}


void AddNode(List* list1, List* list2, List* list3) {
	Node* p;
	Node* q;
	Node* k;
	Node flag = { 0,-1,NULL,0b0 };
	p = list1->head->next;
	q = list2->head->next;
	k = list3->head->next;

	if (list1->num == 0)
		p = &flag;

	if (list2->num == 0)
		q = &flag;


	while ((p != &flag || q != &flag)) {

		if (p->Index == q->Index) {
			AddNode(list3, p->C + q->C, p->Index);
			p = p->next;
			q = q->next;
		}
		else if (p->Index > q->Index) {
			AddNode(list3, p->C, p->Index);
			p = p->next;
		}
		else {
			AddNode(list3, q->C, q->Index);
			q = q->next;
		}

		list3->num++;

		if (p == NULL)
			p = &flag;
		if (q == NULL)
			q = &flag;
	}
}


void ShowNode(List* list) {
	Node* p;
	p = list->head;
	bool flag = true;
	bool first = true;

	if (list->num != 0) {
		for (; p != NULL; p = p->next) {

			if (p->Mask & IS_Zero) {
				continue;
			}

			//=====================================
			if (first) {
				if (p->Mask & IS_Positive) {

				}
				else {
					std::cout << "-";
				}
				first = false;
			}
			else {
				//正负号
				if (p->Mask & IS_Positive) {
					std::cout << "+";
				}
				else {
					std::cout << "-";
				}
			}

			if (p->Mask & IS_Constant) {
				//为常数
				if (p->Mask & IS_One) {
					//为1
					std::cout << 1;
				}
				else {
					//不为1
					std::cout << abs(p->C);
				}
			}
			else {
				//不为常数
				if (p->Mask & IS_One) {
					//为1
					//std::cout << 1;
				}
				else {
					//不为1
					std::cout << abs(p->C);
				}

				if (p->Mask & IS_X) {
					std::cout << "X";
				}
				else {
					std::cout << "X^" << p->Index;
				}
			}
			flag = false;
			//======================================

		}
		if (flag) {
			std::cout << 0;
		}
	}
	else {
		std::cout << 0;
	}
}

int main() {

	List* plist_1 = new List;
	plist_1->head = new Node;
	plist_1->tail = plist_1->head;
	//plist_1->FirstIndex = 0;

	List* plist_2 = new List;
	plist_2->head = new Node;
	plist_2->tail = plist_2->head;
	//plist_2->FirstIndex = 0;

	do {
	} while (AddNode(plist_1));

	do {
	} while (AddNode(plist_2));


	List* plist_3 = new List;
	plist_3->head = new Node;
	//plist_3->head = NULL;
	plist_3->tail = plist_3->head;
	//plist_3->FirstIndex = 0;

	AddNode(plist_1, plist_2, plist_3);

	ShowNode(plist_1);
	std::cout << std::endl;
	ShowNode(plist_2);
	std::cout << std::endl;
	ShowNode(plist_3);
	std::cout << std::endl;
	return 0;
}