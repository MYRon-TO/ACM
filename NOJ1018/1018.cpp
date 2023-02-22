#include<stdio.h>

#define LEFT true
#define RIGHT false

typedef struct Node {
	char data;
	Node* L=NULL;
	Node* R=NULL;
}Node;

typedef struct Tree {
	Node* root;
}Tree;

typedef struct Stack {
	Node* top;
}Stack;

void BuildTree(Tree* tree) {
	tree = new Tree;
	Node* parent=new Node;
	tree->root = parent;

	parent->data = 'D';
	AddNode(parent,'E', LEFT);
	AddNode(parent->L,'H',LEFT);
	AddNode(parent->L, 'F', RIGHT);
	parent = parent->L;

	AddNode(parent, 'A', RIGHT);


}

void AddNode(Node* parent,char data,bool L) {
	Node* node = new Node;
	node->data = data;

	if (L) {
		parent->L = node;
	}
	else {
		parent->R = node;
	}

}


int main() {

	return 0;
}