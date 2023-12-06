#include  <iostream>
#include "LinkedList.h";

int main() {
	//init node
	LinkedList* node = new LinkedList(1); // new LinkedList(1) | ilustrate the prepend
	//apend to values at the end
	node->append(new LinkedList(2));
	node->append(new LinkedList(3));
	//set new node
	node->prepend(new LinkedList(0)); // new LinkedList(0) | ilustrate the prepend

	//delete node at position 3
	node->deleteNode(3);

	//add node at specific position
	node->insertingNode(new LinkedList(4), 3);

	//search for node
	node->searchForNode(4);

	//print list
	node->printList();

	std::cout << "Node data ";
}
