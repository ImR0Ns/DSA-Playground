#include "LinkedList.h";

//deleting and inserting starts from index 1
void LinkedList::append(LinkedList* next) {

	LinkedList* currentPosition = this;

	while (currentPosition->next) {
		currentPosition = currentPosition->next;
	}

	currentPosition->next = next;

}
void LinkedList::prepend(LinkedList* replaceNode) { //gets a new memory adress

	//I save the values from node and the node to be prepended;
	LinkedList nodeValue = *this;
	LinkedList newNodeValue = *replaceNode;

	//I replace the values from node memory adress with replaceNode
	*this = newNodeValue; // current node = new node values
	*replaceNode = nodeValue; //new node values = current node

	this->next = replaceNode;

}
void LinkedList::insertingNode(LinkedList* nodeToInsert, int position) {
	LinkedList* currentPosition = this;
	int counter = 1;
	while (counter < position - 1) {
		currentPosition = currentPosition->next;
		counter++;
	}
	LinkedList* saveNext = currentPosition->next;
	currentPosition->next = nodeToInsert;
	nodeToInsert->next = saveNext;
}

void LinkedList::deleteNode(int position) { //you can't delete the head;
	LinkedList* currentPosition = this;
	int counter = 1;
	while (counter < position - 1) {
		currentPosition = currentPosition->next;
		counter++;
	}

	LinkedList* nodeToDelete = currentPosition->next;

	currentPosition->next = nodeToDelete->next;

	delete nodeToDelete; //free memory
}
LinkedList* LinkedList::searchForNode(int value) {
	LinkedList* currentPosition = this;
	int position = 1;
	while (currentPosition->next) {
		if (currentPosition->data == value) {
			std::cout << "Found at position " << position << "\n";
			return currentPosition;
		}
		currentPosition = currentPosition->next;
		position++;
	}
	std::cout << "Not found!\n";
}
void LinkedList::printList() {

	LinkedList* currentPosition = this;
	while (currentPosition) {
		std::cout << currentPosition->data << "\n";
		currentPosition = currentPosition->next;
	}

}