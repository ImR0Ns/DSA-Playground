#pragma once
#include <iostream>

/* example of runs
UDGraph t(2, true);
t.addVertices();
t.addEdge(1, 2);
t.addEdge(1, 0);
t.addEdge(2, 0);

// Print the updated adjacency matrix
for (int i = 0; i < t.vertices; ++i) {
	for (int j = 0; j < t.vertices; ++j) {
		std::cout << t.aMatrix[i][j] << " ";
	}
	std::cout << std::endl;
}
*/


//This model is made with Adjacency Matrix;

struct UDGraph {
	int vertices;
	int edges;
	int** aMatrix;
	bool isDirected;

	/*
		Ex for 3:

		   A  B  C
		A [0, 0, 0]
		B [0, 0, 0]
		C [0, 0, 0]

		Row means the edges of that graph
		Col means the edge to that
	*/

	UDGraph(int v, bool isDirected) : vertices(v), edges(0), isDirected(isDirected) {
		//init first array
		aMatrix = new int* [v];
		for (int i = 0; i < v; i++) {
			//init second arrays for every position
			aMatrix[i] = new int[v];
			//populate with 0
			for (int j = 0; j < v; j++) {
				aMatrix[i][j] = 0;
			}
		}
	}

	void addVertices();

	void removeVertices();

	/* the index of array [[ ], [ ], [ ]] is the vertices
							0    1    2
		so when we want an edge to 0 to 2
		   0  1  2
		0 [0, 0, 1]
		1 [0, 0, 0]
		2 [1, 0, 0]
		*/

	void addEdge(int start, int finish);

	void removeEdge(int start, int finish);

	void getInfo();

	~UDGraph() {
		//free memory
		for (int i = 0; i < vertices; ++i) {
			delete[] aMatrix[i];
		}
		delete[] aMatrix;
	}

};