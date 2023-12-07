#include  <iostream>
#include <vector>
#include <algorithm>
#include "LinkedList.h"
#include "BinaryTree.h"


//I want to create a separate function for BTS Insert And Search to avoid repeating!

//Binary Search Tree
struct BTS {
	int data;
	BTS* left;
	BTS* right;

	BTS(int data) : data(data), left(nullptr), right(nullptr) {}

	void insertElement(BTS* n) {

		bool foundPosition = false;
		BTS* currentPosition = this;

		while (!foundPosition) {
			if (n->data > currentPosition->data) {
				if (currentPosition->right == nullptr) {
					currentPosition->right = n;
					foundPosition = true;
				}
				else {
					currentPosition = currentPosition->right;
				}
			}
			else if(n->data < currentPosition->data) {
				if (currentPosition->left == nullptr) {
					currentPosition->left = n;
					foundPosition = true;
				}
				else {
					currentPosition = currentPosition->left;
				}
			}
		}
	}

	void searchElement(int data) {
		if (this->data == data) {
			std::cout << "Is the root\n";
		}

		bool foundData = false;
		BTS* currentPosition = this;
		int depth = 0;

		while (!foundData) {
			if (currentPosition->data == data) {
				std::cout << "Value Found at depth of " << depth << "\n";
				foundData = true;
			}

			if (data > currentPosition->data) {
				if (currentPosition->right == nullptr) {
					std::cout << "Value not found!\n";
					foundData = true;
				}
				else {
					currentPosition = currentPosition->right;
				}
			}
			else if (data < currentPosition->data) {
				if (currentPosition->left == nullptr) {
					std::cout << "Value not found!\n";
					foundData = true;
				}
				else {
					currentPosition = currentPosition->left;
				}
			}
			depth++;
		}
	}

};

int main() {
	BTS* node = new BTS(8);
	node->insertElement(new BTS(3));
	node->insertElement(new BTS(1));
	node->insertElement(new BTS(6));
	node->insertElement(new BTS(4));
	node->insertElement(new BTS(7));
	node->insertElement(new BTS(10));
	node->insertElement(new BTS(14));
	node->insertElement(new BTS(13));

	node->searchElement(15);

	std::cout << node;
}
