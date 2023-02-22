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
	int weight;
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
	void AddNode(BTNode* node);

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

void PList::AddNode(BTNode* node) {
	Node* p = new Node;
	p->list_data = node;

	if (this->list->length == 0) {
		list->tail->link = p;
		list->tail = p;
		list->length++;
		return;
	}

	Node* q=this->list->head;
	Node* temp=q;
	for (; q != NULL && p->list_data->weight < q->link->list_data->weight && q->link != this->list->tail; q = q->link)
		temp = q;
	temp->link = p;
	p->link = q;

	list->length++;
}

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

	//递归先序遍历建树
	void CreatTree_recursion_VLR();
	//迭代先序遍历建树
	void CreatTree_VLR();//========================NULL

	//递归先序遍历
	void Re_VLR();

	//递归中序遍历
	void Re_LVR();

	//递归后序遍历
	void Re_LRV();


	//迭代先序遍历
	void VLR();//==================================NULL
	//迭代中序遍历
	void LVR();//==================================NULL

	//层次遍历
	void Layer();


	BTRoot tree;
protected:
	
	BTNode* CreatTree_recursion_VLR(BTNode* node);

	void recursion_VLR(BTNode* node);
	void recursion_LVR(BTNode* node);
	void recursion_LRV(BTNode* node);

private:
};

//====================================================================================================================Funcation of Tree

BinaryTree::BinaryTree()
{
	this->tree.root = new BTNode;
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
	//#代表NULL
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
		queue.OutQueue();

		if (p->left)
			queue.Push(p->left);
		if (p->right)
			queue.Push(p->right);
	}

}

typedef struct C_Node {
	BinaryTree* list_data;
	C_Node* link;
}C_Node;

typedef struct C_List {
	C_Node* head;
	C_Node* tail;
	int length;
}C_List;
//============================
//========Class C_PList=======
//============================


class Combine_PList
{
public:

	Combine_PList();
	//void AddNode();
	bool Is_Empty();
	void AddNode(BinaryTree* node);

	BinaryTree* Out()
	{
		if (list->length > 0) {

			list->length--;
			C_Node* p;
			BinaryTree* q = list->head->list_data;
			p = list->head;
			list->head = list->head->link;
			list->head->list_data = NULL;
			delete p;
			p = NULL;
			return q;
		}
		else {
			//empty Queue
			return NULL;
		}
	}

	void InsertSort() {
		int n;
		bool first = true;
		C_Node* p = list->head->link;
		C_Node* q = list->head;
		C_Node* temp = list->head;

		for (int i = 0; i < list->length - 1; i++) {
			p = p->link;

			while (q->link != p) {

				if (p->list_data->tree.root->weight < q->link->list_data->tree.root->weight) {
					while (temp->link != p)  
						temp = temp->link; 
					temp->link = p->link;
					p->link = q->link;
					q->link = p;
					p = temp;
					break;
				}
				q = q->link;
			}
			q = list->head;

		}
	}

protected:

	C_List* list = new C_List;

private:

};

//==========================================================================================================Funcation of PList

Combine_PList::Combine_PList()
{
	list->head = new C_Node;
	list->tail = list->head;
	list->length = 0;

}


void Combine_PList::AddNode(BinaryTree* node) {
	C_Node* p = new C_Node;
	p->list_data = node;

		list->tail->link = p;
		list->tail = p;
		list->length++;

}

bool Combine_PList::Is_Empty()
{
	if (list->length) {
		return false;
	}
	else {
		return true;
	}
}


//树的合并
BinaryTree* Combine(BinaryTree* tree1, BinaryTree* tree2) {
	if (!tree1||!tree2) {
		if (!tree1)
			return tree2;
		else
			return tree1;
	}
	BinaryTree *tree3=new BinaryTree;
	tree3->tree.root->weight = tree1->tree.root->weight + tree2->tree.root->weight;
	tree3->tree.root->data = '#';
	tree3->tree.root->left = tree1->tree.root;
	tree3->tree.root->right = tree2->tree.root;
	tree3->tree.root->height = tree1->tree.root->height > tree2->tree.root->height ? tree1->tree.root->height + 1 : tree2->tree.root->height + 1;
	tree1->tree.root = NULL;
	tree2->tree.root = NULL;
	return tree3;
}

BinaryTree* CreatHFTree() {
	Combine_PList list;
	BinaryTree *p;
	char data[10] = { 'A','C','I','M','N','P','T','U' };
	for (int i = 0; i < 8; i++) {
		p = new BinaryTree;
		p->tree.root->data = data[i];
		std::cin >> p->tree.root->weight;
		list.AddNode(p);
	}
	list.InsertSort();
	while (!list.Is_Empty()) {
		p = Combine(list.Out(), list.Out());
		list.AddNode(p);
		list.InsertSort();
	}

	return p;
}


//=======================================================================================================================================
//=======================================================================================================================================
//=======================================================================================================================================

int main() {
	BinaryTree* HFTree;
	HFTree = CreatHFTree();
	HFTree->Layer();
	return 0;
}