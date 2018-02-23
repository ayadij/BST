#include "Node.h"


Node::Node(int data)
{
	leftchild = NULL;
	rightchild = NULL;
	this->data = data;
}

Node::~Node(){}


/* Return the data that is stored in this node. */
int Node::getData()
{
	return data;
}



/* Returns the left child of this node or null if it doesn't have one. */
Node* Node::getLeftChild()
{
	return leftchild;
}


/* Returns the right child of this node or null if it doesn't have one. */
Node* Node::getRightChild()
{
	return rightchild;
}


