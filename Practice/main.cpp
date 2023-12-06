#include  <iostream>
#include <vector>
#include <algorithm>
#include "LinkedList.h";


struct BinaryTree {
	int data;
	BinaryTree* right;
	BinaryTree* left;

	BinaryTree(int data) : data(data), right(nullptr), left(nullptr) {}

	/*
		Insertion, check if node value we want to insert is greater or less than the node we are.
		if greater move to right
		if less move to left
		Do this until we find a free node(nullptr)
	*/
	void insertNode(BinaryTree* node) {
		BinaryTree* currentPosition = this;
		bool positionFound = false;
		while (!positionFound) {
			if (node->data > currentPosition->data) {
				if (currentPosition->right == nullptr) {
					currentPosition->right = node;
					positionFound = true;
				}
				else {
					currentPosition = currentPosition->right;
				}
			} else {
				if (currentPosition->left == nullptr) {
					currentPosition->left = node;
					positionFound = true;
				}else {
					currentPosition = currentPosition->left;
				}
			}
		}
	}

	//print the entire tree
	void printTree(bool forSearch = false, int whatToSearch = 0) {
		std::vector<BinaryTree*> remain = { this };
		while (remain.size() != 0) {
			BinaryTree* last = remain[remain.size() - 1];
			remain.pop_back();
			if (forSearch && last->data == whatToSearch) {
				std::cout << "Found: " << last->data << "\n";
				break;
			}
			if (!forSearch) {
				std::cout << last->data << ",";
			}
			if (last->right) {
				remain.push_back(last->right);
			}
			if (last->left) {
				remain.push_back(last->left);
			}
		}

	}

	//search value
	void search(int val) {
		printTree(true, val);
	}

	static int height(BinaryTree* root) {
		if (root == nullptr) {
			return -1;
		}
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);

		return std::max(leftHeight, rightHeight) + 1;
	}

};

int main() {

	BinaryTree* root = new BinaryTree(5);

	root->insertNode(new BinaryTree(3));
	root->insertNode(new BinaryTree(8));
	root->insertNode(new BinaryTree(2));
	root->insertNode(new BinaryTree(4));
	root->insertNode(new BinaryTree(6));
	root->insertNode(new BinaryTree(9));

	std::cout << BinaryTree::height(root);


}
