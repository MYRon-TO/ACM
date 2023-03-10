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
	BTNode* left;
	BTNode* right;
	int height = 1;
}BTNode;

typedef struct BinaryTreeRoot {
	BTNode* root;
	int num = 0;
}BTRoot;

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
		PQueue::ShowTop();
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
		PStack::ShowTop();

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

//============================
//========Class Tree==========
//============================

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();//===============================NULL

	//????????????????
	void CreatTree_recursion_VLR();
	//????????????????
	void CreatTree_VLR();//========================NULL


	//????????????
	void Re_VLR();

	//????????????
	void Re_LVR();

	//????????????
	void Re_LRV();


	//????????????
	void VLR();//==================================NULL
	//????????????
	void LVR();//==================================NULL

	//????????
	void Layer();



protected:
	BTRoot tree;
	BTNode* CreatTree_recursion_VLR(BTNode* node);

	void recursion_VLR(BTNode* node);
	void recursion_LVR(BTNode* node);
	void recursion_LRV(BTNode* node);

private:
};

//====================================================================================================================Funcation of Tree

BinaryTree::BinaryTree()
{

}

BinaryTree::~BinaryTree()
{
	//BTNode p;

}


void BinaryTree::CreatTree_recursion_VLR()
{
	tree.root = CreatTree_recursion_VLR(tree.root);

}


BTNode* BinaryTree::CreatTree_recursion_VLR(BTNode* node)
{
	//#????NULL
	AnyType c;
	std::cin >> c;
	if (c == TypeNull) {
		node = NULL;

	}
	else {
		node = new BTNode;
		node->data = c;
		node->left = this->CreatTree_recursion_VLR(node->left);
		node->right = this->CreatTree_recursion_VLR(node->right);
		if (node->left) {
			if (node->right) {
				node->height = (node->left->height > node->right->height ? node->left->height : node->right->height) + 1;
			}
			else {
				node->height = node->left->height + 1;
			}
		}
		else {
			if (node->right) {
				node->height = node->right->height + 1;
			}
		}

		tree.num++;

	}
	return node;
}

void BinaryTree::Re_VLR() {

	this->recursion_VLR(tree.root);
}

void BinaryTree::Re_LVR()
{
	this->recursion_LVR(tree.root);
}

void BinaryTree::Re_LRV()
{
	this->recursion_LRV(tree.root);
}

void BinaryTree::recursion_VLR(BTNode* node) {
	if (!node) {
		return;
	}

	//Do something!

	std::cout << node->data;
	this->recursion_VLR(node->left);
	this->recursion_VLR(node->right);

}

void BinaryTree::recursion_LVR(BTNode* node)
{
	if (!node) {
		return;
	}

	this->recursion_LVR(node->left);

	//Do something!
	std::cout << node->data;

	this->recursion_LVR(node->right);
}

void BinaryTree::recursion_LRV(BTNode* node)
{
	if (!node) {
		return;
	}

	this->recursion_LRV(node->left);
	this->recursion_LRV(node->right);

	//Do something!
	std::cout << node->data;
}


void BinaryTree::Layer()
{
	if (!tree.root) {
		return;
	}

	PQueue queue;
	BTNode* p = tree.root;
	queue.Push(p);

	while (!queue.Is_Empty()) {
		p = queue.UseTop();
		std::cout << " ";
		queue.OutQueue();

		if (p->left)
			queue.Push(p->left);
		if (p->right)
			queue.Push(p->right);
	}

}





//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================

int main() {
	BinaryTree BTtree;
	BTtree.CreatTree_recursion_VLR();
	std::cout << "LevelOrder:";
	BTtree.Layer();
	return 0;
}