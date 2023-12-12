#pragma once
#include  <iostream>
#include <vector>

struct BinaryTree {
	int data;
	BinaryTree* right;
	BinaryTree* left;

	explicit BinaryTree(int data) : data(data), right(nullptr), left(nullptr) {}

	/*
		Insertion, check if node value we want to insert is greater or less than the node we are.
		if greater move to right
		if less move to left
		Do this until we find a free node(nullptr)
	*/
	void insertNode(BinaryTree* node);

	//print the entire tree
	void printTree(bool forSearch = false, int whatToSearch = 0);

	//search value
	void search(int val);

	int height(BinaryTree* root);

	//help function for delete node.
	BinaryTree* findMin(BinaryTree* node);

	BinaryTree* deleteNode(BinaryTree* root, int key);
	
	//free the memory in heap;
	void deleteTree();
};

/*
	INPUT EXAMPLE FOR RUN

	BinaryTree* root = new BinaryTree(5);

	root->insertNode(new BinaryTree(3));
	root->insertNode(new BinaryTree(8));
	root->insertNode(new BinaryTree(2));
	root->insertNode(new BinaryTree(4));
	root->insertNode(new BinaryTree(6));
	root->insertNode(new BinaryTree(9));

	int keyToDelete = 3;
	root = root->deleteNode(root, keyToDelete);


	root->printTree();

	root->deleteTree(); //using the same strategy to print the tree
*/