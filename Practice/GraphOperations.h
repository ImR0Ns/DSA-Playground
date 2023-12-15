#pragma once
#include <iostream>
#include <vector>
#include "UDGraph.h"

/* Example of run
* 
std::vector<bool> v(t.vertices, false);
dfs(0, v, t);

*/
void dfs(int start, std::vector<bool>& visited, const UDGraph& graph);
