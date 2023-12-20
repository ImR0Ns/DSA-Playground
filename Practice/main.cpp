#include <iostream>
#include <vector>
#include "UDGraph.h"

int main() {
    // Create a large undirected graph with 1000 nodes
    UDGraph largeGraph(1000, false);

    // Test adding edges
    for (int i = 0; i < 1000; ++i) {
        largeGraph.addEdge(i, (i + 1) % 1000); // Connect each node to the next one
    }

    // Test adding and deleting nodes
    for (int i = 0; i < 100; ++i) {
        largeGraph.addNodes(); // Add 100 nodes
    }

    for (int i = 0; i < 50; ++i) {
        largeGraph.deleteNodes(); // Delete 50 nodes
    }

    // Print a subset of the adjacency matrix
    std::cout << "Subset of the adjacency matrix:\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << largeGraph.arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
