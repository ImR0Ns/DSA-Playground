#include "UDGraph.h"

void UDGraph::addVertices() {
	vertices++;

	// Allocate memory for the new row
	int** newMatrix = new int* [vertices];
	for (int i = 0; i < vertices; i++) {
		newMatrix[i] = new int[vertices];
		// Populate with 0
		for (int j = 0; j < vertices; j++) {
			newMatrix[i][j] = 0;
		}
	}

	// Copy the existing matrix to the new matrix
	for (int i = 0; i < vertices - 1; i++) {
		for (int j = 0; j < vertices - 1; j++) {
			newMatrix[i][j] = aMatrix[i][j];
		}
	}

	// Free the memory of the old matrix
	for (int i = 0; i < vertices - 1; i++) {
		delete[] aMatrix[i];
	}
	delete[] aMatrix;

	// Update the matrix pointer
	aMatrix = newMatrix;
}

void UDGraph::removeVertices() {
	vertices--;

	int** newMatrix = new int* [vertices];
	for (int i = 0; i < vertices; i++) {
		newMatrix[i] = new int[vertices];
		for (int j = 0; j < vertices; j++) {
			newMatrix[i][j] = 0;
		}
	}

	// Copy the existing matrix to the new matrix
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			newMatrix[i][j] = aMatrix[i][j];
		}
	}

	// Free the memory of the old matrix
	for (int i = 0; i < vertices; i++) {
		delete[] aMatrix[i];
	}
	delete[] aMatrix;

	// Update the matrix pointer
	aMatrix = newMatrix;
}

/* the index of array [[ ], [ ], [ ]] is the vertices
						0    1    2
	so when we want an edge to 0 to 2
	   0  1  2
	0 [0, 0, 1]
	1 [0, 0, 0]
	2 [1, 0, 0]
	*/
void UDGraph::addEdge(int start, int finish) {
	//set edges
	edges++;
	if (isDirected) {
		aMatrix[start][finish] = 1;
	}
	else {
		aMatrix[start][finish] = 1;
		aMatrix[finish][start] = 1;
	}
}

void UDGraph::removeEdge(int start, int finish) {
	//remove edges
	edges--;
	if (isDirected) {
		aMatrix[start][finish] = 0;
	}
	else {
		aMatrix[start][finish] = 0;
		aMatrix[finish][start] = 0;
	}
}

void UDGraph::getInfo() {
	std::cout << "Total vertices: " << vertices << "\nTotal edges: " << edges;
}