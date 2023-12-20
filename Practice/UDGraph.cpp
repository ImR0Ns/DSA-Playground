#include "UDGraph.h"

void UDGraph::addNodes() {
    //add new node with NxN
    nodes++;
    std::vector<int> toAdd;
    for (int i = 0; i < nodes; i++) {
        toAdd.push_back(0);
    }
    arr.push_back(toAdd);

    //update rest of arrays
    for (int j = 0; j < nodes - 1; j++) {
        arr[j].push_back(0);
    }

}

void UDGraph::deleteNodes() {
    //substract nodes 
    nodes--;
    arr.pop_back();
    //update NxN array
    for (int i = 0; i < nodes; i++) {
        arr[i].pop_back();
    }

}

void UDGraph::addEdge(int fromOne, int toFinal) {
    if (isDirected) {
        arr[fromOne][toFinal] = 1;
    }
    else {
        arr[fromOne][toFinal] = 1;
        arr[toFinal][fromOne] = 1;
    }
}

void UDGraph::removeEdge(int fromOne, int toFinal) {
    if (isDirected) {
        arr[fromOne][toFinal] = 0;
    }
    else {
        arr[fromOne][toFinal] = 0;
        arr[toFinal][fromOne] = 0;
    }
}