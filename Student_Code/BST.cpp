#include "BST.h"


BST::BST()
{
	root = NULL;
}


BST::~BST()
{
	delete root;
	clear();
}



/* Returns the root node for this tree
 * @return the root node for this tree. */
NodeInterface* BST::getRootNode()
{
	return root;
}



/* Attempts to add the given int to the BST tree
 * @return true if added
 * @return false if unsuccessful (i.e. the int is already in tree). */
bool BST::add(int data)
{
	// If the value is unique, add it
	if(!find(data, root))
		return add_helper(data, root);

	// Don't add duplicates
	else return false;
}


/* Attempts to remove the given int from the BST tree
 * @return true if successfully removed
 * @return false if remove is unsuccessful(i.e. the int is not in the tree). */
bool BST::remove(int data)
{
	// If the value exists, remove it
	if(find(data, root))
		return remove_helper(data, root);

	else return false;
}


/* Removes all nodes from the tree, resulting in an empty tree. */
void BST::clear()
{
	// Empty the tree unless it is already empty
	if(root != NULL)
		clear_helper(root);
}




bool BST::add_helper(int data, Node* &current) {
	// Once you get to the bottom of the tree, add the node
	if(current == NULL) {
		current = new Node(data);
		return true;
	} else {
		// If you aren't at the bottom of the tree, keep moving through.
		if(data > current->data)
			return add_helper(data, current->rightchild);
		else
		if(data < current->data)
			return add_helper(data, current->leftchild);
	}
	return false;
}


bool BST::remove_helper(int data, Node* &current) {
	// Once you've arrived to the correct node, delete the node
	if(data == current->data) {
		// Current node has no children
		if(current->rightchild == NULL && current->leftchild == NULL) {
			delete current;
			current = NULL;
			return true;
		}
		// Current node has one child
		else if((current->rightchild == NULL && current->leftchild != NULL) || // One left child
			    (current->leftchild == NULL && current->rightchild != NULL)) { // One right child
			Node * temp = current;
			// Move the existing child node up
			if(current->leftchild == NULL)
				current = current->rightchild;
			else
			if(current->rightchild == NULL)
				current = current->leftchild;

			delete temp;
			temp = NULL;
			return true;
		}
		// Two children
		else if(current->rightchild != NULL && current->leftchild != NULL) {
			// Find the inorder predecessor and put it where the deleted node is.
			return predecessor(current, current->leftchild);
		}
	} else {
		// If you aren't at the correct node or at the bottom of the tree, keep moving through.
		if(data > current->data)
			return remove_helper(data, current->rightchild);
		else
		if(data < current->data)
			return remove_helper(data, current->leftchild);
	}
	return false;
}


void BST::clear_helper(Node* &node) {
	// Move left if you can
	if(node->leftchild != NULL)
		clear_helper(node->leftchild);

	// Move right if you can
	if(node->rightchild != NULL)
		clear_helper(node->rightchild);

	// Once all the children of the node are deleted from above calls, delete the node
	delete node;
	node = NULL;
}




/* Deletes, swaps, rotates, etc all nodes nodes from the tree. */
bool BST::predecessor(Node* &n1, Node* &n2) {
	// As soon as right == NULL, the predecessor has been found.
	if(n2->rightchild == NULL) {
		n1->data = n2->data;
		Node* temp = n2;
		n2 = n2->leftchild;
		delete temp;
		temp = NULL;
		return true;
	} else {
		predecessor(n1, n2->rightchild);
	}
	return false;
}


/* Recursively looks for a node with a certain value. */
bool BST::find(int value, Node* n) {
	if(n == NULL)
		return false;

	else if(value > n->data)
		return find(value, n->rightchild);

	else if(value < n->data)
		return find(value, n->leftchild);

	else if(n->data == value)
		return true;

	return false;
}



