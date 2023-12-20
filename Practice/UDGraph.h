#pragma once
#include <iostream>
#include <vector>

//This model is made with Adjacency Matrix;

struct UDGraph {
	int nodes;
	int edges;
	bool isDirected;
	std::vector<std::vector<int>> arr = {};

	/*
		Ex for 3:

		   A  B  C
		A [0, 0, 0]
		B [0, 0, 0]
		C [0, 0, 0]

		Row means the edges of that graph
		Col means the edge to that
	*/

	UDGraph(int nodes, bool isDirected) : nodes(nodes), edges(0), isDirected(isDirected) {

		if (nodes <= 1) {
			std::cout << "You need to insert more than one node!\n";
			nodes = 2;
		}

		for (int i = 0; i < nodes; i++) {
			std::vector<int> toAdd;
			for (int j = 0; j < nodes; j++) {
				toAdd.push_back(0);
			}
			arr.push_back(toAdd);
		}


	}

	void addNodes();

	void deleteNodes();

	void addEdge(int fromOne, int toFinal);

    void removeEdge(int fromOne, int toFinal);
};