#pragma once

#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{

public:

	BST();
	~BST();

	NodeInterface* getRootNode();

	bool add(int data);
	bool remove(int data);
	void clear();


private:

	Node* root;

	bool add_helper(int data, Node* &current);
	bool remove_helper(int data, Node* &current);
	void clear_helper(Node* &root);

	bool predecessor(Node* &n1, Node* &n2);
	bool find(int value, Node* n);


};
