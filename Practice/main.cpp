#include <iostream>
#include <vector>
#include "UDGraph.h"
#include "GraphOperations.h"


int main() {
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

	std::vector<bool> v(t.vertices, false);

	//dfs(0, v, t);
}
