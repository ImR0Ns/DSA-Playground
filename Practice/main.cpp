#include <iostream>
#include <vector>
#include "LinkedList.h"

// Undirected-Directed Graph with Adjacency List.
struct UDGraphAL {
	int vertices;
	int edges;
	LinkedList** adjacencyList;
	bool isDirected;

	/*
		The index of array are the vertices and the LinkedList edges;
	*/
	UDGraphAL(int vertices, bool isD) : vertices(vertices), isDirected(isD) {
		adjacencyList = new LinkedList*[vertices]; //creates a list of Objects without values, data = null, next = nullptr
		for (int i = 0; i < vertices; i++) {

			adjacencyList[i] = nullptr;
		}
	}

	void addVertices() {
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

	void removeVertices() {
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

	~UDGraphAL() {
		for (int i = 0; i < vertices; ++i) {
			delete adjacencyList[i];
		}
		delete[] adjacencyList;
	}
};

int main() {
	UDGraphAL graph(3, false);
	graph.addVertices();

	for (int i = 0; i < graph.vertices; i++) {
		std::cout << graph.adjacencyList[i] << std::endl;
	}

	std::cout << "Hello" << std::endl;
}
