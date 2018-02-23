#pragma once
#include <iostream>
#include "NodeInterface.h"

class Node : public NodeInterface
{

public:

	Node(int value, Node* left = NULL, Node* right = NULL, int tallness = 0) {
		data = value;
		height = tallness;
		leftchild = left;
		rightchild = right;
	}
	~Node();

	int data;
	int height;
	Node* leftchild;
	Node* rightchild;

private:

	int getData();
	Node* getLeftChild();
	Node* getRightChild();
	int getHeight();
	void setHeight(int value);
	void updateHeight();
	int getBalance();

};















AVL();
~AVL();

NodeInterface* getRootNode();
Node* balance(Node* node);
Node* IOP(Node* curr, Node* rNode);

Node* add_helper(Node* curr, int value);
Node* remove_helper(Node* curr, int x);
bool contains_helper(Node* curr, int value);

void RR(Node* a, Node* b);
void RL(Node* a, Node* b, Node* c);
void LL(Node* a, Node* b);
void LR(Node* a, Node* b, Node* c);

bool contains(int value);
bool add(int data);
bool remove(int data);
void clear();

int size();


Node* AVL::recAdd(Node* c, int x){
	// recursive method
	// doesn't deal with root

	// returns what the parent of c should point to afterward

	////cout << "\nStarting recAdd()..." << endl;

	if (c == NULL){
		////cout << "\nrecAdd() added " << x << " to the tree" << endl;
		return new Node(x);
	}

	else if (x < c->data){
		c->left = recAdd(c->left, x);

		return balance(c);
	}

	else if (x > c->data){
		c->right = recAdd(c->right, x);
		return balance(c);
	}
}











#include "Node.h"


Node::Node(int, int, Node* , Node*) {
	this->data = data;
	this->height = height;
	this->leftchild = leftchild;
	this->rightchild = rightchild;
}


Node::~Node(){}


 Return the data that is stored in this node.
int Node::getData()
{
	return data;
}



 Returns the left child of this node or null if it doesn't have one.
Node* Node::getLeftChild()
{
	return leftchild;
}


 Returns the right child of this node or null if it doesn't have one.
Node* Node::getRightChild()
{
	return rightchild;
}

int Node::getHeight()
{
	return height;
}


void Node::setHeight(int value)
{
	this->height = value;
}

void Node::updateHeight() {
	int LH;
	if (leftchild == NULL)LH = -1;
	else LH = leftchild->height;

	int RH;
	if (rightchild == NULL) RH = -1;
	else RH = rightchild->height;

	height = max(LH, RH) + 1;
}


int Node::getBalance() {
	int LH = (leftchild == NULL) ? -1 : leftchild->height;
	int RH = (rightchild == NULL) ? -1 : rightchild->height;

	return RH - LH;
}




















