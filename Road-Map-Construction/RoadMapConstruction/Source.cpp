#include <iostream>
#include "graph.h"
using namespace std;
int main() {
	Graph g;
	cout << "PMST\n";
g.PrimMinimumSpanningTree();
	cout << "BFS\n";
	g.BFStraversal();
	cout << "DFST\n";
	g.DFStraversal();
}