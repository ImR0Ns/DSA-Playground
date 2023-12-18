#include <iostream>
#include <vector>
#include "UDGraphAL.h"

int main() {
	UDGraphAL graph(3, true);
	graph.addVertices();

	graph.addEdge(1, 0);

	graph.addEdge(1, 2);
	graph.addEdge(2, 0);

	//graph.removeEdge(0, 1);

	std::cout << "\n" << std::endl;

	for (int i = 0; i < 4; i++) {
		if (graph.adjacencyList[i] != nullptr) {
			graph.adjacencyList[i]->printList();
			std::cout << "\n" << std::endl;
		}
	}


	std::cout << "Hello" << std::endl;
}
