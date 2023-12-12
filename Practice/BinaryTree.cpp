#include "BinaryTree.h"

//On Header we have input examples

/*
		Insertion, check if node value we want to insert is greater or less than the node we are.
		if greater move to right
		if less move to left
		Do this until we find a free node(nullptr)
*/

void BinaryTree::insertNode(BinaryTree* node) {
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
		}
		else {
			if (currentPosition->left == nullptr) {
				currentPosition->left = node;
				positionFound = true;
			}
			else {
				currentPosition = currentPosition->left;
			}
		}
	}
}

//print the entire tree
void BinaryTree::printTree(bool forSearch, int whatToSearch) {

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
void BinaryTree::search(int val) {
	printTree(true, val); // we using the method of printing 
}

int BinaryTree::height(BinaryTree* root) {
	if (root == nullptr) {
		return -1;
	}
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);

	return std::max(leftHeight, rightHeight) + 1;
}

//help function for delete node.
BinaryTree* BinaryTree::findMin(BinaryTree* node) {
	while (node->left != nullptr) {
		node = node->left;
	}
	return node;
}

BinaryTree* BinaryTree::deleteNode(BinaryTree* root, int key) {
	if (root == nullptr) {
		return root;
	}

	if (key < root->data) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->data) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if (root->left == nullptr) {
			BinaryTree* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr) {
			BinaryTree* temp = root->left;
			delete root;
			return temp;
		}

		BinaryTree* temp = findMin(root->right);

		root->data = temp->data;

		root->right = deleteNode(root->right, temp->data);
	}

	return root;
}

//we need to clear the memory from heap, so we using the method of printing to delete every address of memory 
void BinaryTree::deleteTree() {

	std::vector<BinaryTree*> remain = { this };

	while (remain.size() != 0) {

		BinaryTree* last = remain[remain.size() - 1];
		remain.pop_back();

		if (last->right) {
			remain.push_back(last->right);
		}
		if (last->left) {
			remain.push_back(last->left);
		}

		//delete memory
		delete last;
	}

}