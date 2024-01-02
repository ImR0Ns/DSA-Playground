#include "GraphOperations.h"


void dfs(int start, std::vector<bool>& visited, const UDGraph& graph) {
	std::cout << start << " ";

	// Set current node as visited
	visited[start] = true;

	for (int i = 0; i < graph.vertices; i++) {
		if (graph.aMatrix[start][i] == 1 && (!visited[i])) {
			dfs(i, visited, graph);
		}

	}
}
