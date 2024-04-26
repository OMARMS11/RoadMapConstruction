
#include "graph.h"
#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

Edge::Edge(string vertex1, string vertex2, double length) 
{
	this->vertex1 = vertex1;
	this->vertex2 = vertex2;
	this->length = length;
}
Edge::Edge() 
{
	this->vertex1 = "";
	this->vertex2 = "";
	this->length = 0;
}
bool Edge::	operator < (Edge e) 
{
	return length < e.length;
}
bool Edge::operator == (Edge e) 
{
	return length == e.length;
}

string Edge::getVertex1() 
{
	return vertex1;
}
string Edge::getVertex2()
{
	return vertex2;
}


void Graph::PrimMinimumSpanningTree()
{
	///
	/// kjljl
	/// lklk
	/// 
	/// klklk
	///
	vector <string> visitedVerticies;
	queue<Edge> edgesOrder;
	vector<Edge> unusedAdjacentEdges;

	adjacencyList.insert(make_pair("a", list<Edge>()));

	adjacencyList.insert(make_pair("b", list<Edge>()));

	adjacencyList.insert(make_pair("c", list<Edge>()));

	adjacencyList.insert(make_pair("d", list<Edge>()));

	adjacencyList.insert(make_pair("e", list<Edge>()));

	adjacencyList.insert(make_pair("f", list<Edge>()));

	string x;
	string y;
	double len;

	x = "a";
	y = "b";
	len = 4;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));
	
	x = "a";
	y = "c";
	len = 4;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));

	x = "b";
	y = "c";
	len = 2;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));
	
	x = "d";
	y = "c";
	len = 3;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));
	
	x = "f";
	y = "c";
	len = 4;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));

	x = "e";
	y = "c";
	len = 2;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));

	x = "e";
	y = "f";
	len = 3;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));
	
	x = "d";
	y = "f";
	len = 3;
	adjacencyList[x].push_back(Edge(x, y, len));
	adjacencyList[y].push_back(Edge(x, y, len));

	auto currentNode = adjacencyList.begin()->first;
	visitedVerticies.push_back(currentNode);

	while (visitedVerticies.size() < adjacencyList.size())
	{

		list<Edge> currentAdjacentEdges = adjacencyList[currentNode];

		for (auto i = currentAdjacentEdges.begin(); i != currentAdjacentEdges.end(); i++)
		{
			unusedAdjacentEdges.push_back(*i);
		}

		sort(unusedAdjacentEdges.begin(), unusedAdjacentEdges.end());
		bool makeCycle = true;

		while (makeCycle)
		{

			Edge currentEdge = unusedAdjacentEdges[0];

			bool foundVertex1 = count(visitedVerticies.begin(), visitedVerticies.end(), currentEdge.getVertex1()) != 0;
			bool foundVertex2 = count(visitedVerticies.begin(), visitedVerticies.end(), currentEdge.getVertex2()) != 0;

			if ((foundVertex1) ^ (foundVertex2))
			{
				edgesOrder.push(currentEdge);
				if (!foundVertex1)
				{
					currentNode = currentEdge.getVertex1();
				}
				else
				{
					currentNode = currentEdge.getVertex2();
				}
				visitedVerticies.push_back(currentNode);
				makeCycle = false;
			}
			else
			{
				unusedAdjacentEdges.erase(unusedAdjacentEdges.begin());
			}
		}
	}

	int size = edgesOrder.size();

	for (int i = 0; i < size; i++)
	{
		cout << edgesOrder.front().getVertex1() << " " << edgesOrder.front().getVertex2() <<
			" " << edgesOrder.front().length << endl;
		edgesOrder.pop();
	}
}
void Graph::BFStraversal()
{

}