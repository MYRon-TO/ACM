#include <iostream>


//==================================
//=========Define & Struct==========
//==================================

//===============================================Define
#define AnyType char
#define TypeNull '#'

//===============================================Struct for Tree

typedef struct BTNode {
	AnyType data;
	BTNode* left=NULL;
	BTNode* right=NULL;
	int height = 1;
}BTNode;

typedef struct BinaryTreeRoot {
	BTNode* root;
	int num = 0;
}BTTree;

//===============================================Struct for List
#define ListType BTNode*

typedef struct Node {
	ListType list_data;
	Node* link;
}Node;

typedef struct List {
	Node* head;
	Node* tail;
	int length;
}List;

#define ListData list_data->data


//============================
//========Class PList=========
//============================


class PList
{
public:

	PList();
	~PList();
	//void AddNode();
	void ShowList();
	bool Is_Empty();

protected:

	List* list = new List;

private:

};

//==========================================================================================================Funcation of PList

PList::PList()
{
	list->head = new Node;
	list->tail = list->head;
	list->length = 0;

}
/*
void PList::AddNode()
{
	Node* p = new Node;
	std::cin >> p->data;
	list->tail->link = p;
	list->tail = p;
	list->length++;

}
*/
PList::~PList()
{
	Node* p = list->head;
	for (; list->length > 0; list->length--) {
		list->head = list->head->link;
		delete p;
		p = list->head;
	}

}

void PList::ShowList()
{
	Node* p = list->head->link;
	for (int i = 0; i < list->length; i++) {
		std::cout << p->ListData;
		p = p->link;
	}
}

bool PList::Is_Empty()
{
	if (list->length) {
		return false;
	}
	else {
		return true;
	}
}

//===========================
//=======Class PQueue========
//===========================

class PQueue :
	public PList
{
public:

	void OutQueue();
	void ShowTop();
	void Push(ListType data);
	ListType UseTop();

protected:
private:
};

//=================================================================================================================Funcation of PQueue

void PQueue::OutQueue()
{
	if (list->length > 0) {
		//Do something before delete
		//PQueue::ShowTop();
		//Now it will be delete

		list->length--;
		Node* p;
		p = list->head;
		list->head = list->head->link;
		list->head->list_data = NULL;
		delete p;
		p = NULL;
	}
	else {
		//empty Queue
	}
}

void PQueue::ShowTop()
{
	std::cout << list->head->link->ListData;
}

ListType PQueue::UseTop() {
	return list->head->link->list_data;
}

void PQueue::Push(ListType data)
{
	Node* p = new Node;
	p->list_data = data;
	list->tail->link = p;
	list->tail = p;
	list->length++;
}

//============================
//=======Class PStack=========
//============================

class PStack :
	public PList
{
public:
	void OutStack();
	void ShowTop();
	void Push(ListType data);
	ListType UseTop();
protected:
private:

};

//=============================================================================================================Funcation of PQueue

void PStack::OutStack()
{
	if (list->length > 0) {
		//Do something before delete
		//PStack::ShowTop();

		//Now it will be delete
		list->length--;
		Node* p = list->head;
		for (int i = 0; i < list->length; i++)
			p = p->link;
		list->tail = p;
		p = p->link;
		p->list_data = NULL;
		delete p;
		list->tail->link = NULL;
		p = NULL;
	}
	else {
		//empty Stack
	}

}

void PStack::ShowTop() {
	//U can print the top of stack here
	std::cout << list->tail->ListData;
}

ListType PStack::UseTop() {
	return list->tail->list_data;
}

void PStack::Push(ListType data) {

	Node* p = new Node;
	p->list_data = data;
	list->tail->link = p;
	list->tail = p;
	list->length++;

}

//=======================================================================
//===========================   BT  tree   ==============================
//=======================================================================

//先序建树
BTTree* CreatTree() {
	BTTree* tree = new BTTree;
	BTNode* p = new BTNode;
	BTNode* q;
	tree->root = p;
	PStack stack;

	AnyType c;
	std::cin.get(c);

	if (c == TypeNull) {
		do {
			std::cin.get(c);
		} while (c !=10);
		return NULL;
	}

	p->data = c;
	stack.Push(p);

	while (c!=10) {

		do {
			std::cin.get(c);
		} while (c == 32);
		
		if (c == TypeNull) {

			do {
				p = stack.UseTop();
				stack.OutStack();

				do {
					std::cin.get(c);
					
				} while (c == 32);

			} while (c==TypeNull&&c!=10);

			if (c == 10) {
				break;
			}

			p->right = new BTNode;
			p->right->data = c;
			p = p->right;
			stack.Push(p);

		}
		else {

			p->left = new BTNode;
			p->left->data = c;
			p = p->left;
			stack.Push(p);
		}
	}

	return tree;
}
//层次遍历
void LevelOrder(BTTree* tree)
{
	
	if (!tree) {
		//std::cout << "returned";
		return;
	}
	
	PQueue queue;
	BTNode* p = tree->root;
	queue.Push(p);

	while (!queue.Is_Empty()) {
		p = queue.UseTop();
		std::cout << " " << p->data;
		queue.OutQueue();

		if (p->left)
			queue.Push(p->left);
		if (p->right)
			queue.Push(p->right);
	}

}
//先序遍历
void PreOrder(BTTree* tree) {

	if (!tree) {
		return;
	}

	BTNode* p = tree->root;
	PStack stack;
	
	do {
		while (p) {

			//do something here
			std::cout <<" " << p->data;

			stack.Push(p);
			p = p->left;
			
		}
		
		p = stack.UseTop();
		if (stack.Is_Empty()) {
			break;
		}

		stack.OutStack();
		p = p->right;
	} while (1);
}
//合并树
BTTree* CombineTree(BTTree* tree1,BTTree* tree2) {

	BTTree* rootTree = new BTTree;
	AnyType c;

	do {
		std::cin.get(c);
	} while (c == 32);

	if (c == 10 || c == TypeNull) {
		return NULL;
	}

	if (!tree1&&!tree2) {
		rootTree->root = new BTNode;
		rootTree->root->data = c;
		return rootTree;
	}

	rootTree->root = new BTNode;
	rootTree->root->data = c;

	if (tree1) {
		rootTree->root->left = tree1->root;
		tree1->root = NULL;
		delete tree1;
	}
		
	if (tree2) {
		rootTree->root->right = tree2->root;
		tree2->root = NULL;
		delete tree2;
	}

	return rootTree;

}
//交换子树
void Exchange(BTTree* tree) {

	if (!tree) {
		return;
	}

	PQueue queue;
	BTNode *p;
	BTNode* temp;

	p = tree->root;
	queue.Push(p);

	do {

		p = queue.UseTop();
		queue.OutQueue();

		temp = p->left;
		p->left = p->right;
		p->right = temp;
		temp = NULL;

		if(p->left)
			queue.Push(p->left);
		if(p->right)
			queue.Push(p->right);

	} while (!queue.Is_Empty());
}

//=======================================================================
//===========================     MAIN     ==============================
//=======================================================================

int main() {
	BTTree* tree1;
	BTTree* tree2;
	BTTree* tree3;
	tree1 = CreatTree();
	tree2 = CreatTree();

	tree3 = CombineTree(tree1,tree2);

	std::cout << "PreOrder:";
	PreOrder(tree3);
	std::cout << std::endl<<"LevelOrder:";
	LevelOrder(tree3);
	std::cout << std::endl ;

	Exchange(tree3);

	std::cout << "PreOrder:";
	PreOrder(tree3);
	std::cout << std::endl << "LevelOrder:";
	LevelOrder(tree3);

	return 0;
}