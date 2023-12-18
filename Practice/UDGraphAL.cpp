#include "UDGraphAL.h"

void UDGraphAL::addVertices() {
	// Add vertices
	vertices++;

	// Create a new array with vertices + 1
	LinkedList** newAdjacencyList = new LinkedList * [vertices];

	//last position filled make it nullptr
	newAdjacencyList[vertices - 1] = nullptr;


	// Copy old values to the new array
	for (int j = 0; j < vertices - 1; j++) {
		newAdjacencyList[j] = adjacencyList[j];
	}


	//delete the pointer
	for (int i = 0; i < vertices - 1; ++i) {
		delete adjacencyList[i];
	}

	// Delete old array to free space
	delete[] adjacencyList;

	// Update the adjacency list pointer
	adjacencyList = newAdjacencyList;
}

void UDGraphAL::removeVertices() {
	vertices--;
	// Create a new array with vertices - 1
	LinkedList** newAdjacencyList = new LinkedList * [vertices];
	for (int j = 0; j < vertices; j++) {
		newAdjacencyList[j] = adjacencyList[j];
	}
	// Delete old array to free space
	delete[] adjacencyList;

	// Update the adjacency list pointer
	adjacencyList = newAdjacencyList;
}

void UDGraphAL::addEdge(int start, int finalPos) {
	if (isDirected) {
		//if nullptr create linkedlist and add value
		if (adjacencyList[start] == nullptr) {
			adjacencyList[start] = new LinkedList(finalPos);
		}
		else {
			adjacencyList[start]->append(new LinkedList(finalPos));
		}
	}
	else {
		//if nullptr create linkedlist and add value
		if (adjacencyList[start] == nullptr) {
			adjacencyList[start] = new LinkedList(finalPos);
		}
		else {
			adjacencyList[start]->append(new LinkedList(finalPos));
		}


		if (adjacencyList[finalPos] == nullptr) {
			adjacencyList[finalPos] = new LinkedList(start);
		}
		else {
			adjacencyList[finalPos]->append(new LinkedList(start));
		}
	}
}

void UDGraphAL::removeEdge(int start, int finalPos) {
	if (isDirected) {
		adjacencyList[start]->deleteFromList(finalPos, adjacencyList[start]);
	}
	else {
		adjacencyList[start]->deleteFromList(finalPos, adjacencyList[start]);
		adjacencyList[finalPos]->deleteFromList(start, adjacencyList[finalPos]);
	}
}