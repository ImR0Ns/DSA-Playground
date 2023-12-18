#pragma once
#include "LinkedList.h"

struct UDGraphAL {
	int vertices;
	int edges;
	LinkedList** adjacencyList;
	bool isDirected;

	/*
		The index of array are the vertices and the LinkedList edges;
	*/

	UDGraphAL(int vertices, bool isD) : vertices(vertices), isDirected(isD) {
		adjacencyList = new LinkedList * [vertices]; //creates a list of Objects without values, data = null, next = nullptr
		for (int i = 0; i < vertices; i++) {

			adjacencyList[i] = nullptr;
		}
	}

	void addVertices();
	void removeVertices();
	void addEdge(int start, int finalPos);
	void removeEdge(int start, int finalPos);

	~UDGraphAL() {
		for (int i = 0; i < vertices; ++i) {
			delete adjacencyList[i];
		}
		delete[] adjacencyList;
	}
};